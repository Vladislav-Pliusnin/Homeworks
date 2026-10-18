#pragma once
#include <cstdint>

namespace demo {
    using Cents = std::int64_t;
    struct Shipment {
        Cents subtotal;
    };
    class DeliveryPolicy {
        public:
        Cents quote(const Shipment& s) const {
            (void)s;
            return 30000;
        }
    };
}