//
// Created by Rosanna Gamal on 02/04/2024.
//

#ifndef CS4650_A2_WALKING_H
#define CS4650_A2_WALKING_H

#include <iostream>
#include "State.h"
#include "StateManager.h"

class Walking : public State {
public:
    Walking(StateManager* state_manager);
    void enter() override;
    void update(char user_input) override;
    void exit() override;
    void handle_timeout() override;
};
#endif //CS4650_A2_WALKING_H
