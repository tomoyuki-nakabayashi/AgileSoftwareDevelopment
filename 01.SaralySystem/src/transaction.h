// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

namespace add_employee_transaction {

class Transaction {
 public:
    Transaction() = default;
    Transaction(const Transaction& other) = default;
    Transaction& operator=(const Transaction& other) = default;
    virtual ~Transaction() = default;
    virtual void Execute() = 0;
};
}  // namespace add_employee_transaction