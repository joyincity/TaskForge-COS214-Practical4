#ifndef RESPONSETASK_H
#define RESPONSETASK_H

#include "TaskState.h"

class ResponseTask {
private:
    TaskState* currentState;

public:
    ResponseTask();
    virtual ~ResponseTask();

    void setState(TaskState* state);
    std::string getStatus() const;

    void dispatch();
    void beginOperation();
    void complete();
};

#endif // RESPONSETASK_H