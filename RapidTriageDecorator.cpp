#include "RapidTriageDecorator.h"
#include <iostream>

RapidTriageDecorator::RapidTriageDecorator(ResponseWorkItem* item): WorkItemDecorator(item){}

RapidTriageDecorator::~RapidTriageDecorator(){}

void RapidTriageDecorator::execute(){
    std::cout << "Rapid Triage: Prioritising critical patients" << std::endl;
    wrappedItem->execute();
}