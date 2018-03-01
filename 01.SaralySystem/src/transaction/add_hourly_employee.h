// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_TRANSACTION_ADD_HOURLY_EMPLOYEE_H_
#define SARALYSYSTEM_TRANSACTION_ADD_HOURLY_EMPLOYEE_H_

#include <string>
#include <memory>
#include <transaction/add_employee_transaction.h>
#include <payroll_domain/payment_classification.h>
#include <payroll_domain/payment_schedule.h>

namespace transaction {
using payroll_domain::UPtrPayClass;
using payroll_domain::UPtrPaySchedule;

class AddHourlyEmployee: public AddEmployeeTransaction {
 public:
    AddHourlyEmployee(int id,
                      std::string name,
                      std::string addr,
                      double hourly_rate);
    ~AddHourlyEmployee() override = default;

 private:
    UPtrPaySchedule GetSchedule() const override;
    UPtrPayClass GetClassification() const override;

 private:
    double hourly_rate_;
};
}  // namespace transaction

#endif  // SARALYSYSTEM_TRANSACTION_ADD_HOURLY_EMPLOYEE_H_
