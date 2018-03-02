// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <transaction/delete_employee.h>
#include <payroll_database/payroll_database.h>

namespace transaction {
using payroll_database::PayrollDatabase;

DeleteEmployee::DeleteEmployee(int id)
    : employee_id_{id} {}

void DeleteEmployee::Execute() {
  PayrollDatabase::DeleteEmployee(employee_id_);
}
}  // namespace transaction
