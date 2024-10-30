#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include <string_view>

#ifndef NDEBUG
#define WOOF_PRINT_DEBUG
#endif

class woof
{
public:
    template<typename... Args>
    static void log(Args&&... args)
    {
        streamInto(": ", *sOut, std::forward<Args>(args)...);
    }

    template<typename... Args>
    static void info(Args&&... args)
    {
        streamInto(" info: ", *sErr, std::forward<Args>(args)...);
    }

    template<typename... Args>
    static void warn(Args&&... args)
    {
        streamInto(" warn: ", *sErr, std::forward<Args>(args)...);
    }

    template<typename... Args>
    static void error(Args&&... args)
    {
        streamInto(" error: ", *sErr, std::forward<Args>(args)...);
    }

#ifdef WOOF_PRINT_DEBUG
    template<typename... Args>
    static void debug(Args&&... args)
    {
        streamInto(" debug: ", *sOut, std::forward<Args>(args)...);
    }
#endif

    static void setPrefix(const std::string_view& prefix)
    {
        sPrefix = prefix;
    }

    static void setOutputStream(std::ostream& stream)
    {
        sOut = &stream;
    }

    static void setErrorStream(std::ostream& stream)
    {
        sErr = &stream;
    }

private:
    template<typename... Args>
    static void streamInto(const std::string_view& prefix, std::ostream& stream, Args&&... args)
    {
        stream << sPrefix << prefix;
        (insertSpaces(stream, args), ...);
        stream << '\n';
    }

    template<typename T>
    static void insertSpaces(std::ostream& os, const T& arg)
    {
        os << arg << ' ';
    };

    static std::ostream* sOut;
    static std::ostream* sErr;
    static std::string sPrefix;
};

#ifdef WOOF_PRINT_DEBUG
#define WOOF_DEBUG(...) woof::debug(__VA_ARGS__)
#else
#define WOOF_DEBUG(...)
#endif

