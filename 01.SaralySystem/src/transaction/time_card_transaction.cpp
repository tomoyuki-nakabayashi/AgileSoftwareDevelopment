// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <transaction/time_card_transaction.h>
#include <payroll_database/payroll_database.h>

namespace transaction {
using payroll_database::PayrollDatabase;

void TimeCardTransaction::Execute() {
  auto e = PayrollDatabase::GetEmployee(employee_id_);
  
}

}  // namespace transaction
