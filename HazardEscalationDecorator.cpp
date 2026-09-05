#include "HazardEscalationDecorator.h"
#include <iostream>

HazardEscalationDecorator::HazardEscalationDecorator(ResponseWorkItem* item): WorkItemDecorator(item){}

HazardEscalationDecorator::~HazardEscalationDecorator(){}

void HazardEscalationDecorator::execute(){
    std::cout << "Hazard escalation in progress, applying hazard procedures." << std::endl;
    wrappedItem->execute();
}