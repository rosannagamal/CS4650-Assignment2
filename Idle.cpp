//
// Created by Rosanna Gamal on 02/04/2024.
//

#include "Idle.h"
#include "Walking.h"
#include "Jumping.h"

Idle::Idle(StateManager* state_manager) : State(state_manager) {}

void Idle::enter() {
    std::cout << "You're now in the idle state" << std::endl;
}

void Idle::update(char user_input) {

    switch (user_input) {
        case ' ':
            state_manager->go_to_state(new Jumping(state_manager));
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

void Idle::exit() {
    std::cout << "You're not in the idle state anymore" << std::endl;
}

void Idle::handle_timeout() {
    std::cout << "WHERE DO YOU WANT TO GOO?!\n" << "------------------------------" << std::endl;
}