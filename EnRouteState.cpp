#include "EnRouteState.h"
#include "ActiveState.h"
#include "ResponseTask.h"
#include <iostream>

void EnRouteState::dispatch(ResponseTask* t) {
    std::cout << "[Invalid Action] Task is already dispatched and en route.\n";
}

void EnRouteState::beginOperation(ResponseTask* t) {
    std::cout << "[State Change] Arrived at scene. Transitioning to ActiveState.\n";
    t->setState(new ActiveState());
}

void EnRouteState::complete(ResponseTask* t) {
    std::cout << "[Invalid Action] Cannot complete task while units are still en route.\n";
}

std::string EnRouteState::getName() const {
    return "EnRoute";
}