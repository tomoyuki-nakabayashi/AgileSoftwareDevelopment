// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <transaction/service_charge_transaction.h>
#include <payroll_database/payroll_database.h>
#include <payroll_domain/affiliation.h>

namespace transaction {
using payroll_database::PayrollDatabase;
using payroll_domain::Affiliation;

void ServiceChargeTransaction::Execute() {
  auto e = PayrollDatabase::GetUnionMember(member_id_);
  auto& a = e->GetAffiliation();
  a.AddServiceCharge(date_, charge_);
}

}  // namespace transaction
