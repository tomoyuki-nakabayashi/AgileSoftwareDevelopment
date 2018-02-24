// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_PAYROLL_DOMAIN_PAYMENT_SCHEDULE_H_
#define SARALYSYSTEM_PAYROLL_DOMAIN_PAYMENT_SCHEDULE_H_

namespace payroll_domain {

class PaymentSchedule {
 public:
    PaymentSchedule() = default;
    PaymentSchedule(const PaymentSchedule&) = default;
    PaymentSchedule& operator=(const PaymentSchedule&) = default;
    virtual ~PaymentSchedule() = default;
};
}  // namespace payroll_domain

#endif  // SARALYSYSTEM_PAYROLL_DOMAIN_PAYMENT_SCHEDULE_H_
