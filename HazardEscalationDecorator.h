#ifndef HAZRDESCALATIONDECORATOR_H
#define HAZRDESCALATIONDECORATOR_H

#include "WorkItemDecorator.h"

class HazardEscalationDecorator: public WorkItemDecorator{
    public:
        HazardEscalationDecorator(ResponseWorkItem* item);
        virtual ~HazardEscalationDecorator();
        virtual void execute() override;
};

#endif //HAZRDESCALATIONDECORATOR_H