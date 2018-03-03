// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_TRANSACTION_TIME_CARD_TRANSACTION_H_
#define SALARYSYSTEM_TRANSACTION_TIME_CARD_TRANSACTION_H_

#include <cstdint>
#include <transaction/transaction.h>
#include <payroll_domain/time_card.h>

namespace transaction {
using payroll_domain::TimeCard;

class TimeCardTransaction: public Transaction {
 public:
    TimeCardTransaction(int64_t date, double hours, int32_t id)
        : date_{date}, hours_{hours}, employee_id_{id} {}
    ~TimeCardTransaction() override = default;

    void Execute() override;

 private:
    const int64_t date_;
    const double hours_;
    const int32_t employee_id_;
};
}  // namespace transaction

#endif  // SALARYSYSTEM_TRANSACTION_TIME_CARD_TRANSACTION_H_
