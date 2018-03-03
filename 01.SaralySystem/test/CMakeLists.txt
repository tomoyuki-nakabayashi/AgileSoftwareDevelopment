cmake_minimum_required(VERSION 2.8)
include_directories(../src)
add_executable(unittests
  payroll_domain_test/employee_test.cpp
  payroll_database_test/payroll_database_test.cpp
  transaction_test/payroll_test.cpp
  ../src/payroll_domain/employee.cpp
  ../src/payroll_database/payroll_database.cpp
  ../src/transaction/add_employee_transaction.cpp
  ../src/transaction/add_salaried_employee.cpp
  ../src/transaction/add_hourly_employee.cpp
  ../src/transaction/add_commissioned_employee.cpp
  ../src/transaction/delete_employee.cpp
  ../src/transaction/time_card_transaction.cpp
  ../src/transaction/sales_receipt_transaction.cpp
  ../src/transaction/service_charge_transaction.cpp)
target_link_libraries(unittests gtest_main)