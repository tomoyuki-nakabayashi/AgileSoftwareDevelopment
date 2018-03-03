// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_PAYROLL_DOMAIN_HOURLY_CLASSIFICATION_H_
#define SALARYSYSTEM_PAYROLL_DOMAIN_HOURLY_CLASSIFICATION_H_

#include <cstdint>
#include <map>
#include <payroll_domain/payment_classification.h>
#include <payroll_domain/time_card.h>

namespace payroll_domain {

class HourlyClassification: public PaymentClassification {
 public:
    explicit HourlyClassification(double hourly_rate = 0.0)
      :PaymentClassification{}
      , hourly_rate_{hourly_rate}
      , time_cards_{} {}
    HourlyClassification(const HourlyClassification&) = default;
    HourlyClassification& operator=(const HourlyClassification&) = default;
    ~HourlyClassification() override = default;

    double GetHourlyRate() const {return hourly_rate_;}
    void AddTimeCard(const TimeCard& tc) { 
      time_cards_.insert(std::make_pair(tc.date, TimeCard{tc})); 
    }
    TimeCard GetTimeCard(int64_t date) { return time_cards_[date]; }

 private:
    double hourly_rate_;
    std::map<int64_t, TimeCard> time_cards_;
};

}  // namespace payroll_domain

#endif  // SALARYSYSTEM_PAYROLL_DOMAIN_HOURLY_CLASSIFICATION_H_
