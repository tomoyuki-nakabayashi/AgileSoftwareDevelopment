// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_PAYROLL_DOMAIN_MONTHLY_SCHEDULE_H_
#define SALARYSYSTEM_PAYROLL_DOMAIN_MONTHLY_SCHEDULE_H_

#include <payroll_domain/payment_schedule.h>

namespace payroll_domain {

class MonthlySchedule: public PaymentSchedule {
 public:
    MonthlySchedule() = default;
    MonthlySchedule(const MonthlySchedule&) = default;
    MonthlySchedule& operator=(const MonthlySchedule&) = default;
    ~MonthlySchedule() override = default;

    std::unique_ptr<PaymentSchedule> clone() const override {
      return std::unique_ptr<PaymentSchedule>(new MonthlySchedule{*this});
    }
};
}  // namespace payroll_domain

#endif  // SALARYSYSTEM_PAYROLL_DOMAIN_MONTHLY_SCHEDULE_H_
