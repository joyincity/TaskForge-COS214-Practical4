#ifndef ENROUTESTATE_H
#define ENROUTESTATE_H

#include "TaskState.h"

class EnRouteState : public TaskState {
public:
    void dispatch(ResponseTask* t) override;
    void beginOperation(ResponseTask* t) override;
    void complete(ResponseTask* t) override;
    std::string getName() const override;
};

#endif // ENROUTESTATE_H