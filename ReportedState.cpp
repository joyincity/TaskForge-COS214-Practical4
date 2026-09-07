#include "ReportedState.h"
#include "EnRouteState.h"
#include "ResponseTask.h"
#include <iostream>

void ReportedState::dispatch(ResponseTask* t) {
    std::cout << "[State Change] Task dispatched. Transitioning to EnRouteState.\n";
    t->setState(new EnRouteState());
}

void ReportedState::beginOperation(ResponseTask* t) {
    std::cout << "[Invalid Action] Cannot begin operation while task is still in ReportedState.\n";
}

void ReportedState::complete(ResponseTask* t) {
    std::cout << "[Invalid Action] Cannot complete task directly from ReportedState.\n";
}

std::string ReportedState::getName() const {
    return "Reported";
}