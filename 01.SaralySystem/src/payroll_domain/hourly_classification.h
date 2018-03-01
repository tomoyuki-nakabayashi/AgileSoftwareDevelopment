// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_PAYROLL_DOMAIN_HOURLY_CLASSIFICATION_H_
#define SARALYSYSTEM_PAYROLL_DOMAIN_HOURLY_CLASSIFICATION_H_

#include <payroll_domain/payment_classification.h>

namespace payroll_domain {

class HourlyClassification: public PaymentClassification {
 public:
    explicit HourlyClassification(double hourly_rate = 0.0)
      :PaymentClassification{}, hourly_rate_ {hourly_rate} {}
    HourlyClassification(const HourlyClassification&) = default;
    HourlyClassification& operator=(const HourlyClassification&) = default;
    ~HourlyClassification() override = default;

    std::unique_ptr<PaymentClassification> clone() const override {
      return std::unique_ptr<PaymentClassification>(new HourlyClassification{*this});
    }
    double GetHourlyRate() const {return hourly_rate_;}

 private:
    double hourly_rate_;
};

}  // namespace payroll_domain

#endif  // SARALYSYSTEM_PAYROLL_DOMAIN_HOURLY_CLASSIFICATION_H_
