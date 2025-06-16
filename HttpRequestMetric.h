#ifndef HTTP_REQUEST_METRIC_H
#define HTTP_REQUEST_METRIC_H

#include <string>

class HttpRequestMetric {
private:
    std::string name;
    int requestCount;

public:
    HttpRequestMetric() {
        name = "HTTP requests RPS";
        requestCount = 0;
    }

    void incrementCount(int count = 1) {
        requestCount = requestCount + count;
    }

    std::string getName() const {
        return name;
    }

    std::string getValueAsString() const {
        return std::to_string(requestCount);
    }

    std::string getDescription() const {
        return "";
    }

    void reset() {
        requestCount = 0;
    }
};

#endif // HTTP_REQUEST_METRIC_H
