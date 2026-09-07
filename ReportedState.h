#ifndef REPORTEDSTATE_H
#define REPORTEDSTATE_H

#include "TaskState.h"

class ReportedState : public TaskState {
public:
    void dispatch(ResponseTask* t) override;
    void beginOperation(ResponseTask* t) override;
    void complete(ResponseTask* t) override;
    std::string getName() const override;
};

#endif // REPORTEDSTATE_H