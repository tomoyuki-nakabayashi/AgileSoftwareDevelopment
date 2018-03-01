// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_TRANSACTION_ADD_COMMISSIONED_EMPLOYEE_H_
#define SARALYSYSTEM_TRANSACTION_ADD_COMMISSIONED_EMPLOYEE_H_

#include <string>
#include <memory>
#include <transaction/add_employee_transaction.h>
#include <payroll_domain/payment_classification.h>
#include <payroll_domain/payment_schedule.h>

namespace transaction {
using payroll_domain::UPtrPayClass;
using payroll_domain::UPtrPaySchedule;

class AddCommissionedEmployee: public AddEmployeeTransaction {
 public:
    AddCommissionedEmployee() = default;
    AddCommissionedEmployee(int id,
                            std::string name,
                            std::string addr,
                            double salary,
                            double commission_rate);
    ~AddCommissionedEmployee() override = default;

 private:
    UPtrPaySchedule GetSchedule() const override;
    UPtrPayClass GetClassification() const override;

 private:
    double salary_;
    double commission_rate_;
};
}  // namespace transaction

#endif  // SARALYSYSTEM_TRANSACTION_ADD_COMMISSIONED_EMPLOYEE_H_
