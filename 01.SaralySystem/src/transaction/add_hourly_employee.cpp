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
                                     double hourly_rate) 
  : AddEmployeeTransaction{id, name, addr}
  , hourly_rate_{hourly_rate} {
}

UPtrPayClass AddHourlyEmployee::GetClassification() const {
  return UPtrPayClass(new HourlyClassification{hourly_rate_});
}

UPtrPaySchedule AddHourlyEmployee::GetSchedule() const {
  return UPtrPaySchedule(new WeeklySchedule{});
}

}  // namespace transaction
