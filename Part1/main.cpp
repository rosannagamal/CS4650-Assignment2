#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
#include <limits>
#include "StateManager.h"
#include "Idle.h"

int main() {
    StateManager state_manager;
    state_manager.go_to_state(new Idle(&state_manager));

    std::atomic<bool> input_received(false);

    while (true) {
        input_received = false;

        std::thread timeout_thread([&state_manager, &input_received]() {
            for (int i = 0; i < 5; ++i) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                if (input_received) return;
            }
            state_manager.timeout();
        });

        if (std::cin.peek() != EOF) {
            char user_input = std::cin.get();
            // Since we have to use cin.get() to get space, we have to remove the new line
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            state_manager.update(user_input);
            input_received = true;
        }

        if (timeout_thread.joinable()) {
            timeout_thread.join();
        }
    }
}
