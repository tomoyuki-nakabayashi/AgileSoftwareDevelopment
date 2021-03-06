// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_PAYROLL_DOMAIN_TIME_CARD_H_
#define SALARYSYSTEM_PAYROLL_DOMAIN_TIME_CARD_H_

#include <cstdint>

namespace payroll_domain {

struct TimeCard {
  int64_t date;
  double hours;
};
}  // namespace payroll_domain

#endif  // SALARYSYSTEM_PAYROLL_DOMAIN_TIME_CARD_H_
