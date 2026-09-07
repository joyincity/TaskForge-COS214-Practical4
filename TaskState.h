#ifndef TASKSTATE_H
#define TASKSTATE_H

#include <string>

class ResponseTask;

class TaskState {
public:
    virtual ~TaskState() = default;

    virtual void dispatch(ResponseTask* t) = 0;
    virtual void beginOperation(ResponseTask* t) = 0;
    virtual void complete(ResponseTask* t) = 0;
    virtual std::string getName() const = 0;
};

#endif // TASKSTATE_H