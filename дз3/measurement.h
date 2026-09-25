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
        return ctx.end();
    }

    auto format(const Measurement<T>& m, std::format_context& ctx) const {
        double val = m.getValue().getValue();
        double err = m.getError();
        auto time = m.getTime();
        
        return std::format_to(
            ctx.out(),
            "Значение: {:.2f}, Погрешность: ±{:.2f}, Время: {:%Y-%m-%d %H:%M:%S}",
            val, err, time
        );
    }
};