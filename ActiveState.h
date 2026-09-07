#ifndef ACTIVESTATE_H
#define ACTIVESTATE_H

#include "TaskState.h"

class ActiveState : public TaskState {
public:
    void dispatch(ResponseTask* t) override;
    void beginOperation(ResponseTask* t) override;
    void complete(ResponseTask* t) override;
    std::string getName() const override;
};

#endif // ACTIVESTATE_H