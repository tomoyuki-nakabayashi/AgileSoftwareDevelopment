// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_PAYROLL_DOMAIN_EMPLOYEE_H_
#define SARALYSYSTEM_PAYROLL_DOMAIN_EMPLOYEE_H_

#include <string>
#include <cstdint>

namespace payroll_domain {

class Employee {

 public:
    Employee(int32_t id, std::string name, std::string addr, double saraly);
    ~Employee() = default;
    Employee(const Employee& other) = default;
    Employee& operator=(const Employee& other) = default;

 private:

};

}  // namespace payroll_domain

#endif  // SARALYSYSTEM_PAYROLL_DOMAIN_EMPLOYEE_H_
