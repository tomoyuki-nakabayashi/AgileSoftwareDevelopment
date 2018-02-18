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

  Employee(int id, std::string name, std::string addr)
      : employee_id_ {id}
      , name_ {name}
      , address_ {addr} {

  }
  Employee(const Employee& other) = default;
  Employee& operator=(const Employee& other) = default;
  virtual ~Employee() = default;

  bool operator==(const Employee& rhs) const {
    return employee_id_ == rhs.employee_id_
          && name_ == rhs.name_
          && address_ == rhs.address_;
  }

  bool operator!=(const Employee &rhs) const {
    return !(*this == rhs);
  }
};

}  // namespace payroll_domain
#endif  // SARALYSYSTEM_PAYROLL_DOMAIN_EMPLOYEE_H_
