// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_PAYROLL_DOMAIN_UNION_AFFILIATION_H_
#define SALARYSYSTEM_PAYROLL_DOMAIN_UNION_AFFILIATION_H_

#include <cstdint>
#include <map>
#include <payroll_domain/affiliation.h>

namespace payroll_domain {

class UnionAffiliation: public Affiliation {
 public:
    explicit UnionAffiliation(int32_t member_id, double due = 0.0):
        Affiliation{}, member_id_{member_id}, due_{due}, service_charges_{} {}
    UnionAffiliation(const UnionAffiliation&) = delete;
    UnionAffiliation(UnionAffiliation&&) = default;
    UnionAffiliation& operator=(const UnionAffiliation&) = delete;
    UnionAffiliation& operator=(UnionAffiliation&&) = default;
    ~UnionAffiliation() override = default;

    double ServiceCharge(const int64_t date) override {
      return service_charges_[date];
    }
    void AddServiceCharge(const int64_t date, const double amount) override {
      service_charges_.emplace(date, amount);
    }
    int32_t MemberId() const { return member_id_; }
    double Dues() const { return due_; }

 private:
    int32_t member_id_;
    double due_;
    std::map<int64_t, double> service_charges_;
};
}  // namespace payroll_domain

#endif  // SALARYSYSTEM_PAYROLL_DOMAIN_UNION_AFFILIATION_H_
