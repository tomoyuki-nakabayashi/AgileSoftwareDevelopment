// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <gtest/gtest.h>
#include <transaction/add_salaried_employee.h>
#include <transaction/add_hourly_employee.h>
#include <transaction/add_commissioned_employee.h>
#include <transaction/delete_employee.h>
#include <payroll_domain/employee.h>
#include <payroll_domain/salaried_classification.h>
#include <payroll_domain/hourly_classification.h>
#include <payroll_domain/commissioned_classification.h>
#include <payroll_domain/monthly_schedule.h>
#include <payroll_domain/weekly_schedule.h>
#include <payroll_domain/biweekly_schedule.h>
#include <payroll_database/payroll_database.h>

namespace add_employee_transaction_test {
using transaction::AddSalariedEmployee;
using transaction::AddHourlyEmployee;
using transaction::AddCommissionedEmployee;
using transaction::DeleteEmployee;
using payroll_domain::Employee;
using payroll_domain::SalariedClassification;
using payroll_domain::HourlyClassification;
using payroll_domain::CommissionedClassification;
using payroll_domain::MonthlySchedule;
using payroll_domain::WeeklySchedule;
using payroll_domain::BiweeklySchedule;
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
  Employee e {PayrollDatabase::GetEmployee(kEmployeeId)};
  EXPECT_EQ(expect, e);
  auto sc = dynamic_cast<const SalariedClassification*>(e.GetClassification());
  EXPECT_NE(nullptr, sc);
  EXPECT_DOUBLE_EQ(1000.00, sc->GetSalary());
  auto ms = dynamic_cast<const MonthlySchedule*>(e.GetSchedule());
  EXPECT_NE(nullptr, ms);
}

TEST_F(TestPayroll, TestAddHourlyEmployee) {
  constexpr int kEmployeeId = 2;
  const Employee expect {kEmployeeId, "Martin", "Home"};
  AddHourlyEmployee t {kEmployeeId, "Martin", "Home", 10.00};
  t.Execute();
  Employee e {PayrollDatabase::GetEmployee(kEmployeeId)};
  EXPECT_EQ(expect, e);
  auto hc = dynamic_cast<const HourlyClassification*>(e.GetClassification());
  EXPECT_NE(nullptr, hc);
  EXPECT_DOUBLE_EQ(10.00, hc->GetHourlyRate());
  auto ws = dynamic_cast<const WeeklySchedule*>(e.GetSchedule());
  EXPECT_NE(nullptr, ws);
}

TEST_F(TestPayroll, TestAddCommissionedEmployee) {
  constexpr int kEmployeeId = 3;
  const Employee expect {kEmployeeId, "Robert", "Home"};
  AddCommissionedEmployee t {kEmployeeId, "Robert", "Home", 1000.00, 10.00};
  t.Execute();
  Employee e {PayrollDatabase::GetEmployee(kEmployeeId)};
  EXPECT_EQ(expect, e);
  auto cc = dynamic_cast<const CommissionedClassification*>(e.GetClassification());
  EXPECT_NE(nullptr, cc);
  EXPECT_DOUBLE_EQ(1000.00, cc->GetSalary());
  EXPECT_DOUBLE_EQ(10.00, cc->GetCommissionRate());
  auto bws = dynamic_cast<const BiweeklySchedule*>(e.GetSchedule());
  EXPECT_NE(nullptr, bws);
}

TEST_F(TestPayroll, TestDeleteEmployee) {
  constexpr int kEmployeeId = 3;
  const Employee expect {kEmployeeId, "Lance", "Home"};
  AddCommissionedEmployee t{kEmployeeId, "Lance", "Home", 2500, 3.2};
  t.Execute();
  Employee e{PayrollDatabase::GetEmployee(kEmployeeId)};
  EXPECT_EQ(expect, e);

  DeleteEmployee dt{kEmployeeId};
  dt.Execute();
  EXPECT_THROW(PayrollDatabase::GetEmployee(kEmployeeId), std::out_of_range);
}

TEST_F(TestPayroll, TestTimeCardTransaction) {
  constexpr int kEmployeeId = 2;
  AddHourlyEmployee t{kEmployeeId, "Bill", "Home", 15.25};
  t.Execute();
  TimeCardTransaction tct{20180303, 8.0, kEmployeeId};
  tct.Execute();
  Employee e{PayrollDatabase::GetEmployee(kEmployeeId)};
  auto pc = e.GetClassification();
  EXPECT_EQ(typeid(HourlyClassification), typeid(pc));
  TimeCard tc = dynamic_cast<const HourlyClassification*>(pc)->GetTimeCard(20180303);
  EXPECT_EQ(8.0, tc.GetHours());
}
}  // namespace add_salaried_employee_test
