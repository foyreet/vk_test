#include <iostream>
#include <cstdlib>
#include <ctime>

#include "MetricsCollector.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));

    MetricsCollector myAppMetrics("my_simple_app_metrics.log");

    myAppMetrics.getCpuMetric().setUtilization(0.65 + (rand() % 20 / 100.0));
    myAppMetrics.getHttpRequestMetric().incrementCount(rand() % 50 + 1);
    myAppMetrics.writeMetricsToFile();

    myAppMetrics.getCpuMetric().setUtilization(0.20 + (rand() % 15 / 100.0));
    myAppMetrics.getHttpRequestMetric().incrementCount(rand() % 30 + 5);
    myAppMetrics.writeMetricsToFile();

    return 0;
}
