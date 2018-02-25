// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <transaction/add_salaried_employee.h>
#include <payroll_domain/salaried_classification.h>
#include <payroll_domain/monthly_schedule.h>

namespace transaction {
using payroll_domain::SalariedClassification;
using payroll_domain::MonthlySchedule;

AddSalariedEmployee::AddSalariedEmployee(int id,
                                         std::string name,
                                         std::string addr,
                                         double salary) 
  : AddEmployeeTransaction{id, name, addr}
  , salary_{salary} {
}

std::unique_ptr<PaymentClassification> AddSalariedEmployee::GetClassification() const {
  return std::unique_ptr<PaymentClassification>(new SalariedClassification{salary_});
}

std::unique_ptr<PaymentSchedule> AddSalariedEmployee::GetSchedule() const {
  return std::unique_ptr<PaymentSchedule>(new MonthlySchedule{});
}

}  // namespace transaction
