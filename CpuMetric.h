#ifndef CPU_METRIC_H
#define CPU_METRIC_H

#include <string>
#include <sstream>
#include <iomanip>

class CpuMetric {
private:
    std::string name;
    double currentValue;

public:
    CpuMetric() {
        name = "CPU";
        currentValue = 0.0;
    }

    void setUtilization(double utilization) {
        currentValue = utilization;
    }

    std::string getName() const {
        return name;
    }

    std::string getValueAsString() const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << currentValue;
        return oss.str();
    }

    std::string getDescription() const {
        return "";
    }

    void reset() {
        currentValue = 0.0;
    }
};

#endif // CPU_METRIC_H
