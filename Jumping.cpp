//
// Created by Rosanna Gamal on 02/04/2024.
//

#include "Jumping.h"
#include "Idle.h"
#include "Walking.h"

Jumping::Jumping(StateManager *state_manager) : State(state_manager) {}

void Jumping::enter() {
    std::cout << "You're now jumping" << std::endl;
}

void Jumping::update(char user_input) {
    switch (user_input) {
        case ' ':
            std::cout << "You're still jumping" << std::endl;
            break;
        case 'w':
        case 'W':
            state_manager->go_to_state(new Walking(state_manager));
            break;
        default:
            std::cout << "Wrong input :(" << std::endl;
            break;
    }
}

void Jumping::exit() {
    std::cout << "You're not jumping anymore" << std::endl;
}

void Jumping::handle_timeout() {
    std::cout << "You're taking too long!!\n" << "------------------------------" << std::endl;
    state_manager->go_to_state(new Idle(state_manager));
}