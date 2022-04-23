#include <utils/Logger.h>
#include <iostream>

fun Log::onMessage(const std::string& msg){
    std::cout << "[MESSAGE]: " << msg << std::endl;
}
fun Log::onError(const std::string& msg){
    std::cerr << "[ERROR]  : " << msg << std::endl;
}
fun Log::onLog(const std::string& msg){
    std::cout << "[LOG]    : " << msg << std::endl;
}
