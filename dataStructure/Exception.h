#pragma once
#include <stdexcept>
#include <string>

class InitializationFailureException : public std::runtime_error {
public:
    explicit InitializationFailureException(const std::string& func)
        : std::runtime_error("Initialization failed in " + func) {}

    explicit InitializationFailureException(const std::string& func, const std::string& msg)
        : std::runtime_error("Initialization failed in " + func + " : " + msg) {}
};

class AppendFailureException : public std::runtime_error {
public:
    explicit AppendFailureException(const std::string& func)
        : std::runtime_error("Append failed in " + func) {}

    explicit AppendFailureException(const std::string& func, const std::string& msg)
        : std::runtime_error("Append failed in " + func + " : " + msg) {}
};

class InvalidRankException : public std::runtime_error {
public:
    explicit InvalidRankException(const std::string& func)
        : std::runtime_error("Invalid rank access in " + func) {}

    explicit InvalidRankException(const std::string& func, const std::string& msg)
        : std::runtime_error("Invalid rank access in " + func + " : " + msg) {}
};

class FullListException : public std::runtime_error {
public:
    explicit FullListException(const std::string& func)
        : std::runtime_error("Invalid Action: Tried to append to a full fixed-size list in " + func) {}

    explicit FullListException(const std::string& func, const std::string& msg)
        : std::runtime_error("Invalid Action: Tried to append to a full fixed-size list in " + func + " : " + msg) {}
};

class RemoveFailureException :public std::runtime_error {
public:
    explicit RemoveFailureException(const std::string&func)
        :std::runtime_error("Remove failed in " + func) {}
    explicit RemoveFailureException(const std::string& func, const std::string& msg)
        :std::runtime_error("Remove failed in " + func + " : " + msg) {}
};