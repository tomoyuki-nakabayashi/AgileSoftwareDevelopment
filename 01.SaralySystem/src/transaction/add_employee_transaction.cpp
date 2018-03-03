// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <transaction/add_employee_transaction.h>
#include <memory>
#include <payroll_database/payroll_database.h>
#include <payroll_domain/employee.h>

namespace transaction {
using payroll_database::PayrollDatabase;
using payroll_domain::Employee;

void AddEmployeeTransaction::Execute() {
  auto e = std::make_shared<Employee>(employee_id_, name_, address_);
  e->SetClassification(GetClassification());
  e->SetSchedule(GetSchedule());
  e->SetMethod([](){});

  PayrollDatabase::AddEmployee(employee_id_, e);
}
}  // namespace transaction
