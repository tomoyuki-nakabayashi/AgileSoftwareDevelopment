// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <gtest/gtest.h>
#include <payroll_domain/employee.h>

namespace payroll_domain_test {
using payroll_domain::Employee;

class EmployeeTest : public ::testing::Test {
};

TEST_F(EmployeeTest, FirstTest) {
  EXPECT_TRUE(true);
}

}  // namespace payroll_domain_test
