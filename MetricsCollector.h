#ifndef METRICS_COLLECTOR_H
#define METRICS_COLLECTOR_H

#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

#include "CpuMetric.h"
#include "HttpRequestMetric.h"

class MetricsCollector {
private:
    CpuMetric cpuMetric;
    HttpRequestMetric httpMetric;

    std::string filename;

    std::string getCurrentTimestamp() {
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S");
        
        return ss.str();
    }

public:
    MetricsCollector(const std::string& outputFilename) : filename(outputFilename) {
    }

    CpuMetric& getCpuMetric() {
        return cpuMetric;
    }

    HttpRequestMetric& getHttpRequestMetric() {
        return httpMetric;
    }

    void writeMetricsToFile() {
        std::ofstream outFile(filename, std::ios_base::app);
        
        if (!outFile.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return;
        }

        std::string timestamp = getCurrentTimestamp();

        outFile << timestamp << " "
                << cpuMetric.getName() << " "
                << cpuMetric.getValueAsString()
                << std::endl;

        outFile << timestamp << " "
                << httpMetric.getName() << " "
                << httpMetric.getValueAsString()
                << std::endl;

        cpuMetric.reset();
        httpMetric.reset();

        outFile.close();
    }
};

#endif // METRICS_COLLECTOR_H
