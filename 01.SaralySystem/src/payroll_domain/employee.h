// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_PAYROLL_DOMAIN_EMPLOYEE_H_
#define SARALYSYSTEM_PAYROLL_DOMAIN_EMPLOYEE_H_

#include <string>

namespace payroll_domain {

struct Employee {
  int employee_id_;
  std::string name_;
  std::string address_;

  Employee(int id, std::string name, std::string addr);
  Employee(const Employee& other) = default;
  Employee& operator=(const Employee& other) = default;
  ~Employee() = default;
};

}  // namespace payroll_domain

bool operator==(const payroll_domain::Employee& lhs,
                const payroll_domain::Employee& rhs) {
  return lhs.employee_id_ == rhs.employee_id_
      && lhs.name_ == rhs.name_
      && lhs.address_ == rhs.address_;
}

bool operator!=(const payroll_domain::Employee& lhs,
                const payroll_domain::Employee& rhs) {
  return !(lhs == rhs);
}
#endif  // SARALYSYSTEM_PAYROLL_DOMAIN_EMPLOYEE_H_
