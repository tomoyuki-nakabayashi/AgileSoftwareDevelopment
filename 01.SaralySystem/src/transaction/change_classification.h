// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_TRANSACTION_CHANGE_CLASSIFICATION_H_
#define SALARYSYSTEM_TRANSACTION_CHANGE_CLASSIFICATION_H_

#include <cstdint>
#include <string>
#include <memory>
#include <transaction/transaction.h>
#include <transaction/change_employee_transaction.h>
#include <payroll_domain/employee.h>
#include <payroll_domain/payment_classification.h>
#include <payroll_domain/salaried_classification.h>
#include <payroll_domain/hourly_classification.h>
#include <payroll_domain/commissioned_classification.h>
#include <payroll_domain/payment_schedule.h>
#include <payroll_domain/monthly_schedule.h>
#include <payroll_domain/weekly_schedule.h>
#include <payroll_domain/biweekly_schedule.h>

namespace transaction {
using payroll_domain::Employee;
using payroll_domain::UPtrPayClass;
using payroll_domain::UPtrPaySchedule;
using payroll_domain::SalariedClassification;
using payroll_domain::HourlyClassification;
using payroll_domain::CommissionedClassification;
using payroll_domain::MonthlySchedule;
using payroll_domain::WeeklySchedule;
using payroll_domain::BiweeklySchedule;

class ChangeClassification: public ChangeEmployeeTransaction {
 public:
    explicit ChangeClassification(int32_t id)
        : ChangeEmployeeTransaction{id} {}
    virtual ~ChangeClassification() override = default;

 private:
    virtual UPtrPaySchedule GetSchedule() const = 0;
    virtual UPtrPayClass GetClassification() const = 0;

 private:
    void Change(std::shared_ptr<Employee> e) final {
      e->SetSchedule(GetSchedule());
      e->SetClassification(GetClassification());
    }
};

class ChangeHourlyTransaction: public ChangeClassification {
 public:
    ChangeHourlyTransaction(int32_t id, double hourly_pay)
        : ChangeClassification{id}
        , hourly_pay_{hourly_pay} {}
    virtual ~ChangeHourlyTransaction() override = default;

 private:
    UPtrPayClass GetClassification() const override {
      return UPtrPayClass(new HourlyClassification{hourly_pay_});
    }

    UPtrPaySchedule GetSchedule() const override {
      return UPtrPaySchedule(new WeeklySchedule{});
    }

 private:
    double hourly_pay_;
};

class ChangeSalariedTransaction: public ChangeClassification {
 public:
    ChangeSalariedTransaction(int32_t id, double salary)
        : ChangeClassification{id}
        , salary_{salary} {}
    virtual ~ChangeSalariedTransaction() override = default;

 private:
    UPtrPayClass GetClassification() const override {
      return UPtrPayClass(new SalariedClassification{salary_});
    }

    UPtrPaySchedule GetSchedule() const override {
      return UPtrPaySchedule(new MonthlySchedule{});
    }

 private:
    double salary_;
};

class ChangeCommissionedTransaction: public ChangeClassification {
 public:
    ChangeCommissionedTransaction(int32_t id, double salary, double commission_rate)
        : ChangeClassification{id}
        , salary_{salary}
        , commission_rate_{commission_rate} {}
    virtual ~ChangeCommissionedTransaction() override = default;

 private:
    UPtrPayClass GetClassification() const override {
      return UPtrPayClass(new CommissionedClassification{salary_, commission_rate_});
    }

    UPtrPaySchedule GetSchedule() const override {
      return UPtrPaySchedule(new BiweeklySchedule{});
    }

 private:
    double salary_;
    double commission_rate_;
};
}  // namespace transaction

#endif  // SALARYSYSTEM_TRANSACTION_CHANGE_CLASSIFICATION_H_
