#include "ActiveState.h"
#include "CompletedState.h"
#include "ResponseTask.h"
#include <iostream>

void ActiveState::dispatch(ResponseTask* t) {
    std::cout << "[Invalid Action] Cannot dispatch a task that is actively being executed.\n";
}

void ActiveState::beginOperation(ResponseTask* t) {
    std::cout << "[Invalid Action] Operation is already actively underway.\n";
}

void ActiveState::complete(ResponseTask* t) {
    std::cout << "[State Change] Operation completed successfully. Transitioning to CompletedState.\n";
    t->setState(new CompletedState());
}

std::string ActiveState::getName() const {
    return "Active";
}