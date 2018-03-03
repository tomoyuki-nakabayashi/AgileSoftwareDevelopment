// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <payroll_database/payroll_database.h>

namespace payroll_database {
static std::map<int, std::shared_ptr<Employee>> employees_ {};
static std::map<int, std::shared_ptr<Employee>> union_memer_ {};

void PayrollDatabase::AddEmployee(const int id, std::shared_ptr<Employee> e) {
  employees_[id] = e;
}

void PayrollDatabase::DeleteEmployee(const int id) {
  employees_.erase(id);
}

SPtrEmployee PayrollDatabase::GetEmployee(const int id) {
  return employees_[id];
}

void PayrollDatabase::AddUnionMember(const int id,
                                     std::shared_ptr<Employee> e) {
  union_memer_[id] = e;
}

void PayrollDatabase::DeleteUnionMember(const int id) {
  union_memer_.erase(id);
}

SPtrEmployee PayrollDatabase::GetUnionMember(const int id) {
  return union_memer_[id];
}

void PayrollDatabase::Clear() {
  employees_.clear();
  union_memer_.clear();
}
}  // namespace payroll_database
