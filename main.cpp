#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <ctime>

bool start = false;
auto curr_time = time(NULL);
int count = 0;

using namespace std::chrono_literals;
void task(int n) {
	while (!start) {}
	while (time(NULL) < curr_time + 5) {}
	for (count = 0; count < 200; count++) {
		std::cout << n;
		std::this_thread::sleep_for(100ms);
	}
}

int main()
{
	std::vector<std::thread> threads;
	for (int i = 0; i < 200; i++) {
		threads.emplace_back(task, i%10);
	}

	curr_time = time(NULL);
	start = true;

	for (auto& t : threads) {
		t.join();
	}

	return 0;
}


