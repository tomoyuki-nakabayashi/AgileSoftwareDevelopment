// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_TRANSACTION_DELETE_EMPLOYEE_H_
#define SALARYSYSTEM_TRANSACTION_DELETE_EMPLOYEE_H_

#include <transaction/transaction.h>

namespace transaction {

class DeleteEmployee: public Transaction {
 public:
    explicit DeleteEmployee(int id = 0);
    ~DeleteEmployee() override = default;
    void Execute() override;

 private:
    const int employee_id_;
};
}  // namespace transaction

#endif  // SALARYSYSTEM_TRANSACTION_DELETE_EMPLOYEE_H_
