cmake_minimum_required(VERSION 3.12)
project(BennysBank)

set(CMAKE_CXX_STANDARD 14)

add_executable(BennysBank main.cpp Bank.h Account.h Transaction.h LinkedTransactionList.h)