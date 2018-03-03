// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <transaction/time_card_transaction.h>
#include <payroll_database/payroll_database.h>
#include <payroll_domain/hourly_classification.h>

namespace transaction {
using payroll_database::PayrollDatabase;
using payroll_domain::HourlyClassification;

void TimeCardTransaction::Execute() {
  auto e = PayrollDatabase::GetEmployee(employee_id_);
  auto pc = e->GetClassification();
  auto hc = dynamic_cast<HourlyClassification*>(pc);
  if (hc != nullptr) {
    hc->AddTimeCard(TimeCard{date_, hours_});
  }
}

}  // namespace transaction
