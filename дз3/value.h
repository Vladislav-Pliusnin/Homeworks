#pragma once

#include <iostream>
#include <cmath>
#include <stdexcept>

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
        double getValue() const {
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
        double getValue() const {
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
        double getValue() const {
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
        double getValue() const {
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
        double getValue() const {
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
                throw std::invalid_argument("The time value must be positive");
            }
        }
        double getValue() const {
            return s;
        }
    };

    inline Amper operator""_mA(long double milamper) {
        return Amper(milamper / 1000.0);
    }
    inline Volt operator""_V(long double volt) {
        return Volt(volt);
    }
    inline Ohm operator""_Ohm(long double ohm) {
        return Ohm(ohm);
    }
    inline Joule operator""_J(long double joule) {
        return Joule(joule);
    }
    inline Watt operator""_W(long double watt) {
        return Watt(watt);
    }
    inline Second operator""_s(long double second) {
        return Second(second);
    }

    inline Ohm operator/(const Volt& u, const Amper& i) {
        return Ohm(u.getValue() / i.getValue());
    }
    inline Amper operator/(const Volt& u, const Ohm& r) {
        return Amper(u.getValue() / r.getValue());
    }
    inline Volt operator*(const Amper& i, const Ohm& r) {
        return Volt(i.getValue() * r.getValue());
    }
    inline Watt operator*(const Volt& u, const Amper& i) {
        return Watt(u.getValue() * i.getValue());
    }
    inline Volt operator/(const Watt& p, const Amper& i) {
        return Volt(p.getValue() / i.getValue());
    }
    inline Amper operator/(const Watt& p, const Volt& u) {
        return Amper(p.getValue() / u.getValue());
    }
    inline Joule operator*(const Watt& p, const Second& s) {
        return Joule(p.getValue() * s.getValue());
    }
    inline Watt operator/(const Joule& a, const Second& s) {
        return Watt(a.getValue() / s.getValue());
    }
    inline Second operator/(const Joule& a, const Watt& p) {
        return Second(a.getValue() / p.getValue());
    }
};