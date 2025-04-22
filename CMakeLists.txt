cmake_minimum_required(VERSION 3.30)
project(cpp00)

set(CMAKE_CXX_STANDARD 98)

add_executable(cpp00_ex_00
        ex00/MegaPhone.cpp
)

add_executable(cpp00_ex_01
        ex01/PhoneBook.cpp
        ex01/Contact.hpp
        ex01/Contact.cpp
        ex01/main.cpp
)