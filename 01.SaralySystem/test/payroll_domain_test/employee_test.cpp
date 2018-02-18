// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <gtest/gtest.h>
#include <payroll_domain/employee.h>

namespace payroll_domain_test {
using payroll_domain::Employee;

class EmployeeTest : public ::testing::Test {
};

TEST_F(EmployeeTest, FirstTest) {
  Employee e1 {1, "Bob", "Home"};
  Employee e2 {1, "Bob", "Home"};
  Employee e3 {2, "Robert", "Lab"};

  EXPECT_EQ(e1, e2);
  EXPECT_NE(e1, e3);
}

}  // namespace payroll_domain_test
