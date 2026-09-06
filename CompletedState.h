#ifndef COMPLETEDSTATE_H
#define COMPLETEDSTATE_H

#include "TaskState.h"

class CompletedState : public TaskState {
public:
    void dispatch(ResponseTask* t) override;
    void beginOperation(ResponseTask* t) override;
    void complete(ResponseTask* t) override;
    std::string getName() const override;
};

#endif // COMPLETEDSTATE_H