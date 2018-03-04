// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <cstdint>
#include <gtest/gtest.h>
#include <transaction/add_salaried_employee.h>
#include <transaction/add_hourly_employee.h>
#include <transaction/add_commissioned_employee.h>
#include <transaction/delete_employee.h>
#include <transaction/time_card_transaction.h>
#include <transaction/sales_receipt_transaction.h>
#include <transaction/service_charge_transaction.h>
#include <transaction/change_employee_transaction.h>
#include <transaction/change_basic_information.h>
#include <transaction/change_classification.h>
#include <transaction/change_affiliation.h>
#include <payroll_domain/employee.h>
#include <payroll_domain/salaried_classification.h>
#include <payroll_domain/hourly_classification.h>
#include <payroll_domain/commissioned_classification.h>
#include <payroll_domain/monthly_schedule.h>
#include <payroll_domain/weekly_schedule.h>
#include <payroll_domain/biweekly_schedule.h>
#include <payroll_domain/affiliation.h>
#include <payroll_domain/union_affiliation.h>
#include <payroll_domain/time_card.h>
#include <payroll_domain/sales_receipt.h>
#include <payroll_database/payroll_database.h>

namespace add_employee_transaction_test {
using transaction::AddSalariedEmployee;
using transaction::AddHourlyEmployee;
using transaction::AddCommissionedEmployee;
using transaction::DeleteEmployee;
using transaction::TimeCardTransaction;
using transaction::SalesReceiptTransaction;
using transaction::ServiceChargeTransaction;
using transaction::ChangeNameTransaction;
using transaction::ChangeAddressTransaction;
using transaction::ChangeSalariedTransaction;
using transaction::ChangeHourlyTransaction;
using transaction::ChangeCommissionedTransaction;
using transaction::ChangeMemberTransaction;
using payroll_domain::Employee;
using payroll_domain::SalariedClassification;
using payroll_domain::HourlyClassification;
using payroll_domain::CommissionedClassification;
using payroll_domain::MonthlySchedule;
using payroll_domain::WeeklySchedule;
using payroll_domain::BiweeklySchedule;
using payroll_domain::Affiliation;
using payroll_domain::UnionAffiliation;
using payroll_domain::TimeCard;
using payroll_domain::SalesReceipt;
using payroll_domain::UPtrPayClass;
using payroll_database::PayrollDatabase;

class TestPayroll : public ::testing::Test {
 protected:
    void TearDown() override {
      PayrollDatabase::Clear();
    }
};

constexpr int32_t kHeId = 2;
const Employee kHourlyEmp{kHeId, "Bill", "Home"};
AddHourlyEmployee ahe{kHeId, "Bill", "Home", 15.25};

constexpr int32_t kCeId = 3;
const Employee kCoEmp{kCeId, "Lance", "Home"};
AddCommissionedEmployee ace{kCeId, "Lance", "Home", 2500, 3.2};

TEST_F(TestPayroll, TestAddSalariedEmployee) {
  constexpr int kEmployeeId = 1;
  const Employee expect {kEmployeeId, "Bob", "Home"};
  AddSalariedEmployee t {kEmployeeId, "Bob", "Home", 1000.00};
  t.Execute();
  auto e = PayrollDatabase::GetEmployee(kEmployeeId);
  EXPECT_EQ(expect, *e);
  auto sc = dynamic_cast<const SalariedClassification*>(e->GetClassification());
  EXPECT_NE(nullptr, sc);
  EXPECT_DOUBLE_EQ(1000.00, sc->GetSalary());
  auto ms = dynamic_cast<const MonthlySchedule*>(e->GetSchedule());
  EXPECT_NE(nullptr, ms);
}

TEST_F(TestPayroll, TestAddHourlyEmployee) {
  ahe.Execute();
  auto e = PayrollDatabase::GetEmployee(kHeId);
  EXPECT_EQ(kHourlyEmp, *e);
  auto hc = dynamic_cast<const HourlyClassification*>(e->GetClassification());
  EXPECT_NE(nullptr, hc);
  EXPECT_DOUBLE_EQ(15.25, hc->GetHourlyRate());
  auto ws = dynamic_cast<const WeeklySchedule*>(e->GetSchedule());
  EXPECT_NE(nullptr, ws);
}

TEST_F(TestPayroll, TestAddCommissionedEmployee) {
  ace.Execute();
  auto e = PayrollDatabase::GetEmployee(kCeId);
  EXPECT_EQ(kCoEmp, *e);
  auto cc = dynamic_cast<const CommissionedClassification*>(e->GetClassification());
  EXPECT_NE(nullptr, cc);
  EXPECT_DOUBLE_EQ(2500, cc->GetSalary());
  EXPECT_DOUBLE_EQ(3.2, cc->GetCommissionRate());
  auto bws = dynamic_cast<const BiweeklySchedule*>(e->GetSchedule());
  EXPECT_NE(nullptr, bws);
}

TEST_F(TestPayroll, TestDeleteEmployee) {
  ace.Execute();
  auto e = PayrollDatabase::GetEmployee(kCeId);
  EXPECT_EQ(kCoEmp, *e);

  DeleteEmployee dt{kCeId};
  dt.Execute();
  EXPECT_EQ(nullptr, PayrollDatabase::GetEmployee(kCeId));
}

TEST_F(TestPayroll, TestTimeCardTransaction) {
  ahe.Execute();
  TimeCardTransaction tct{20180303, 8.0, kHeId};
  tct.Execute();
  auto e = PayrollDatabase::GetEmployee(kHeId);
  auto pc = e->GetClassification();
  auto hc = dynamic_cast<HourlyClassification*>(pc);
  EXPECT_NE(nullptr, hc);
  auto tc = hc->GetTimeCard(20180303);
  EXPECT_DOUBLE_EQ(8.0, tc.hours);
}

TEST_F(TestPayroll, TestSalesReceiptTransaction) {
  ace.Execute();
  SalesReceiptTransaction srt{20180303, 100, kCeId};
  srt.Execute();
  auto e = PayrollDatabase::GetEmployee(kCeId);
  auto pc = e->GetClassification();
  auto sc = dynamic_cast<CommissionedClassification*>(pc);
  EXPECT_NE(nullptr, sc);
  auto sr = sc->GetSalesReceipt(20180303);
  EXPECT_DOUBLE_EQ(100, sr.amount);
}

TEST_F(TestPayroll, TestAddServiceCharge) {
  ahe.Execute();
  auto e = PayrollDatabase::GetEmployee(kHeId);
  e->SetAffiliation(std::unique_ptr<Affiliation>{new UnionAffiliation{12.5}});
  constexpr int32_t kMemberId = 86;
  PayrollDatabase::AddUnionMember(kMemberId, e);
  ServiceChargeTransaction sct{kMemberId, 20180303, 12.95};
  sct.Execute();
  EXPECT_EQ(12.95, e->GetAffiliation().ServiceCharge(20180303));
}

TEST_F(TestPayroll, TestChangeNameTransaction) {
  ahe.Execute();

  Employee expect{kHeId, "Bob", "Home"};
  ChangeNameTransaction cnt{kHeId, "Bob"};
  cnt.Execute();
  auto e = PayrollDatabase::GetEmployee(kHeId);
  EXPECT_EQ(expect, *e);
}

TEST_F(TestPayroll, TestChangeAddressTransaction) {
  ahe.Execute();

  Employee expect{kHeId, "Bill", "New Home"};
  ChangeAddressTransaction cat{kHeId, "New Home"};
  cat.Execute();
  auto e = PayrollDatabase::GetEmployee(kHeId);
  EXPECT_EQ(expect, *e);
}

TEST_F(TestPayroll, TestChangeHourlyTransaction) {
  ace.Execute();

  ChangeHourlyTransaction cht{kCeId, 27.52};
  cht.Execute();
  auto e = PayrollDatabase::GetEmployee(kCeId);
  auto hc = dynamic_cast<const HourlyClassification*>(e->GetClassification());
  EXPECT_NE(nullptr, hc);
  EXPECT_DOUBLE_EQ(27.52, hc->GetHourlyRate());
  auto ws = dynamic_cast<const WeeklySchedule*>(e->GetSchedule());
  EXPECT_NE(nullptr, ws);
}

TEST_F(TestPayroll, TestChangeSalariedTransaction) {
  ace.Execute();

  ChangeSalariedTransaction cht{kCeId, 2500};
  cht.Execute();
  auto e = PayrollDatabase::GetEmployee(kCeId);
  auto sc = dynamic_cast<const SalariedClassification*>(e->GetClassification());
  EXPECT_NE(nullptr, sc);
  EXPECT_DOUBLE_EQ(2500, sc->GetSalary());
  auto ms = dynamic_cast<const MonthlySchedule*>(e->GetSchedule());
  EXPECT_NE(nullptr, ms);
}

TEST_F(TestPayroll, TestChangeCommissionedTransaction) {
  ahe.Execute();

  ChangeCommissionedTransaction cht{kHeId, 2500, 3.2};
  cht.Execute();
  auto e = PayrollDatabase::GetEmployee(kHeId);
  auto cc = dynamic_cast<const CommissionedClassification*>(e->GetClassification());
  EXPECT_NE(nullptr, cc);
  EXPECT_DOUBLE_EQ(2500, cc->GetSalary());
  auto bs = dynamic_cast<const BiweeklySchedule*>(e->GetSchedule());
  EXPECT_NE(nullptr, bs);
}

TEST_F(TestPayroll, TestChangeMemberTransaction) {
  ahe.Execute();
  constexpr int kMemberId = 7734;
  ChangeMemberTransaction cmt{kHeId, kMemberId, 99.42};
  cmt.Execute();
  auto e = PayrollDatabase::GetEmployee(kHeId);
  auto uf = dynamic_cast<const UnionAffiliation*>(&e->GetAffiliation());
  ASSERT_NE(nullptr, uf);
  EXPECT_EQ(99.42, uf->Dues());
  auto member = PayrollDatabase::GetUnionMember(kMemberId);
  ASSERT_NE(nullptr, member);
  EXPECT_EQ(*e, *member);
}
}  // namespace add_salaried_employee_test
