// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_TRANSACTION_ADD_EMPLOYEE_TRANSACTION_H_
#define SARALYSYSTEM_TRANSACTION_ADD_EMPLOYEE_TRANSACTION_H_

#include <string>
#include <transaction/transaction.h>

namespace transaction {
class AddEmployeeTransaction: public Transaction {
 public:
    AddEmployeeTransaction(int id, std::string name, std::string addr)
        : employee_id {id}, name_ {name}, address_ {addr} {}
    AddEmployeeTransaction(const AddEmployeeTransaction&) = delete;
    AddEmployeeTransaction& operator=(const AddEmployeeTransaction&) = delete;
    virtual ~AddEmployeeTransaction() override = default;
    void Execute() override;

 private:
    PaymentSchedule GetSchedule() = 0 const;
    PaymentClassification GetClassification() = 0 const;

 private:
    int employee_id_;
    std::string name_;
    std::string address_;
};
}  // namespace transaction

#endif  // SARALYSYSTEM_TRANSACTION_ADD_EMPLOYEE_TRANSACTION_H_s
