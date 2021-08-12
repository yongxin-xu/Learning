#include <iostream>
#include <chrono>

class Timer {
public:
    Timer() {
        m_startTimePoint = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        stop();
    }

private:
    void stop() {
        auto endTimePoint = std::chrono::high_resolution_clock::now(); 

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimePoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

        auto duration = end - start;
        double ms = duration * 0.001;

        std::cout << duration << " us (" << ms << "ms)\n"; 
    }
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimePoint;
};

int main() {
    int value = 0;
    {
        Timer timer;
        for (int i = 0; i < 200000; i++) {
            value += 3;
        }
    }
    std::cout << "Value; " << value << "\n";

    return 0;
}