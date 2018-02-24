// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_TRANSACTION_ADD_SALARIED_EMPLOYEE_H_
#define SARALYSYSTEM_TRANSACTION_ADD_SALARIED_EMPLOYEE_H_

#include <transaction/add_employee_transaction.h>
#include <string>
#include <memory>

namespace transaction {

class AddSalariedEmployee: public AddEmployeeTransaction {
 public:
    AddSalariedEmployee(int id,
                        std::string name,
                        std::string addr,
                        double saraly);
    ~AddSalariedEmployee() override = default;

 private:
    std::unique_ptr<PaymentSchedule> GetSchedule() const override;
    std::unique_ptr<PaymentClassification> GetClassification() const override;

 private:
    double salary_;
};
}  // namespace transaction

#endif  // SARALYSYSTEM_TRANSACTION_ADD_SALARIED_EMPLOYEE_H_
