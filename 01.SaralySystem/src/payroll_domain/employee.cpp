// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <payroll_domain/employee.h>

namespace payroll_domain {
Employee::Employee(int id, std::string name, std::string addr)
    : employee_id_ {id}
    , name_ {name}
    , address_ {addr}
    , classification_ {nullptr}
    , schedule_ {nullptr}
    , method_ {} {    
}

Employee::Employee(const Employee& other)
    : employee_id_ {other.employee_id_}
    , name_ {other.name_}
    , address_ {other.address_}
    , classification_ {std::make_unique<PaymentClassification>(*other.classification_)}
    , schedule_ {std::make_unique<PaymentSchedule>(*other.schedule_)}
    , method_ {other.method_} {    
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

const PaymentClassification& Employee::GetPaymentClassification() const{ 
    return *classification_;
}

const PaymentSchedule& Employee::GetPaymentSchedule() const {
    return *schedule_;
}

std::function<void()> Employee::GetMethod() const {
    return method_;
}
}  // namespace payroll_domain
