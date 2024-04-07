//
// Created by Rosanna Gamal on 02/04/2024.
//

#ifndef CS4650_A2_STATEMANAGER_H
#define CS4650_A2_STATEMANAGER_H

#include <iostream>

class State;

class StateManager {
private:
    State* current_state;

public:
    StateManager();
    ~StateManager();

    void update(char user_input);
    void go_to_state(State* state);
    void timeout();
};
#endif //CS4650_A2_STATEMANAGER_H
