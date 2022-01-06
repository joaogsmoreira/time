#ifndef _TIME_H_
#define _TIME_H_

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Timer {
public:
    Timer(std::string name) {
        _name = name;
    };
    inline void start(void) {
        _start = high_resolution_clock::now();
    }
    inline void stop(void) {
        _stop = high_resolution_clock::now();
    }
    inline void print(void) {
        cout << "Time elapsed by clock " << _name << " : " << duration_cast<microseconds>(_stop - _start).count() << 
        " microseconds" << endl;
    }
private:
    high_resolution_clock::time_point _start, _stop;
    std::string _name;
};

#endif