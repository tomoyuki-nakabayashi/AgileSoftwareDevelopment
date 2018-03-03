// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_PAYROLL_DOMAIN_SALES_RECEIPT_H_
#define SALARYSYSTEM_PAYROLL_DOMAIN_SALES_RECEIPT_H_

#include <cstdint>

namespace payroll_domain {

struct SalesReceipt {
  int64_t date;
  double amount;
};
}  // namespace payroll_domain

#endif  // SALARYSYSTEM_PAYROLL_DOMAIN_SALES_RECEIPT_H_
