// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_TRANSACTION_SALES_RECEIPT_TRANSACTION_H_
#define SALARYSYSTEM_TRANSACTION_SALES_RECEIPT_TRANSACTION_H_

#include <cstdint>
#include <transaction/transaction.h>
#include <payroll_domain/sales_receipt.h>

namespace transaction {
using payroll_domain::SalesReceipt;

class SalesReceiptTransaction: public Transaction {
 public:
    SalesReceiptTransaction(int64_t date, double amount, int32_t id)
        : date_{date}, amount_{amount}, employee_id_{id} {}
    ~SalesReceiptTransaction() override = default;

    void Execute() override;

 private:
    const int64_t date_;
    const double amount_;
    const int32_t employee_id_;
};
}  // namespace transaction

#endif  // SALARYSYSTEM_TRANSACTION_SALES_RECEIPT_TRANSACTION_H_
