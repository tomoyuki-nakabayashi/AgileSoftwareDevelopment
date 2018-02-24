// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_PAYROLL_DOMAIN_PAYMENT_SCHEDULE_H_
#define SARALYSYSTEM_PAYROLL_DOMAIN_PAYMENT_SCHEDULE_H_

namespace payroll_domain {

class PayrollSchedule {
 public:
    PayrollSchedule() = default;
    PayrollSchedule(const PayrollSchedule&) = default;
    PayrollSchedule& operator=(const PayrollSchedule&) = default;
    virtual ~PayrollSchedule() = default;
};
}  // namespace payroll_domain

#endif  // SARALYSYSTEM_PAYROLL_DOMAIN_PAYMENT_SCHEDULE_H_
