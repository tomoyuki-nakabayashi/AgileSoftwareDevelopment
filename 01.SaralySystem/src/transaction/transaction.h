// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_TRANSACTION_TRANSACTION_H_
#define SARALYSYSTEM_TRANSACTION_TRANSACTION_H_

namespace transaction {

class Transaction {
 public:
    Transaction() = default;
    Transaction(const Transaction& other) = default;
    Transaction& operator=(const Transaction& other) = default;
    virtual ~Transaction() = default;
    virtual void Execute() = 0;
};
}  // namespace transaction

#endif  // SARALYSYSTEM_TRANSACTION_TRANSACTION_H_
