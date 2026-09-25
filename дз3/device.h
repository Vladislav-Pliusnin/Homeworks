#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <stdexcept>

namespace Devices {
    class Ampermeter {

        private:
        double min_range;
        double max_range;
        double accuracy_class;
        std::string id;

        public:
        Ampermeter (double min_r, double max_r, double acc, const std::string& identifier) : min_range(min_r), max_range(max_r), accuracy_class(acc), id(identifier) {
            
            if(min_range >= max_range) {
                throw std::invalid_argument("The minimum should be less than the maximum\n");
            }
            if(accuracy_class <= 0) {
                throw std::invalid_argument("The accuracy class must be positive\n");
            }
            if(id.empty()) {
                throw std::invalid_argument("The ID cannot be empty\n");
            }
        }

        Measurement<Value::Amper> measure() {
            static std::random_device rd;
            static std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dist(min_range, max_range);
            double random_value = dist(gen);
            
            double error = (accuracy_class / 100.0) * max_range;
            auto time = std::chrono::system_clock::now();
            
            Amper current(random_value);
            return Measurement<Value::Amper>(current, error, time);
        }
    }

    class Voltmeter {

        private:
        double min_range;
        double max_range;
        double accuracy_class;
        std::string id;

        public:
        Voltmeter (double min_r, double max_r, double acc, const std::string& identifier) : min_range(min_r), max_range(max_r), accuracy_class(acc), id(identifier) {
            
            if(min_range >= max_range) {
                throw std::invalid_argument("The minimum should be less than the maximum\n");
            }
            if(accuracy_class <= 0) {
                throw std::invalid_argument("The accuracy class must be positive\n");
            }
            if(id.empty()) {
                throw std::invalid_argument("The ID cannot be empty\n");
            }
        }

        Measurement<Value::Volt> measure() {
            static std::random_device rd;
            static std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dist(min_range, max_range);
            double random_value = dist(gen);
            
            double error = (accuracy_class / 100.0) * max_range;
            auto time = std::chrono::system_clock::now();
            
            Value::Volt voltage(random_value);
            return Measurement<Value::Volt>(voltage, error, time);
        }
    }

    class Multimeter {

        private:
        double min_range;
        double max_range;
        double accuracy_class;
        std::string id;

        public:
        Multimeter (double min_r, double max_r, double acc, const std::string& identifier) : min_range(min_r), max_range(max_r), accuracy_class(acc), id(identifier) {
            
            if(min_range >= max_range) {
                throw std::invalid_argument("The minimum should be less than the maximum\n");
            }
            if(accuracy_class <= 0) {
                throw std::invalid_argument("The accuracy class must be positive\n");
            }
            if(id.empty()) {
                throw std::invalid_argument("The ID cannot be empty\n");
            }
        }
        template<typename T>
        Measurement<T> measure() {
            static std::random_device rd;
            static std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dist(min_range, max_range);
            double random_value = dist(gen);
            
            double error = (accuracy_class / 100.0) * max_range;
            auto time = std::chrono::system_clock::now();
            
            T value(random_value);
            return Measurement<T>(value, error, time);
        }s
    }
};