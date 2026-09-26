#include <iostream>
#include "device.h"
#include "value.h"

void demo_values() {
    using namespace Value;
    
    std::cout << "Demonstration of values\n";
    
    Volt u = 12.0_V;
    Amper i = 2000.0_mA;
    
    Ohm r = u / i;
    std::cout << "R = U / I = " << r.getValue() << " Ohm\n";
    
    Watt p = u * i;
    std::cout << "P = U * I = " << p.getValue() << " W\n";
    
    Second t = 5.0_s;
    Joule a = p * t;
    std::cout << "A = P * t = " << a.getValue() << " J\n";
    
    Amper current = 500.0_mA;
    std::cout << "500 mA = " << current.getValue() << " A\n\n";
}

void demo_ampermeter() {
    using namespace Devices;
    using namespace Value;
    
    std::cout << "Demonstration of ampermeter\n";
    
    Ampermeter ammeter(0.0, 10.0, 1.5, "A-001");
    auto result = ammeter.measure();
    
    std::cout << std::format("Ampermeter: {}\n", result);
    std::cout << "Current: " << result.getValue().getValue() << " A\n";
    std::cout << "Error: +/- " << result.getError() << " A\n\n";
}

void demo_voltmeter() {
    using namespace Devices;
    using namespace Value;
    
    std::cout << "Demonstration of voltmeter\n";
    
    Voltmeter voltmeter(0.0, 300.0, 1.0, "V-001");
    auto result = voltmeter.measure();
    
    std::cout << std::format("Voltmeter: {}\n", result);
    std::cout << "Voltage: " << result.getValue().getValue() << " V\n";
    std::cout << "Error: +/- " << result.getError() << " V\n\n";
}

void demo_multimeter() {
    using namespace Devices;
    using namespace Value;
    
    std::cout << "Demonstratoin of multimeter\n";
    
    Multimeter multimeter(0.0, 100.0, 2.5, "M-001");
    
    auto voltage_result = multimeter.measure<Volt>();
    std::cout << std::format("Multimeter (V): {}\n", voltage_result);
    
    auto current_result = multimeter.measure<Amper>();
    std::cout << std::format("Multimeter (A): {}\n", current_result);
    
    std::cout << "\n";
}

int main() {
    try {
        demo_values();
        demo_ampermeter();
        demo_voltmeter();
        demo_multimeter();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    
    return 0;
}