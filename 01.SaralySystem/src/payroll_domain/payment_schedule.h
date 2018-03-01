// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_PAYROLL_DOMAIN_PAYMENT_SCHEDULE_H_
#define SARALYSYSTEM_PAYROLL_DOMAIN_PAYMENT_SCHEDULE_H_

namespace payroll_domain {
class PaymentSchedule;
using UPtrPaySchedule = std::unique_ptr<PaymentSchedule>;

class PaymentSchedule {
 public:
    PaymentSchedule() = default;
    PaymentSchedule(const PaymentSchedule&) = default;
    PaymentSchedule& operator=(const PaymentSchedule&) = default;
    virtual ~PaymentSchedule() = default;

    virtual UPtrPaySchedule clone() const {
      return std::make_unique<PaymentSchedule>(*this);
    }
};
}  // namespace payroll_domain

#endif  // SARALYSYSTEM_PAYROLL_DOMAIN_PAYMENT_SCHEDULE_H_
