// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <gtest/gtest.h>

namespace add_employee_transaction_test {
class TestPayrollDatabase : public ::testing::Test {
};

TEST_F(TestPayrollDatabase, AddEmployee) {
  PayrollDatabase db {};
  Employee expect {};
  db.AddEmployee(expect);

  Employee actual = db.GetEmployee(id);
  EXPECT_EQ(expect, actual);
}

} //  namespace add_employee_transaction_test