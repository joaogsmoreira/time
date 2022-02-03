#ifndef _TIME_H_
#define _TIME_H_

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Timer {
public:
    Timer(std::string name) 
        : _name(name) {}
    inline void start(void) {
        _start = steady_clock::now();
    }
    inline void stop(bool print = false) {
        _stop = steady_clock::now();
        if (print) {
            this->print();
        }
    }
    inline void print(void) {
        cout << "Time elapsed by clock <" << _name << ">: " << duration_cast<seconds>(_stop - _start).count() << 
        " seconds" << endl;
    }
private:
    steady_clock::time_point _start, _stop;
    std::string _name;
};

#endif