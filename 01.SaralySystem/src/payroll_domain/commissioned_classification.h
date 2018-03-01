// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_PAYROLL_DOMAIN_COMMISSIONED_CLASSIFICATION_H_
#define SARALYSYSTEM_PAYROLL_DOMAIN_COMMISSIONED_CLASSIFICATION_H_

#include <payroll_domain/payment_classification.h>

namespace payroll_domain {
using payroll_domain::UPtrPayClass;
class CommissionedClassification: public PaymentClassification {
 public:
    explicit CommissionedClassification(double salary = 0.0,
                                        double commission_rate = 0.0)
      :PaymentClassification{}
      , salary_ {salary}
      , commission_rate_ {commission_rate} {}
    CommissionedClassification(const CommissionedClassification&) = default;
    CommissionedClassification& operator=(const CommissionedClassification&)
      = default;
    ~CommissionedClassification() override = default;

    UPtrPayClass clone() const override {
      return UPtrPayClass(new CommissionedClassification{*this});
    }
    double GetSalary() const { return salary_; }
    double GetCommissionRate() const { return commission_rate_; }

 private:
    double salary_;
    double commission_rate_;
};

}  // namespace payroll_domain

#endif  // SARALYSYSTEM_PAYROLL_DOMAIN_COMMISSIONED_CLASSIFICATION_H_
