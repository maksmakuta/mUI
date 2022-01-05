#ifndef LOGGER_H
#define LOGGER_H

#include "../types.h"

class Log{
public:
    Log(){ /* ... */}

    static fun onError(const str& msg){
        cerr << "[ERROR  ] " << msg << "\n";
    }

    static fun onWarning(const str& msg){
        cout << "[WARNING] " << msg << "\n";
    }

    static fun onMessage(const str& msg){
        cout << "[MESSAGE] " << msg << "\n";
    }
};

#endif
