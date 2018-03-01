// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <gtest/gtest.h>
#include <transaction/add_salaried_employee.h>
#include <transaction/add_hourly_employee.h>
#include <transaction/add_commissioned_employee.h>
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
using payroll_domain::Employee;
using payroll_domain::SalariedClassification;
using payroll_domain::HourlyClassification;
using payroll_domain::CommissionedClassification;
using payroll_domain::MonthlySchedule;
using payroll_domain::WeeklySchedule;
using payroll_domain::BiweeklySchedule;
using payroll_database::PayrollDatabase;

class TestPayroll : public ::testing::Test {
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
  const Employee expect {kEmployeeId, "Martin", "Home"};
  AddCommissionedEmployee t {kEmployeeId, "Martin", "Home", 1000.00, 10.00};
  t.Execute();
  Employee e {PayrollDatabase::GetEmployee(kEmployeeId)};
  EXPECT_EQ(expect, e);
}
}  // namespace add_salaried_employee_test
