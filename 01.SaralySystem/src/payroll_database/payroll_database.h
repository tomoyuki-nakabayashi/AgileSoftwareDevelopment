// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_PAYROLL_DATABASE_PAYROLL_DATABASE_H_
#define SARALYSYSTEM_PAYROLL_DATABASE_PAYROLL_DATABASE_H_

#include <map>
#include <payroll_domain/employee.h>

namespace payroll_database {
using payroll_domain::Employee;

class PayrollDatabase {
 public:
    PayrollDatabase(): employees_ {} {}
    PayrollDatabase(const PayrollDatabase&) = delete;
    PayrollDatabase& operator=(const PayrollDatabase&) = delete;
    ~PayrollDatabase() = default;
    void AddEmployee(const int id, Employee *employee);
    const Employee* GetEmployee(const int id) const;

 private:
    std::map<int, Employee*> employees_;
};

}  // namespace payroll_database

#endif  // SARALYSYSTEM_PAYROLL_DATABASE_PAYROLL_DATABASE_H_
