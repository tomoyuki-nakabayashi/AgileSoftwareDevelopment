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
    explicit UnionAffiliation(double due = 0.0):
        Affilication{}, due_{due}, service_charges_{} {}
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

 private:
    double due_;
    std::map<int64_t, double> service_charges_;
};
}  // namespace payroll_domain

#endif  // SALARYSYSTEM_PAYROLL_DOMAIN_UNION_AFFILIATION_H_
