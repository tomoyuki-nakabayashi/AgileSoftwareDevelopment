// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_PAYROLL_DOMAIN_EMPLOYEE_H_
#define SALARYSYSTEM_PAYROLL_DOMAIN_EMPLOYEE_H_

#include <string>
#include <functional>
#include <memory>
#include <payroll_domain/payment_classification.h>
#include <payroll_domain/payment_schedule.h>
#include <payroll_domain/affiliation.h>

namespace payroll_domain {
class Employee;
using SPtrEmployee = std::shared_ptr<Employee>;
using UPtrClassification = std::unique_ptr<PaymentClassification>;
using UPtrSchedule = std::unique_ptr<PaymentSchedule>;
using UPtrAffiliation = std::unique_ptr<Affiliation>;

class Employee {
 public:
    Employee(int id, std::string name, std::string addr);
    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = default;
    virtual ~Employee() = default;

    void SetClassification(UPtrClassification c);
    void SetSchedule(UPtrSchedule s);
    void SetMethod(std::function<void()> m);
    void SetAffiliation(UPtrAffiliation a);

    PaymentClassification* GetClassification() const;
    PaymentSchedule* GetSchedule() const;
    std::function<void()> GetMethod() const;
    Affiliation* GetAffiliation() const;

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
    UPtrClassification classification_;
    UPtrSchedule schedule_;
    std::function<void()> method_;
    UPtrAffiliation affiliation_;
};

}  // namespace payroll_domain
#endif  // SALARYSYSTEM_PAYROLL_DOMAIN_EMPLOYEE_H_
