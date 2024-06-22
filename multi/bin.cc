#include<iostream>
#include<thread>
#include<vector>

int main() {
	auto lambda = [](int x) {
		std::cout << "TID: " << std::this_thread::get_id() << std::endl;
		std::cout << "Item ID: " << x << std::endl;
	};
	// we can use jthread instead of thread in >= C++20
	std::vector<std::jthread> threads;
	for(int i = 0; i < 10; i++){
		threads.push_back(std::jthread(lambda, i));
	}	
	// so we don't have to multiple join()
//	for(int i = 0; i < 10; i++){
//		threads[i].join();
//	}	
	return 0;
}
