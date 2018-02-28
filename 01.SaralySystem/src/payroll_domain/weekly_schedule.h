// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_PAYROLL_DOMAIN_WEEKLY_SCHEDULE_H_
#define SARALYSYSTEM_PAYROLL_DOMAIN_WEEKLY_SCHEDULE_H_

#include <payroll_domain/payment_schedule.h>

namespace payroll_domain {

class WeeklySchedule: public PaymentSchedule {
 public:
    WeeklySchedule() = default;
    WeeklySchedule(const WeeklySchedule&) = default;
    WeeklySchedule& operator=(const WeeklySchedule&) = default;
    ~WeeklySchedule() override = default;

    std::unique_ptr<PaymentSchedule> clone() const override {
      return std::unique_ptr<PaymentSchedule>(new WeeklySchedule{*this});
    }
};
}  // namespace payroll_domain

#endif  // SARALYSYSTEM_PAYROLL_DOMAIN_WEEKLY_SCHEDULE_H_
