// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_TRANSACTION_ADD_SALARIED_EMPLOYEE_H_
#define SALARYSYSTEM_TRANSACTION_ADD_SALARIED_EMPLOYEE_H_

#include <string>
#include <memory>
#include <transaction/add_employee_transaction.h>
#include <payroll_domain/payment_classification.h>
#include <payroll_domain/payment_schedule.h>

namespace transaction {
using payroll_domain::UPtrPayClass;
using payroll_domain::UPtrPaySchedule;

class AddSalariedEmployee: public AddEmployeeTransaction {
 public:
    AddSalariedEmployee(int id,
                        std::string name,
                        std::string addr,
                        double salary);
    ~AddSalariedEmployee() override = default;

 private:
    UPtrPaySchedule GetSchedule() const override;
    UPtrPayClass GetClassification() const override;

 private:
    double salary_;
};
}  // namespace transaction

#endif  // SALARYSYSTEM_TRANSACTION_ADD_SALARIED_EMPLOYEE_H_
