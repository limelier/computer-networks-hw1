cmake_minimum_required(VERSION 3.15)
project(tema_1 C)

set(CMAKE_C_STANDARD 11)

add_executable(tema_1 main.c init.c init.h parent/master.c parent/master.h util.h children/loginWorker.c children/loginWorker.h children/findWorker.c children/findWorker.h children/statWorker.c children/statWorker.h)