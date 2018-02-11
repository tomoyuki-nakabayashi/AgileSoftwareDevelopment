// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <gtest/gtest.h>

namespace add_employee_transaction_test {
class TestPayroll : public ::testing::Test {
};

TEST_F(TestPayroll, TestAddSalariedEmployee) {
  int employee_id = 1;
  AddSalariedEmployee t {employee_id, "Bob", "Home", 1000.00};
  t.Execute();
  Employee e {PayrollDatabase.GetEmployee(employee_id)};
  EXPECT_EQ("Bob", e.GetName());
}
}  // namespace add_salaried_employee_test