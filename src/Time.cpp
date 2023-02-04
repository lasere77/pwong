#include "../include/Time.hpp"
#include <thread>
#include <iostream>

int timers = 0;
bool threadAction = false;
bool runningThread = true;


void timer() { 
    using namespace std::literals::chrono_literals;
    while (runningThread) {
        if(threadAction) {
            std::this_thread::sleep_for(1s);
            timers++;
        }
    }
    std::cout << "thread dead" << std::endl;
}

int getTime() {
    return timers;
}

void setThreadAction(bool run) {
    threadAction = run;
}

void killThread() {
    runningThread = false;
}