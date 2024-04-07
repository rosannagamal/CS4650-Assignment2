//
// Created by Rosanna Gamal on 02/04/2024.
//

#include "Walking.h"
#include "Idle.h"
#include "Jumping.h"

Walking::Walking(StateManager *state_manager) : State(state_manager) {}

void Walking::enter() {
    std::cout << "You're now walking" << std::endl;
}

void Walking::update(char user_input) {
    switch (user_input) {
        case ' ':
            state_manager->go_to_state(new Jumping(state_manager));
            break;
        case 'w':
        case 'W':
            std::cout << "You're still walking" << std::endl;
            break;
        default:
            std::cout << "Wrong input :(" << std::endl;
            break;
    }
}

void Walking::exit() {
    std::cout << "You're not walking anymore" << std::endl;
}

void Walking::handle_timeout() {
    std::cout << "You're taking too long!!\n" << "------------------------------" << std::endl;
    state_manager->go_to_state(new Idle(state_manager));
}
