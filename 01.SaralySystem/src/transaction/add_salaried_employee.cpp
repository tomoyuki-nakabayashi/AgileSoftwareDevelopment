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
  return std::unique_ptr<PaymentClassification>(new PaymentClassification{});
}

std::unique_ptr<PaymentSchedule> AddSalariedEmployee::GetSchedule() const {
  return std::unique_ptr<PaymentSchedule>(new PaymentSchedule{});
}

}  // namespace transaction
