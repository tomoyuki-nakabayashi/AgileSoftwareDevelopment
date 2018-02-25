// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_PAYROLL_DOMAIN_SALARIED_CLASSIFICATION_H_
#define SARALYSYSTEM_PAYROLL_DOMAIN_SALARIED_CLASSIFICATION_H_

#include <payroll_domain/payment_classification.h>

namespace payroll_domain {

class SalariedClassification: public PaymentClassification {
 public:
    explicit SalariedClassification(double saraly = 0.0)
      :PaymentClassification{}, saraly_ {saraly} {}
    SalariedClassification(const SalariedClassification&) = default;
    SalariedClassification& operator=(const SalariedClassification&) = default;
    ~SalariedClassification() override = default;

 private:
    double saraly_;
};

}  // namespace payroll_domain

#endif  // SARALYSYSTEM_PAYROLL_DOMAIN_SALARIED_CLASSIFICATION_H_
