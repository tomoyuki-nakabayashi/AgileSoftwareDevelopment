// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_PAYROLL_DOMAIN_PAYMENT_CLASSIFICATION_H_
#define SARALYSYSTEM_PAYROLL_DOMAIN_PAYMENT_CLASSIFICATION_H_

#include <memory>

namespace payroll_domain {
class PaymentClassification;
using UPtrPayClass = std::unique_ptr<PaymentClassification>;

class PaymentClassification {
 public:
    PaymentClassification() = default;
    PaymentClassification(const PaymentClassification&) = default;
    PaymentClassification& operator=(const PaymentClassification&) = default;
    virtual ~PaymentClassification() = default;

    virtual UPtrPayClass clone() const {
      return std::make_unique<PaymentClassification>(*this);
    }
};

}  // namespace payroll_domain

#endif  // SARALYSYSTEM_PAYROLL_DOMAIN_PAYMENT_CLASSIFICATION_H_
