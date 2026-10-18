#include "delivery.hpp"
#include <gtest/gtest.h>
using namespace demo;
TEST(DeliveryTest, LocalOrderHasBaseFee) {
DeliveryPolicy policy;
Shipment shipment{100000};
const auto fee = policy.quote(shipment);
EXPECT_EQ(fee, 30000);
}