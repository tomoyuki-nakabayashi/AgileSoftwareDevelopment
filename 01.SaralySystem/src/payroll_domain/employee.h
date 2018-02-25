// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SARALYSYSTEM_PAYROLL_DOMAIN_EMPLOYEE_H_
#define SARALYSYSTEM_PAYROLL_DOMAIN_EMPLOYEE_H_

#include <string>
#include <functional>
#include <memory>
#include <payroll_domain/payment_classification.h>
#include <payroll_domain/payment_schedule.h>

namespace payroll_domain {

using ClassificationUPtr = std::unique_ptr<PaymentClassification>;
using ScheduleUPtr = std::unique_ptr<PaymentSchedule>;

class Employee {
 public:
    Employee(int id, std::string name, std::string addr);
    Employee(const Employee&);
    Employee& operator=(const Employee&) = default;
    virtual ~Employee() = default;

    void SetClassification(ClassificationUPtr c) {
      classification_ = std::move(c);
    }

    void SetSchedule(ScheduleUPtr s) {
      schedule_ = std::move(s);
    }

    void SetMethod(std::function<void()> m) {
      method_ = m;
    }

    PaymentClassification GetPaymentClassification() {
      return *classification_;
    }

    PaymentSchedule GetPaymentSchedule() {
      return *schedule_;
    }

    std::function<void()> GetMethod() {
      return method_;
    }

    bool operator==(const Employee& rhs) const {
      return employee_id_ == rhs.employee_id_
            && name_ == rhs.name_
            && address_ == rhs.address_;
    }

    bool operator!=(const Employee &rhs) const {
      return !(*this == rhs);
    }

 private:
    int employee_id_;
    std::string name_;
    std::string address_;
    ClassificationUPtr classification_;
    ScheduleUPtr schedule_;
    std::function<void()> method_;
};

}  // namespace payroll_domain
#endif  // SARALYSYSTEM_PAYROLL_DOMAIN_EMPLOYEE_H_
