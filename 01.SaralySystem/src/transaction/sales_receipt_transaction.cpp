// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <transaction/sales_receipt_transaction.h>
#include <payroll_database/payroll_database.h>
#include <payroll_domain/commissioned_classification.h>

namespace transaction {
using payroll_database::PayrollDatabase;
using payroll_domain::CommissionedClassification;

void SalesReceiptTransaction::Execute() {
  auto e = PayrollDatabase::GetEmployee(employee_id_);
  auto pc = e->GetClassification();
  auto cc = dynamic_cast<CommissionedClassification*>(pc);
  if (cc != nullptr) {
    cc->AddSalesReceipt(SalesReceipt{date_, amount_});
  }
}

}  // namespace transaction
