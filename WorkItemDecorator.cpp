#include "WorkItemDecorator.h"

//constr
WorkItemDecorator::WorkItemDecorator(ResponseWorkItem* item):ResponseWorkItem(item->getName()), wrappedItem(item){}

//destr
WorkItemDecorator::~WorkItemDecorator(){
    delete wrappedItem;
}

void WorkItemDecorator::execute(){
    wrappedItem->execute();
}

std::string WorkItemDecorator::getStatus() const{
    return wrappedItem->getStatus();
}

WorkItemIterator* WorkItemDecorator::createIterator(){
    return wrappedItem->createIterator();
}