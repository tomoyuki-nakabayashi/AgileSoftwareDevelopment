// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_PAYROLL_DOMAIN_PAYMENT_CLASSIFICATION_H_
#define SARALYSYSTEM_PAYROLL_DOMAIN_PAYMENT_CLASSIFICATION_H_

namespace payroll_domain {

class PaymentClassification {
 public:
    PaymentClassification() = default;
    PaymentClassification(const PaymentClassification&) = default;
    PaymentClassification& operator=(const PaymentClassification&) = default;
    virtual ~PaymentClassification() = default;

    virtual PaymentClassification* clone() const {
      return new PaymentClassification{*this};
    }
};

}  // namespace payroll_domain

#endif  // SARALYSYSTEM_PAYROLL_DOMAIN_PAYMENT_CLASSIFICATION_H_
