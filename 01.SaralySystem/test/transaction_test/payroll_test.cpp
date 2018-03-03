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
using transaction::ChangeHourlyTransaction;
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
  constexpr int kEmployeeId = 2;
  const Employee expect {kEmployeeId, "Martin", "Home"};
  AddHourlyEmployee t {kEmployeeId, "Martin", "Home", 10.00};
  t.Execute();
  auto e = PayrollDatabase::GetEmployee(kEmployeeId);
  EXPECT_EQ(expect, *e);
  auto hc = dynamic_cast<const HourlyClassification*>(e->GetClassification());
  EXPECT_NE(nullptr, hc);
  EXPECT_DOUBLE_EQ(10.00, hc->GetHourlyRate());
  auto ws = dynamic_cast<const WeeklySchedule*>(e->GetSchedule());
  EXPECT_NE(nullptr, ws);
}

TEST_F(TestPayroll, TestAddCommissionedEmployee) {
  constexpr int kEmployeeId = 3;
  const Employee expect {kEmployeeId, "Robert", "Home"};
  AddCommissionedEmployee t {kEmployeeId, "Robert", "Home", 1000.00, 10.00};
  t.Execute();
  auto e = PayrollDatabase::GetEmployee(kEmployeeId);
  EXPECT_EQ(expect, *e);
  auto cc = dynamic_cast<const CommissionedClassification*>(e->GetClassification());
  EXPECT_NE(nullptr, cc);
  EXPECT_DOUBLE_EQ(1000.00, cc->GetSalary());
  EXPECT_DOUBLE_EQ(10.00, cc->GetCommissionRate());
  auto bws = dynamic_cast<const BiweeklySchedule*>(e->GetSchedule());
  EXPECT_NE(nullptr, bws);
}

TEST_F(TestPayroll, TestDeleteEmployee) {
  constexpr int kEmployeeId = 3;
  const Employee expect {kEmployeeId, "Lance", "Home"};
  AddCommissionedEmployee t{kEmployeeId, "Lance", "Home", 2500, 3.2};
  t.Execute();
  auto e = PayrollDatabase::GetEmployee(kEmployeeId);
  EXPECT_EQ(expect, *e);

  DeleteEmployee dt{kEmployeeId};
  dt.Execute();
  EXPECT_EQ(nullptr, PayrollDatabase::GetEmployee(kEmployeeId));
}

TEST_F(TestPayroll, TestTimeCardTransaction) {
  constexpr int kEmployeeId = 2;
  AddHourlyEmployee t{kEmployeeId, "Bill", "Home", 15.25};
  t.Execute();
  TimeCardTransaction tct{20180303, 8.0, kEmployeeId};
  tct.Execute();
  auto e = PayrollDatabase::GetEmployee(kEmployeeId);
  auto pc = e->GetClassification();
  auto hc = dynamic_cast<HourlyClassification*>(pc);
  EXPECT_NE(nullptr, hc);
  auto tc = hc->GetTimeCard(20180303);
  EXPECT_DOUBLE_EQ(8.0, tc.hours);
}

TEST_F(TestPayroll, TestSalesReceiptTransaction) {
  constexpr int kEmployeeId = 3;
  AddCommissionedEmployee t{kEmployeeId, "Lance", "Home", 2500, 3.2};
  t.Execute();
  SalesReceiptTransaction srt{20180303, 100, kEmployeeId};
  srt.Execute();
  auto e = PayrollDatabase::GetEmployee(kEmployeeId);
  auto pc = e->GetClassification();
  auto sc = dynamic_cast<CommissionedClassification*>(pc);
  EXPECT_NE(nullptr, sc);
  auto sr = sc->GetSalesReceipt(20180303);
  EXPECT_DOUBLE_EQ(100, sr.amount);
}

TEST_F(TestPayroll, TestAddServiceCharge) {
  constexpr int32_t kEmployeeId = 2;
  AddHourlyEmployee t{kEmployeeId, "Bill", "Home", 15.25};
  t.Execute();
  auto e = PayrollDatabase::GetEmployee(kEmployeeId);
  e->SetAffiliation(std::unique_ptr<Affiliation>{new UnionAffiliation{12.5}});
  constexpr int32_t kMemberId = 86;
  PayrollDatabase::AddUnionMember(kMemberId, e);
  ServiceChargeTransaction sct{kMemberId, 20180303, 12.95};
  sct.Execute();
  EXPECT_EQ(12.95, e->GetAffiliation().ServiceCharge(20180303));
}

TEST_F(TestPayroll, TestChangeNameTransaction) {
  constexpr int32_t kEmpId = 2;
  AddHourlyEmployee t{kEmpId, "Bill", "Home", 15.25};
  t.Execute();

  Employee expect{kEmpId, "Bob", "Home"};
  ChangeNameTransaction cnt{kEmpId, "Bob"};
  cnt.Execute();
  auto e = PayrollDatabase::GetEmployee(kEmpId);
  EXPECT_EQ(expect, *e);
}

TEST_F(TestPayroll, TestChangeAddressTransaction) {
  constexpr int32_t kEmpId = 2;
  AddHourlyEmployee t{kEmpId, "Bill", "Home", 15.25};
  t.Execute();

  Employee expect{kEmpId, "Bill", "New Home"};
  ChangeAddressTransaction cat{kEmpId, "New Home"};
  cat.Execute();
  auto e = PayrollDatabase::GetEmployee(kEmpId);
  EXPECT_EQ(expect, *e);
}

TEST_F(TestPayroll, TestChangeClassification) {
  constexpr int32_t kEmpId = 3;
  AddCommissionedEmployee t{kEmpId, "Lance", "Home", 2500, 3.2};
  t.Execute();

  ChangeHourlyTransaction cht{kEmpId, 27.52};
  cht.Execute();
  auto e = PayrollDatabase::GetEmployee(kEmpId);
  auto hc = dynamic_cast<const HourlyClassification*>(e->GetClassification());
  EXPECT_NE(nullptr, hc);
  EXPECT_DOUBLE_EQ(27.52, hc->GetHourlyRate());
  auto ws = dynamic_cast<const WeeklySchedule*>(e->GetSchedule());
  EXPECT_NE(nullptr, ws);
}
}  // namespace add_salaried_employee_test
