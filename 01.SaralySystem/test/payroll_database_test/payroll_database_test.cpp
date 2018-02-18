// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <gtest/gtest.h>
#include <payroll_domain/employee.h>
#include <payroll_database/payroll_database.h>

namespace payroll_database_test {
using payroll_database::PayrollDatabase;
using payroll_domain::Employee;

class PayrollDatabaseTest : public ::testing::Test {
};

TEST_F(PayrollDatabaseTest, AddEmployee) {
  Employee expect {1, "Bob", "Home"};
  PayrollDatabase::AddEmployee(1, expect);

  Employee actual = PayrollDatabase::GetEmployee(1);
  EXPECT_EQ(expect, actual);
}

} //  namespace add_employee_transaction_test