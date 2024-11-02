#include <chrono>
#include <iostream>
#include <thread>

void runtime_thread() {
  std::cout << "Runtime thread started." << std::endl;

  for (;;) {
    // Simulate processing tasks or commands
    std::cout << "Runtime is executing a task..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }
}

void foo_impl() {}

int main() {
  // Start the runtime thread
  std::thread runtime(runtime_thread);

  // Main program can do other tasks here
  std::cout << "Server is running..." << std::endl;
  std::this_thread::sleep_for(
      std::chrono::seconds(3)); // Let main thread wait for 3 seconds

  // Wait for the runtime thread to finish
  if (runtime.joinable()) {
    runtime.join();
  }

  std::cout << "Server is running..." << std::endl;
}
