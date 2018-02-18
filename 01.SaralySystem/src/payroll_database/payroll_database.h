// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_PAYROLL_DATABASE_PAYROLL_DATABASE_H_
#define SARALYSYSTEM_PAYROLL_DATABASE_PAYROLL_DATABASE_H_

#include <map>
#include <memory>
#include <payroll_domain/employee.h>

namespace payroll_database {
using payroll_domain::Employee;

class PayrollDatabase {
 public:
    PayrollDatabase() = delete;
    PayrollDatabase(const PayrollDatabase&) = delete;
    PayrollDatabase& operator=(const PayrollDatabase&) = delete;
    ~PayrollDatabase() = delete;
    static void AddEmployee(const int id, Employee& employee);
    static Employee GetEmployee(const int id);
    static void Clear();
};

}  // namespace payroll_database

#endif  // SARALYSYSTEM_PAYROLL_DATABASE_PAYROLL_DATABASE_H_
