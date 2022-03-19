// workshop 04.19
#include <iostream>
#include <thread>
#include <vector>
#include <sstream>

int counter {0};

void task(int s) {
    int counter_l = 0;
    std::stringstream ss;
    ss << "begin thread " << s << ": counter_l = " << counter_l << ", counter = " << counter << std::endl;
    std::cout << ss.str();
	for (int i = 0; i < 100'000; ++i)
    {
        ++counter;
        ++counter_l;
        if(i == 50'000)
        {
            ss.str("");
            ss << "mid thread " << s << ": counter_l = " << counter_l << ", counter = " << counter << std::endl;
            std::cout << ss.str();
        }
    }
    ss.str("");
    ss << "end thread " << s << ": counter_l = " << counter_l << ", counter = " << counter << std::endl;
    std::cout << ss.str();
}

int main() {
	std::vector<std::thread> tasks;
	for (int i = 0; i < 10; ++i) tasks.push_back(std::thread{task, i});
	for (auto& t: tasks) t.join();
	std::cout << counter << std::endl;
}
