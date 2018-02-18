// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <payroll_database/payroll_database.h>

namespace payroll_database {
void PayrollDatabase::AddEmployee(const int id, Employee *employee) {
  employees_.insert(std::make_pair(id, employee));
}

const Employee* PayrollDatabase::GetEmployee(const int id) const {
  return employees_.at(id);
}
}  // namespace payroll_database
