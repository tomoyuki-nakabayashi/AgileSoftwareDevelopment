// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_TRANSACTION_ADD_HOURLY_EMPLOYEE_H_
#define SARALYSYSTEM_TRANSACTION_ADD_HOURLY_EMPLOYEE_H_

#include <transaction/add_employee_transaction.h>
#include <string>
#include <memory>

namespace transaction {

class AddHourlyEmployee: public AddEmployeeTransaction {
 public:
    AddHourlyEmployee(int id,
                      std::string name,
                      std::string addr,
                      double hourly_pay);
    ~AddHourlyEmployee() override = default;

 private:
    std::unique_ptr<PaymentSchedule> GetSchedule() const override;
    std::unique_ptr<PaymentClassification> GetClassification() const override;

 private:
    double hourly_pay_;
};
}  // namespace transaction

#endif  // SARALYSYSTEM_TRANSACTION_ADD_HOURLY_EMPLOYEE_H_
