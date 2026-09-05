#ifndef RAPIDTRIAGEDECORATOR_H
#define RAPIDTRIAGEDECORATOR_H

#include "WorkItemDecorator.h"

class RapidTriageDecorator: public WorkItemDecorator{
    public:
        RapidTriageDecorator(ResponseWorkItem* item);
        virtual ~RapidTriageDecorator();
        virtual void execute() override;
};

#endif //RAPIDTRIAGEDECORATOR_H