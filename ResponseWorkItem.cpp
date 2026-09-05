#include "ResponseWorkItem.h"

//constructor
ResponseWorkItem::ResponseWorkItem(const std::string& name): name(name){}

//destructor
ResponseWorkItem::~ResponseWorkItem(){
    //nothing ithink
}

std::string ResponseWorkItem::getName() const{
    return name;
}