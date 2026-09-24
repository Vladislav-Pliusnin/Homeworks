#include <iostream>
#include <cmath>

namespace Value {

    class Amper {

        private:
        double A;

        public:
        Amper (double amper) : A(amper) {
            if(!std::isfinite(amper)) {
                throw std::invalid_argument("The current value must be a finite number.\n");
            }
        }
        double amper() const {
            return A;
        }
    };

    class Volt {

        private:
        double V;

        public:
        Volt (double volt) : V(volt) {
            if(!std::isfinite(volt)) {
                throw std::invalid_argument("The voltage value must be a finite number.\n");
            }
        }
        double volt() const {
            return V;
        }
    };

    class Ohm {
        
        private:
        double O;

        public:
        Ohm (double ohm) : O(ohm) {
            if(!std::isfinite(ohm)) {
                throw std::invalid_argument("The current resistance value must be a finite number.\n");
            }
        }
        double ohm() const {
            return O;
        }
    };
    
    class Joule {

        private:
        double J;

        public:
        Joule (double joule) : J(joule) {
            if(!std::isfinite(joule)) {
                throw std::invalid_argument("The value of work must be a finite number.\n");
            }
        }
        double joule() const {
            return J;
        }
    };

    class Watt {

        private:
        double W;

        public:
        Watt (double watt) : W(watt) {
            if(!std::isfinite(watt)) {
                throw std::invalid_argument("The current power value must be a finite number.\n");
            }
        }
        double watt() const {
            return W;
        }
    };

    class Second {

        private:
        double s;

        public:
        Second (double second) : s(second) {
            if(!std::isfinite(second)) {
                throw std::invalid_argument("The current value must be a finite number.\n");
            }
            if(second <= 0) {
                throw std::invalid_argument("The time value must be positive")
            }
        }
        double second() const {
            return s;
        }
    };

    Amper operator""_mA(long double milamper) {
        return Amper(milamper / 1000.0);
    }
    Volt operator""_V(long double volt) {
        return Volt(volt);
    }
    Ohm operator""_Ohm(long double ohm) {
        return Ohm(ohm);
    }
    Joule operator""_J(long double joule) {
        return Joule(joule);
    }
    Watt operator""_W(long double watt) {
        return Watt(watt);
    }
    Second operator""_s(long double second) {
        return Second(second);
    }
};