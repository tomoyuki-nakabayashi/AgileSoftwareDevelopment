// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_TRANSACTION_PAY_DAY_TRANSACTION_H_
#define SALARYSYSTEM_TRANSACTION_PAY_DAY_TRANSACTION_H_

#include <vector>
#include <transaction/transaction.h>
#include <boost/date_time/gregorian/gregorian.hpp>

namespace transaction {
namespace gr = boost::gregorian;

class PayDayTransaction: public Transaction {
 public:
    PayDayTransaction(gr::date pay_date)
        : pay_date_{pay_date}, paycheck_{} {}
    ~PayDayTransaction() override = default;

    void Execute() override;

 private:
    const gr::date pay_date_;
    std::vector<Paycheck> paychecks_;
};
}  // namespace transaction

#endif  // SALARYSYSTEM_TRANSACTION_PAY_DAY_TRANSACTION_H_
