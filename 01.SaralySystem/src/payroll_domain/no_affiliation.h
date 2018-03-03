// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_PAYROLL_DOMAIN_NO_AFFILIATION_H_
#define SALARYSYSTEM_PAYROLL_DOMAIN_NO_AFFILIATION_H_

#include <cstdint>
#include <payroll_domain/affiliation.h>

namespace payroll_domain {

// Null Object
class NoAffiliation: public Affiliation {
 public:
    NoAffiliation() = default;
    ~NoAffiliation() override = default;

    double ServiceCharge(const int64_t) override {
      return 0.0;
    }
    void AddServiceCharge(const int64_t, const double) override {
      return;
    }
};
}  // namespace payroll_domain

#endif  // SALARYSYSTEM_PAYROLL_DOMAIN_NO_AFFILIATION_H_
