//
// luna
//
// Copyright © 2016, D.E. Goodman-Wilson
//

#pragma once

#include <string>
#include <map>

namespace luna
{

using status_code = uint16_t;
struct response
{
    std::string content_type;
    std::string content;
};

enum class request_method
{
    UNKNOWN = 0,
    GET,
    POST,
    PUT,
    PATCH,
    DELETE,
    //Yes, there are more than these. Later, though. Later.
};

using query_params = std::map<std::string, std::string>;

#define LUNA_FWD(...) ::std::forward<decltype(__VA_ARGS__)>(__VA_ARGS__)

#define MAKE_STRING_LIKE(x) class x : public std::string \
{ \
public: \
    x() = default; \
    x(const x &rhs) = default; \
    x(x &&rhs) = default; \
    x &operator=(const x &rhs) = default; \
    x &operator=(x &&rhs) = default; \
    x(const char *raw_string) : std::string(raw_string) {} \
    x(const char *raw_string, size_t length) : std::string(raw_string, length) {} \
    explicit x(size_t to_fill, char character) : std::string(to_fill, character) {} \
    x(const std::string &std_string) : std::string(std_string) {} \
    x(const std::string &std_string, size_t position, size_t length = std::string::npos) \
        : std::string(std_string, position, length) {} \
    explicit x(std::initializer_list<char> il) : std::string(il) {} \
    template<class InputIterator> \
    explicit x(InputIterator first, InputIterator last) \
        : std::string(first, last) {} \
}

#define MAKE_BOOL_LIKE(x) class x \
{ \
public: \
    x() = default; \
    x(const x &rhs) = default; \
    x(x &&rhs) = default; \
    x &operator=(const x &rhs) = default; \
    x &operator=(x &&rhs) = default; \
    x(bool new_val) : value{new_val} {} \
    x & operator=(bool && new_value) {value = new_value;} \
    explicit operator bool() {return value;} \
private: \
    bool value; \
}

#define MAKE_UINT16_T_LIKE(x) class x\
{ \
public: \
    x() = default; \
    x(const x &rhs) = default; \
    x(x &&rhs) = default; \
    x &operator=(const x &rhs) = default; \
    x &operator=(x &&rhs) = default; \
    x(uint16_t new_val) : value{new_val} {} \
    operator uint16_t() {return value;} \
private: \
    uint16_t value; \
}

} //namespace luna