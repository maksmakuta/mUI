#ifndef LOGGER_H
#define LOGGER_H

#include <utils/TypeUtils.h>
#include <string>

class Log{
public:
    static fun onMessage(const std::string& msg);
    static fun onError(const std::string& msg);
    static fun onLog(const std::string& msg);
};

#endif // LOGGER_H
