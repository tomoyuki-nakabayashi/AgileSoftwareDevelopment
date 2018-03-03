// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <payroll_database/payroll_database.h>

namespace payroll_database {
static std::map<int, std::shared_ptr<Employee>> employees_ {};

void PayrollDatabase::AddEmployee(const int id, Employee& employee) {
  employees_[id] = std::make_shared<Employee>(employee);
}

void PayrollDatabase::DeleteEmployee(const int id) {
  employees_.erase(id);
}

SPtrEmployee PayrollDatabase::GetEmployee(const int id) {
  return employees_[id];
}

void PayrollDatabase::Clear() {
  employees_.clear();
}
}  // namespace payroll_database
