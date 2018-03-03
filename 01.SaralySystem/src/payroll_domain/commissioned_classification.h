// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef SALARYSYSTEM_PAYROLL_DOMAIN_COMMISSIONED_CLASSIFICATION_H_
#define SALARYSYSTEM_PAYROLL_DOMAIN_COMMISSIONED_CLASSIFICATION_H_

#include <map>
#include <cstdint>
#include <payroll_domain/payment_classification.h>
#include <payroll_domain/sales_receipt.h>

namespace payroll_domain {
using payroll_domain::UPtrPayClass;
class CommissionedClassification: public PaymentClassification {
 public:
    explicit CommissionedClassification(double salary = 0.0,
                                        double commission_rate = 0.0)
      :PaymentClassification{}
      , salary_{salary}
      , commission_rate_{commission_rate}
      , sales_receipts_{} {}
    CommissionedClassification(const CommissionedClassification&) = default;
    CommissionedClassification& operator=(const CommissionedClassification&)
      = default;
    ~CommissionedClassification() override = default;

    UPtrPayClass clone() const override {
      return UPtrPayClass(new CommissionedClassification{*this});
    }
    double GetSalary() const { return salary_; }
    double GetCommissionRate() const { return commission_rate_; }
    void AddSalesReceipt(const SalesReceipt&& sr) {
      sales_receipts_.insert(std::make_pair(sr.date, sr));
    }
    SalesReceipt GetSalesReceipt(int64_t date) { return sales_receipts_[date]; }

 private:
    double salary_;
    double commission_rate_;
    std::map<int64_t, SalesReceipt> sales_receipts_;
};

}  // namespace payroll_domain

#endif  // SALARYSYSTEM_PAYROLL_DOMAIN_COMMISSIONED_CLASSIFICATION_H_
