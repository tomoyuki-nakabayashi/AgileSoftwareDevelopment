// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_TRANSACTION_CHANGE_NAME_TRANSACTION_H_
#define SALARYSYSTEM_TRANSACTION_CHANGE_NAME_TRANSACTION_H_

#include <cstdint>
#include <string>
#include <memory>
#include <transaction/transaction.h>
#include <transaction/change_employee_transaction.h>
#include <payroll_domain/employee.h>

namespace transaction {
using payroll_domain::Employee;

class ChangeNameTransaction: public ChangeEmployeeTransaction {
 public:
    ChangeNameTransaction(int32_t id, std::string name)
        : ChangeEmployeeTransaction{id}
        , name_{name} {}
    virtual ~ChangeNameTransaction() override = default;

 private:
    void Change(std::shared_ptr<Employee> e) override {
      e->SetName(name_);
    }

 private:
    std::string name_;
};
}  // namespace transaction

#endif  // SALARYSYSTEM_TRANSACTION_CHANGE_NAME_TRANSACTION_H_
