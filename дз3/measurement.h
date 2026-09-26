#pragma once

#include "value.h"
#include <chrono>
#include <stdexcept>
#include <format>
#include <ctime>

template<typename T>
class Measurement {
    private:
    T value;
    double error;
    std::chrono::system_clock::time_point time;
    public:
    Measurement(T val, double err, std::chrono::system_clock::time_point t) : value(val), error(err), time(t) {
        if (error < 0) {
            throw std::invalid_argument("Error cannot be negative");
        }
    }

    T getValue() const {
        return value;
    }
    double getError() const {
        return error;
    }
    std::chrono::system_clock::time_point getTime() const {
        return time;
    }
};

template<typename T>
struct std::formatter<Measurement<T>> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    template<typename FormatContext>
    auto format(const Measurement<T>& m, FormatContext& ctx) const {
        return std::format_to(
            ctx.out(),
            "{:.2f} +/- {:.2f}",
            m.getValue().getValue(),
            m.getError()
        );
    }
};