// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <transaction/pay_day_transaction.h>
#include <payroll_database/payroll_database.h>
#include <payroll_domain/employee.h>

namespace transaction {
using payroll_database::PyarollDatabase;

void PayDayTransaction::Execute() {
  auto ids = PayrollDatabase::GetAllEmployeeIds();
  for (auto id : ids) {
    Employee e = PayrollDatabase.GetEmployee(id);
    if (e.IsPayDate(pay_date_)) {
      Paycheck pc{e.GetPayPeriodStartDate(pay_date_), pay_date_};
      e.Payday(pc);
      paychecks_.put(id, pc);
    }
  }
}

}  // namespace transaction
