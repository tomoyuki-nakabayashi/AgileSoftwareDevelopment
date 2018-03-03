// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_TRANSACTION_TRANSACTION_H_
#define SALARYSYSTEM_TRANSACTION_TRANSACTION_H_

namespace transaction {

class Transaction {
 public:
    Transaction() = default;
    Transaction(const Transaction& other) = delete;
    Transaction& operator=(const Transaction& other) = delete;
    virtual ~Transaction() = default;
    virtual void Execute() = 0;
};
}  // namespace transaction

#endif  // SALARYSYSTEM_TRANSACTION_TRANSACTION_H_
