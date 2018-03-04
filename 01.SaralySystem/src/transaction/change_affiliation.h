// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_TRANSACTION_CHANGE_AFFILIATION_H_
#define SALARYSYSTEM_TRANSACTION_CHANGE_AFFILIATION_H_

#include <cstdint>
#include <string>
#include <memory>
#include <transaction/transaction.h>
#include <transaction/change_employee_transaction.h>
#include <payroll_domain/employee.h>
#include <payroll_domain/affiliation.h>
#include <payroll_domain/union_affiliation.h>
#include <payroll_domain/no_affiliation.h>
#include <payroll_database/payroll_database.h>

namespace transaction {
using payroll_domain::Employee;
using payroll_domain::Affiliation;
using payroll_domain::UnionAffiliation;
using payroll_domain::NoAffiliation;
using payroll_database::PayrollDatabase;

class ChangeAffiliation: public ChangeEmployeeTransaction {
 public:
    explicit ChangeAffiliation(int32_t id)
        : ChangeEmployeeTransaction{id} {}
    virtual ~ChangeAffiliation() override = default;

 private:
    virtual void RecordMembership(std::shared_ptr<Employee> e) = 0;
    virtual std::unique_ptr<Affiliation> GetAffiliation() const = 0;

 private:
    void Change(std::shared_ptr<Employee> e) final {
      RecordMembership(e);
      e->SetAffiliation(GetAffiliation());
    }
};

class ChangeMemberTransaction: public ChangeAffiliation {
 public:
    ChangeMemberTransaction(int32_t emp_id, int32_t member_id, double dues)
        : ChangeAffiliation{emp_id}
        , member_id_{member_id}
        , dues_{dues} {}
    virtual ~ChangeMemberTransaction() override = default;

 private:
    void RecordMembership(std::shared_ptr<Employee> e) override {
      PayrollDatabase::AddUnionMember(member_id_, e);
    }

    std::unique_ptr<Affiliation> GetAffiliation() const final {
      return std::unique_ptr<Affiliation>(new UnionAffiliation{member_id_, dues_});
    }

 private:
    int32_t member_id_;
    double dues_;
};

class ChangeUnaffiliatedTransaction: public ChangeAffiliation {
 public:
    ChangeUnaffiliatedTransaction(int32_t emp_id)
        : ChangeAffiliation{emp_id} {}
    virtual ~ChangeUnaffiliatedTransaction() override = default;

 private:
    void RecordMembership(std::shared_ptr<Employee> e) override {
      auto uf = dynamic_cast<const UnionAffiliation*>(&e->GetAffiliation());
      if (uf != nullptr) {
        int32_t member_id = uf->MemberId();
        PayrollDatabase::DeleteUnionMember(member_id);
      }
    }

    std::unique_ptr<Affiliation> GetAffiliation() const final {
      return std::unique_ptr<Affiliation>(new NoAffiliation{});
    }
};
}  // namespace transaction

#endif  // SALARYSYSTEM_TRANSACTION_CHANGE_AFFILIATION_H_
