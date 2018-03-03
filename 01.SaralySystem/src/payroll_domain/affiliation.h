// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_PAYROLL_DOMAIN_AFFILIATION_H_
#define SALARYSYSTEM_PAYROLL_DOMAIN_AFFILIATION_H_

#include <cstdint>

namespace payroll_domain {

// Movable but not copyable.
class Affiliation {
 public:
    Affiliation() = default;
    Affiliation(const Affiliation&) = delete;
    Affiliation(Affiliation&&) = default;
    Affiliation& operator=(const Affiliation&) = delete;
    Affiliation& operator=(Affiliation&&) = default;
    virtual ~Affiliation() = default;

    virtual double ServiceCharge(int64_t date) = 0;
    virtual void AddServiceCharge(int64_t date, double amount) = 0;
};
}  // namespace payroll_domain

#endif  // SALARYSYSTEM_PAYROLL_DOMAIN_AFFILIATION_H_
