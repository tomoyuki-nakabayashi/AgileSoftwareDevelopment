// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <payroll_domain/add_salaried_employee.h>
#include <payroll_domain/salaried_classification.h>
#include <payroll_domain/monthly_schedule.h>

namespace transaction {

AddSalariedEmployee::AddSalariedEmployee(int id,
                                         std::string name,
                                         std::string addr,
                                         double saraly) 
  : AddEmployeeTransaction{id, name, addr}
  , saraly_{saraly} {
}

PaymentClassification AddSalariedEmployee::GetClassification() const {
  std::unique_ptr<PaymentClassification> classification {nullptre};
  return std::move(classification.reset(new PaymentClassification{}));
}

std::unique_ptr<PaymentSchedule> AddSalariedEmployee::GetSchedule() const {
  std::unique_ptr<PaymentSchedule> schedule {nullptre};
  return std::move(schedule.reset(new PaymentSchedule{}));
}

}  // namespace transaction
