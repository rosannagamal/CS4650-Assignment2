//
// Created by Rosanna Gamal on 02/04/2024.
//

#ifndef CS4650_A2_STATE_H
#define CS4650_A2_STATE_H

#include <iostream>
#include "StateManager.h"

class State {
protected:
    StateManager* state_manager;

public:
    State(StateManager* state_manager) {
        this->state_manager = state_manager;
    }

    virtual ~State() {};
    virtual void enter() = 0;
    virtual void update(char user_input) = 0;
    virtual void exit() = 0;
    virtual void handle_timeout() = 0;
};
#endif //CS4650_A2_STATE_H
