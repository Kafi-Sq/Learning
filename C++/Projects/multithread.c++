#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <mutex>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;
mutex m;
int money = 0;

void findOdd(ull start, ull end) {
	for (ull i = start; i <= end; ++i) {
		if ((i & 1) == 1) {
			oddSum += i;
		}
	}
}

void findEven(ull start, ull end) {
	for (ull i = start; i <= end; ++i) {
		if ((i & 1) == 0) {
			evenSum += i;
		}
	}
}

void addMoney() {
	m.lock();
	money++;
	m.unlock();
}

int main() {
	ull start = 0, end = 1900000000;

	auto startTime = high_resolution_clock::now();

	thread t1(findEven, start, end);
	thread t2(findOdd, start, end);

	thread t3(addMoney);
	thread t4(addMoney);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	/*findOdd(start, end);
	findEven(start, end);*/

	auto stopTime = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stopTime - startTime);

	cout << oddSum << endl;
	cout << evenSum << endl;
	cout << money << endl;

	cout << duration.count() / 1000000 << " Secs." << endl;

	return 0;
}