// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_PAYROLL_DOMAIN_SALARIED_CLASSIFICATION_H_
#define SALARYSYSTEM_PAYROLL_DOMAIN_SALARIED_CLASSIFICATION_H_

#include <payroll_domain/payment_classification.h>

namespace payroll_domain {

class SalariedClassification: public PaymentClassification {
 public:
    explicit SalariedClassification(double salary = 0.0)
      :PaymentClassification{}, salary_ {salary} {}
    SalariedClassification(const SalariedClassification&) = default;
    SalariedClassification& operator=(const SalariedClassification&) = default;
    ~SalariedClassification() override = default;

    double GetSalary() const {return salary_;}

 private:
    double salary_;
};

}  // namespace payroll_domain

#endif  // SALARYSYSTEM_PAYROLL_DOMAIN_SALARIED_CLASSIFICATION_H_
