#include <iostream>
#include <cstdlib>
#include <ctime>

#include "MetricsCollector.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));

    MetricsCollector myAppMetrics("my_simple_app_metrics.log");

    std::cout << "Starting basic metric collection...\n";

    std::cout << "\n--- Setting first metric values ---\n";
    
    myAppMetrics.getCpuMetric().setUtilization(0.65 + (rand() % 20 / 100.0));
    std::cout << "CPU updated to: " << myAppMetrics.getCpuMetric().getValueAsString() << std::endl;

    myAppMetrics.getHttpRequestMetric().incrementCount(rand() % 50 + 1);
    std::cout << "HTTP requests updated to: " << myAppMetrics.getHttpRequestMetric().getValueAsString() << std::endl;

    std::cout << "\n--- Writing metrics to file (first time) ---\n";
    myAppMetrics.writeMetricsToFile();
    std::cout << "Metrics written. Check 'my_simple_app_metrics.log'\n";

    std::cout << "\n--- Setting new metric values (after reset) ---\n";
    
    myAppMetrics.getCpuMetric().setUtilization(0.20 + (rand() % 15 / 100.0));
    std::cout << "CPU updated to: " << myAppMetrics.getCpuMetric().getValueAsString() << std::endl;

    myAppMetrics.getHttpRequestMetric().incrementCount(rand() % 30 + 5);
    std::cout << "HTTP requests updated to: " << myAppMetrics.getHttpRequestMetric().getValueAsString() << std::endl;

    std::cout << "\n--- Writing metrics to file (second time) ---\n";
    myAppMetrics.writeMetricsToFile();
    std::cout << "Metrics written again. Check 'my_simple_app_metrics.log'\n";

    std::cout << "\nProgram finished.\n";

    return 0;
}
