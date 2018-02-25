// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <gtest/gtest.h>
#include<typeinfo>
#include <transaction/add_salaried_employee.h>
#include <payroll_domain/employee.h>
#include <payroll_domain/salaried_classification.h>
#include <payroll_database/payroll_database.h>

namespace add_employee_transaction_test {
using transaction::AddSalariedEmployee;
using payroll_domain::Employee;
using payroll_domain::SalariedClassification;
using payroll_database::PayrollDatabase;

class TestPayroll : public ::testing::Test {
};

TEST_F(TestPayroll, TestAddSalariedEmployee) {
  constexpr int kEmployeeId = 1;
  Employee expect {kEmployeeId, "Bob", "Home"};
  AddSalariedEmployee t {kEmployeeId, "Bob", "Home", 1000.00};
  t.Execute();
  Employee e {PayrollDatabase::GetEmployee(kEmployeeId)};
  EXPECT_EQ(expect, e);
  auto c = e.GetClassification();
  EXPECT_NE(nullptr, dynamic_cast<const SalariedClassification*>(c));
}
}  // namespace add_salaried_employee_test
