// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <payroll_database/payroll_database.h>

namespace payroll_database {
static std::map<int, std::unique_ptr<Employee>> employees_ {};

void PayrollDatabase::AddEmployee(const int id, Employee& employee) {
  employees_[id] = std::unique_ptr<Employee>{new Employee{employee}};
}

Employee PayrollDatabase::GetEmployee(const int id) {
  return *(employees_.at(id).get());
}

void PayrollDatabase::Clear() {
  employees_.clear();
}
}  // namespace payroll_database
