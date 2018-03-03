// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <gtest/gtest.h>
#include <payroll_domain/employee.h>
#include <payroll_domain/salaried_classification.h>

namespace payroll_domain_test {
using payroll_domain::Employee;
using payroll_domain::PaymentClassification;
using payroll_domain::SalariedClassification;

class EmployeeTest : public ::testing::Test {
};

TEST_F(EmployeeTest, FirstTest) {
  Employee e1 {1, "Bob", "Home"};
  Employee e2 {1, "Bob", "Home"};
  Employee e3 {2, "Robert", "Lab"};

  EXPECT_EQ(e1, e2);
  EXPECT_NE(e1, e3);
}

TEST_F(EmployeeTest, CanRetreaveClassification) {
  Employee e1 {1, "Bob", "Home"};
  e1.SetClassification(std::unique_ptr<PaymentClassification>(new SalariedClassification{100.0}));
  auto c = e1.GetClassification();

  EXPECT_NE(nullptr, dynamic_cast<const SalariedClassification*>(c));
}
/* 
TEST_F(EmployeeTest, CanRetreaveClassificationAfterCopy) {
  Employee e1 {1, "Bob", "Home"};
  e1.SetClassification(std::unique_ptr<PaymentClassification>(new SalariedClassification{100.0}));
  Employee e2 {e1};
  auto c = e2.GetClassification();

  EXPECT_NE(nullptr, dynamic_cast<const SalariedClassification*>(c));
}
 */
}  // namespace payroll_domain_test
