#include<iostream>
#include<chrono>
#include<thread>
#include<algorithm>
typedef unsigned long long ull;

ull even_count = 0;
ull odd_count = 0;

void even_counter(ull start, ull end){
	for(ull i = start; i <= end; ++i){
		if((i & 1) == 0) even_count++;
	}
}

void odd_counter(ull start, ull end){
	for(ull i = start; i <= end; ++i) {
		if((i & 1) == 1) odd_count++;
	}
}

int main(){
	ull start = 0;
	ull end = 190000000;
	auto start_time = std::chrono::high_resolution_clock::now();
	std::thread t1([start, end] {even_counter(start, end);});
	std::thread t2([start, end] {odd_counter(start, end);});
	t1.join();
	t2.join();
//	even_counter(start, end);
//	odd_counter(start, end);
	auto stop_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop_time - start_time);
	std::cout << "----Even and Odd Summary----\n";
	std::cout << "--Start: " << start << std::endl;
	std::cout << "--End: " << end << std::endl;
	std::cout << "--Even Count: " << even_count << std::endl;
	std::cout << "--Odd Count: " << odd_count << std::endl;
	std::cout << "--Time Usage: " << duration.count()/1000 << std::endl;

	return 0;
}
