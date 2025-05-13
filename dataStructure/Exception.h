#pragma once
#include<iostream>

class InitializationFailureException : public std::runtime_error {
public:
    explicit InitializationFailureException(const std::string& func, const std::string& msg)
        : std::runtime_error("Initialization failed in " + func + " : " + msg) {}
};

class AppendFailureException :public std::runtime_error {
public:
    explicit AppendFailureException(const std::string& func, const std::string& msg)
        :std::runtime_error("Initialization failed in " + func + " : " + msg) {}
};