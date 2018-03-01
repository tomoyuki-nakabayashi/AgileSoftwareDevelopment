// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <transaction/add_commissioned_employee.h>
#include <payroll_domain/commissioned_classification.h>
#include <payroll_domain/biweekly_schedule.h>

namespace transaction {
using payroll_domain::CommissionedClassification;
using payroll_domain::BiweeklySchedule;

AddCommissionedEmployee::AddCommissionedEmployee(int id,
                                                 std::string name,
                                                 std::string addr,
                                                 double salary,
                                                 double commission_rate) 
  : AddEmployeeTransaction{id, name, addr}
  , salary_{salary}
  , commission_rate_{commission_rate} {
}

UPtrPayClass AddCommissionedEmployee::GetClassification() const {
  return UPtrPayClass(new CommissionedClassification{salary_, commission_rate_});
}

UPtrPaySchedule AddCommissionedEmployee::GetSchedule() const {
  return UPtrPaySchedule(new BiweeklySchedule{});
}

}  // namespace transaction
