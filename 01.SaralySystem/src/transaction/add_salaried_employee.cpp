// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <transaction/add_salaried_employee.h>
#include <payroll_domain/salaried_classification.h>
#include <payroll_domain/monthly_schedule.h>

namespace transaction {

AddSalariedEmployee::AddSalariedEmployee(int id,
                                         std::string name,
                                         std::string addr,
                                         double salary) 
  : AddEmployeeTransaction{id, name, addr}
  , salary_{salary} {
}

std::unique_ptr<PaymentClassification> AddSalariedEmployee::GetClassification() const {
  std::unique_ptr<PaymentClassification> classification {nullptr};
  classification.reset(new PaymentClassification{});
  return classification;
}

std::unique_ptr<PaymentSchedule> AddSalariedEmployee::GetSchedule() const {
  std::unique_ptr<PaymentSchedule> schedule {nullptr};
  schedule.reset(new PaymentSchedule{});
  return schedule;
}

}  // namespace transaction
