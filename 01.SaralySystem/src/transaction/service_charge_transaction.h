// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_TRANSACTION_SERVICE_CHARGE_TRANSACTION_H_
#define SALARYSYSTEM_TRANSACTION_SERVICE_CHARGE_TRANSACTION_H_

#include <cstdint>
#include <transaction/transaction.h>
#include <payroll_domain/affiliation.h>

namespace transaction {
using payroll_domain::Affiliation;

class ServiceChargeTransaction: public Transaction {
 public:
    ServiceChargeTransaction(int32_t member_id, int64_t date, double charge)
        : member_id_{member_id}, date_{date}, charge_{charge} {}
    ~ServiceChargeTransaction() override = default;

    void Execute() override;

 private:
    const int32_t member_id_;
    const int64_t date_;
    const double charge_;
};
}  // namespace transaction

#endif  // SALARYSYSTEM_TRANSACTION_SERVICE_CHARGE_TRANSACTION_H_
