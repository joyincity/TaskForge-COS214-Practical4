#ifndef RESPONSEWORKITEM_H
#define RESPONSEWORKITEM_H

//component
#include <string>
class WorkItemIterator;

class ResponseWorkItem{
    protected:
        std::string name;
    public:
        ResponseWorkItem(const std::string& name);
        virtual ~ResponseWorkItem();
        virtual void execute() = 0;
        virtual std::string getStatus() const = 0;
        virtual WorkItemIterator* createIterator() = 0;
        std::string getName() const;
};

#endif //RESPONSEWORKITEM_H