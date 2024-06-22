#include<iostream>
#include<vector>
#include<thread>
#include<atomic>

static std::atomic<int> val = 0;

//static int val = 0;

void increment_val() {
	val++;
}

int main() {
	std::vector<std::thread> threads;
	int len = 100000;
	for(int i = 0; i < len; i++){
		threads.push_back(std::thread(increment_val));
	}
	for(int i = 0; i < len; i++){
		if(threads[i].joinable()) threads[i].join();
	}
	std::cout << "val: " << val << std::endl;
	return 0;
}
