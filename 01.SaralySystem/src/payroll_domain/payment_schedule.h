// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_PAYROLL_DOMAIN_PAYMENT_SCHEDULE_H_
#define SALARYSYSTEM_PAYROLL_DOMAIN_PAYMENT_SCHEDULE_H_

#include <boost/date_time/gregorian/gregorian.hpp>

namespace payroll_domain {
class PaymentSchedule;
using UPtrPaySchedule = std::unique_ptr<PaymentSchedule>;

class PaymentSchedule {
 public:
    PaymentSchedule() = default;
    PaymentSchedule(const PaymentSchedule&) = default;
    PaymentSchedule& operator=(const PaymentSchedule&) = default;
    virtual ~PaymentSchedule() = default;

    virtual bool IsPayDate(gr::date pay_date) const = 0;
};
}  // namespace payroll_domain

#endif  // SALARYSYSTEM_PAYROLL_DOMAIN_PAYMENT_SCHEDULE_H_
