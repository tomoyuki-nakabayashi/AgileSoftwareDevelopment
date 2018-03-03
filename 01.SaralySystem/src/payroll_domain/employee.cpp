// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <payroll_domain/employee.h>

namespace payroll_domain {
Employee::Employee(int id, std::string name, std::string addr)
    : employee_id_{id}
    , name_{name}
    , address_{addr}
    , classification_{nullptr}
    , schedule_{nullptr}
    , method_{}
    , affiliation_{nullptr} {    
}

void Employee::SetClassification(std::unique_ptr<PaymentClassification> c) {
  classification_ = std::move(c);
}

void Employee::SetSchedule(std::unique_ptr<PaymentSchedule> s) {
  schedule_ = std::move(s);
}

void Employee::SetMethod(std::function<void()> m) {
  method_ = m;
}

PaymentClassification* Employee::GetClassification() const{ 
  return classification_.get();
}

PaymentSchedule* Employee::GetSchedule() const {
  return schedule_.get();
}

std::function<void()> Employee::GetMethod() const {
  return method_;
}
}  // namespace payroll_domain
