// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_PAYROLL_DOMAIN_PAYMENT_SCHEDULE_H_
#define SALARYSYSTEM_PAYROLL_DOMAIN_PAYMENT_SCHEDULE_H_

namespace payroll_domain {
class PaymentSchedule;
using UPtrPaySchedule = std::unique_ptr<PaymentSchedule>;

class PaymentSchedule {
 public:
    PaymentSchedule() = default;
    PaymentSchedule(const PaymentSchedule&) = default;
    PaymentSchedule& operator=(const PaymentSchedule&) = default;
    virtual ~PaymentSchedule() = default;
};
}  // namespace payroll_domain

#endif  // SALARYSYSTEM_PAYROLL_DOMAIN_PAYMENT_SCHEDULE_H_
