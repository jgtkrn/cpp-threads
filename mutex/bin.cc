#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

std::mutex mtx;

int count_thread_sum = 0;

void run(int count) {
	while(count-- > 0) {
		// instead using lock unlock, let's use mutex lock guard
		std::lock_guard<std::mutex> lock(mtx); // this will lock until out of scope
		count_thread_sum++;
//		if(mtx.try_lock()){
//			mtx.lock();
//			mtx.unlock();	
//		}
		std::cout << "count thread sum: " << count_thread_sum << std::endl;
	}
}

int main() {
	int c_loop = 20;
	std::cout << "start\n";
	std::thread t1([c_loop] { run(c_loop); });
	std::thread t2([c_loop] { run(c_loop); });
	if(t1.joinable()) t1.detach();
	if(t2.joinable()) t2.detach();	
	std::cout << "count thread sum in main: " << count_thread_sum << std::endl;
	std::cout << "end\n";
	while(1){}
	return 0;
}
