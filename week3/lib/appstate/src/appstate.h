//
// Created by Alan Hu on 11/12/23.
//

#ifndef UCSC_APPSTATE_H
#define UCSC_APPSTATE_H

#include <vector>
#include <utility>

template<typename StateType>
class ProgramStateClass {
private:
    StateType prevState;
    StateType currentState;
    std::vector<std::pair<StateType, int>> callingOrder;

public:
    ProgramStateClass(StateType initialState);
    void setState(StateType newState);
    StateType getPrevState() const;
    StateType getCurrentState() const;
    const std::vector<std::pair<StateType, int>>& getCallingOrder() const;
};

#include "appstate.tpp" // Include the implementation

#endif //UCSC_APPSTATE_H
