#include<iostream>
#include<thread>
#include<chrono>

int count_thread_sum = 0;

void run(int count) {
	while(count-- > 0) {
		std::cout << "N: " << count << " ----Test Join Detach----\n";
		count_thread_sum++;
		std::cout << "count thread sum: " << count_thread_sum << std::endl;
	}
	std::this_thread::sleep_for(std::chrono::seconds(3));
}

int main() {
	int c_loop = 10;
	std::cout << "join() start\n";
	std::thread t1([c_loop] { run(c_loop); });
	if(t1.joinable()) t1.join();
	std::cout << "join() end\n";
	std::cout << "count thread sum: " << count_thread_sum << std::endl;
	std::cout << "detach() start\n";
	std::thread t2([c_loop] { run(c_loop); });
	if(t2.joinable()) t2.detach();
	std::cout << "detach() end\n";
	while(1){}
	return 0;
}
