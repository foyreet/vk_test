#ifndef METRICS_COLLECTOR_H
#define METRICS_COLLECTOR_H

#include <string>
#include <fstream>
#include <ctime>
#include <iostream>

#include "CpuMetric.h"
#include "HttpRequestMetric.h"

class MetricsCollector {
private:
    CpuMetric cpuMetric;
    HttpRequestMetric httpMetric;

    std::string filename;

    std::string getCurrentTimestamp() {
        std::time_t rawtime;
        std::time(&rawtime);
        std::string ts = std::ctime(&rawtime);
        if (!ts.empty() && ts.back() == '\n') {
            ts.pop_back();
        }
        return ts;
    }

public:
    MetricsCollector(const std::string& outputFilename) {
        filename = outputFilename;
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
                << cpuMetric.getValueAsString();
        outFile << std::endl;

        outFile << timestamp << " "
                << httpMetric.getName() << " "
                << httpMetric.getValueAsString();
        outFile << std::endl;

        cpuMetric.reset();
        httpMetric.reset();

        outFile.close();
    }
};

#endif // METRICS_COLLECTOR_H
