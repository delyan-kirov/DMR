
#include <iostream>
#include <sched.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

enum class ProcessState {
  EXECL_FAILED,
  FORK_FAILED,
};

pid_t start_process(const char *exec_path, const char *exec_name) {
  pid_t pid = fork(); // Create a new process

  if (pid == 0) {
    // This block is executed by the child process
    execl(exec_path, exec_name, nullptr); // Use nullptr for termination
    throw ProcessState::EXECL_FAILED;     // If exec fails
  } else if (pid < 0) {
    // Fork failed
    throw ProcessState::FORK_FAILED;
  }

  // Give the process some time to start
  sleep(1);
  return pid; // Return the child process ID
}

int main() {
  try {
    // Start the server process
    pid_t server_pid = start_process("./bin/server", "server");
    // Start the client process
    pid_t client_pid =
        start_process("./bin/client", "client"); // Correcting to client
    waitpid(server_pid, nullptr, 0);
    waitpid(client_pid, nullptr, 0);

  } catch (ProcessState state) {
    switch (state) {
    case ProcessState::FORK_FAILED: {
      std::cerr << "ERROR: fork failed\n";
      break;
    }
    case ProcessState::EXECL_FAILED: {
      std::cerr << "ERROR: execl failed\n";
      break;
    }
    }
    return 1;
  }

  return 0;
}
