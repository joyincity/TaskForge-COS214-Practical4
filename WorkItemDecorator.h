#ifndef WORKITEMDECORATOR_H
#define WORKITEMDECORATOR_H

#include "ResponseWorkItem.h"

class WorkItemDecorator: public ResponseWorkItem{
    protected:
        ResponseWorkItem* wrappedItem;
    public:
        WorkItemDecorator(ResponseWorkItem* item);
        virtual ~WorkItemDecorator();
        virtual void execute() override;
        virtual std::string getStatus() const override;
        virtual WorkItemIterator* createIterator() override;
};

#endif //WORKITEMDECORATOR_H