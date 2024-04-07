//
// Created by Rosanna Gamal on 02/04/2024.
//

#include "StateManager.h"
#include "State.h"

StateManager::StateManager() : current_state(nullptr) {}

StateManager::~StateManager() {
    if (current_state != nullptr) {
        current_state->exit();
        delete current_state;
    }
}

void StateManager::update(char user_input) {
    if (current_state != nullptr) {
        current_state->update(user_input);
    }
}

void StateManager::go_to_state(State* state) {
    if (current_state != nullptr) {
        current_state->exit();
        delete current_state;
    }
    current_state = state;
    if (current_state != nullptr) {
        current_state->enter();
    }
}

void StateManager::timeout() {
    if (current_state != nullptr) {
        std::cout << "------------------------------" << std::endl;
        current_state->handle_timeout();
    }
}