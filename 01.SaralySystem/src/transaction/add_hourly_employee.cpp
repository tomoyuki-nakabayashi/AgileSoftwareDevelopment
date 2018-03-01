// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <transaction/add_hourly_employee.h>
#include <payroll_domain/hourly_classification.h>
#include <payroll_domain/weekly_schedule.h>

namespace transaction {
using payroll_domain::HourlyClassification;
using payroll_domain::WeeklySchedule;

AddHourlyEmployee::AddHourlyEmployee(int id,
                                     std::string name,
                                     std::string addr,
                                     double hourly_pay) 
  : AddEmployeeTransaction{id, name, addr}
  , hourly_pay_{hourly_pay} {
}

std::unique_ptr<PaymentClassification> AddHourlyEmployee::GetClassification() const {
  return std::unique_ptr<PaymentClassification>(new HourlyClassification{hourly_pay_});
}

std::unique_ptr<PaymentSchedule> AddHourlyEmployee::GetSchedule() const {
  return std::unique_ptr<PaymentSchedule>(new WeeklySchedule{});
}

}  // namespace transaction
