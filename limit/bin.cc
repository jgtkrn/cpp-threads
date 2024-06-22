#include <iostream>
#include <thread>
#include <vector>

void thread_spawner() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main() {
    std::vector<std::thread> threads;
    try {
        while (true) {
            threads.push_back(std::thread(thread_spawner));
            std::cout << "Thread " << threads.size() << " created" << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        std::cerr << "Failed to create more threads after " << threads.size() << " threads." << std::endl;
    }

    for (auto &t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    return 0;
}
