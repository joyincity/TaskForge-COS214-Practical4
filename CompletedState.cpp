#include "CompletedState.h"
#include "ResponseTask.h"
#include <iostream>

void CompletedState::dispatch(ResponseTask* t) {
    std::cout << "[Invalid Action] Cannot dispatch a completed task.\n";
}

void CompletedState::beginOperation(ResponseTask* t) {
    std::cout << "[Invalid Action] Cannot begin operation on an already completed task.\n";
}

void CompletedState::complete(ResponseTask* t) {
    std::cout << "[Invalid Action] Task is already completed.\n";
}

std::string CompletedState::getName() const {
    return "Completed";
}