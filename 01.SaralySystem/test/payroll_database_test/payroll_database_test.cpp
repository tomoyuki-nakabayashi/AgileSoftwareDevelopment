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
  PayrollDatabase db {};
  Employee expect {1, "Bob", "Home"};
  db.AddEmployee(1, &expect);

  const Employee *actual = db.GetEmployee(1);
  EXPECT_EQ(expect, *actual);
}

} //  namespace add_employee_transaction_test