// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_TRANSACTION_CHANGE_EMPLOYEE_TRANSACTION_H_
#define SALARYSYSTEM_TRANSACTION_CHANGE_EMPLOYEE_TRANSACTION_H_

#include <cstdint>
#include <memory>
#include <transaction/transaction.h>
#include <payroll_domain/employee.h>
#include <payroll_database/payroll_database.h>

namespace transaction {
using payroll_domain::Employee;
using payroll_database::PayrollDatabase;

class ChangeEmployeeTransaction: public Transaction {
 public:
    explicit ChangeEmployeeTransaction(int32_t id)
        : Transaction{}
        , employee_id_{id} {}
    virtual ~ChangeEmployeeTransaction() override = default;
    void Execute() final {
      auto e = PayrollDatabase::GetEmployee(employee_id_);
      if (e != nullptr) Change(e);
    }

 private:
    virtual void Change(std::shared_ptr<Employee> e) = 0;

 private:
    int32_t employee_id_;
};
}  // namespace transaction

#endif  // SALARYSYSTEM_TRANSACTION_CHANGE_EMPLOYEE_TRANSACTION_H_
