// ProgramStateClass.tpp


template<typename StateType>

ProgramStateClass<StateType>::ProgramStateClass(StateType initialState)
        : prevState(initialState),
        currentState(initialState) {

        }

        // In constructor
template<typename StateType>

void ProgramStateClass<StateType>::setState(StateType newState) {
    prevState = currentState;
    currentState = newState;

    if (!callingOrder.empty() && callingOrder.back().first == newState) {
        callingOrder.back().second++;
    } else {
        callingOrder.push_back({newState, 1});
    }
}

template<typename StateType>
StateType ProgramStateClass<StateType>::getPrevState() const {
    return prevState;
}

template<typename StateType>
StateType ProgramStateClass<StateType>::getCurrentState() const {
    return currentState;
}

template<typename StateType>
const std::vector<std::pair<StateType, int>>& ProgramStateClass<StateType>::getCallingOrder() const {
    return callingOrder;
}
