#include "ResponseTask.h"
#include "ReportedState.h"

ResponseTask::ResponseTask() : currentState(new ReportedState()) {}

ResponseTask::~ResponseTask() {
    delete currentState;
}

void ResponseTask::setState(TaskState* state) {
    if (currentState != state) {
        delete currentState;
        currentState = state;
    }
}

std::string ResponseTask::getStatus() const {
    return currentState ? currentState->getName() : "Unknown";
}

void ResponseTask::dispatch() {
    if (currentState) currentState->dispatch(this);
}

void ResponseTask::beginOperation() {
    if (currentState) currentState->beginOperation(this);
}

void ResponseTask::complete() {
    if (currentState) currentState->complete(this);
}