#include "InterAgencySyncDecorator.h"
#include <iostream>

InterAgencySyncDecorator::InterAgencySyncDecorator(ResponseWorkItem* item): WorkItemDecorator(item){}

InterAgencySyncDecorator::~InterAgencySyncDecorator(){}

//this merges with other emergency response 'agencies' such as the police
void InterAgencySyncDecorator::execute(){
    std::cout << "Inter-Agency Sync in progress, coordinating with partner agencies." << std::endl;
    wrappedItem->execute();
}