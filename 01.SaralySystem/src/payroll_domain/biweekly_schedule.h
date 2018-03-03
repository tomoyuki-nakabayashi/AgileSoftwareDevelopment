// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_PAYROLL_DOMAIN_BIWEEKLY_SCHEDULE_H_
#define SALARYSYSTEM_PAYROLL_DOMAIN_BIWEEKLY_SCHEDULE_H_

#include <payroll_domain/payment_schedule.h>

namespace payroll_domain {
using payroll_domain::UPtrPaySchedule;
class BiweeklySchedule: public PaymentSchedule {
 public:
    BiweeklySchedule() = default;
    BiweeklySchedule(const BiweeklySchedule&) = default;
    BiweeklySchedule& operator=(const BiweeklySchedule&) = default;
    ~BiweeklySchedule() override = default;
};
}  // namespace payroll_domain

#endif  // SALARYSYSTEM_PAYROLL_DOMAIN_BIWEEKLY_SCHEDULE_H_
