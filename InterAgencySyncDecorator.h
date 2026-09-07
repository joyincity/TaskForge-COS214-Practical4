#ifndef INTERAGENCYSYNCDecorator_H
#define INTERAGENCYSYNCDecorator_H

#include "WorkItemDecorator.h"

class InterAgencySyncDecorator: public WorkItemDecorator{
    public:
        InterAgencySyncDecorator(ResponseWorkItem* item);
        virtual ~InterAgencySyncDecorator();
        virtual void execute() override;
};

#endif //INTERAGENCYSYNCDecorator_H