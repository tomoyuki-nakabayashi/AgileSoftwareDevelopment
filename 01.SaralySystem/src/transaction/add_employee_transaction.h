// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_TRANSACTION_ADD_EMPLOYEE_TRANSACTION_H_
#define SARALYSYSTEM_TRANSACTION_ADD_EMPLOYEE_TRANSACTION_H_

#include <string>
#include <memory>
#include <transaction/transaction.h>
#include <payroll_domain/payment_schedule.h>
#include <payroll_domain/payment_classification.h>

namespace transaction {
using payroll_domain::PaymentSchedule;
using payroll_domain::PaymentClassification;
class AddEmployeeTransaction: public Transaction {
 public:
    AddEmployeeTransaction(int id, std::string name, std::string addr)
        : employee_id_ {id}, name_ {name}, address_ {addr} {}
    AddEmployeeTransaction(const AddEmployeeTransaction&) = delete;
    AddEmployeeTransaction& operator=(const AddEmployeeTransaction&) = delete;
    virtual ~AddEmployeeTransaction() override = default;
    void Execute() final;

 private:
    virtual std::unique_ptr<PaymentSchedule> GetSchedule() const = 0;
    virtual std::unique_ptr<PaymentClassification> GetClassification() const = 0;

 private:
    int employee_id_;
    std::string name_;
    std::string address_;
};
}  // namespace transaction

#endif  // SARALYSYSTEM_TRANSACTION_ADD_EMPLOYEE_TRANSACTION_H_s
