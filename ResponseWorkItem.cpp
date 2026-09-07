#include "ResponseWorkItem.h"
#include "WorkItemIterator.h"


void ResponseWorkItem:: doFullSweep(FullOperationalSweepIterator* it){
    it->visitLeaf(this);
}
void ResponseWorkItem::doMedicalSweep(MedicalPriorityIterator*it){
    it->visitNonMedical(this);
}

 IncidentGroup::IncidentGroup(const std::string& n){
    name =n;
 }
        
        IncidentGroup::~IncidentGroup(){
             std::vector<ResponseWorkItem*>:: iterator iterator;
    for(iterator = children.begin(); iterator!= children.end(); ++iterator){
        delete *iterator;}
        }
        void IncidentGroup:: add(ResponseWorkItem* item){
            if(item== nullptr){
         return;
        }
        children.push_back(item);
        }
        void IncidentGroup:: remove(ResponseWorkItem* item){
             std::vector<ResponseWorkItem*>:: iterator iterator;
    for(iterator = children.begin(); iterator!= children.end(); ++iterator){
        if(*iterator ==item){
            children.erase(iterator);return; 
        }
    }

        }
        void IncidentGroup:: execute() {
            std::cout << "Executing Incident: " << name << std::endl;
    
    if (children.empty()) {
        std::cout << "Nothing available to execute" << std::endl;
        return;
    }
    std::vector<ResponseWorkItem*>::iterator iterator;
    for (iterator = children.begin(); iterator != children.end(); ++iterator) {
        (*iterator)->execute();
    }

        }
        void IncidentGroup:: getStatus() {
            if(children.empty()==true){
                std::cout<<"No status available at this moment"<<std::endl;
                return;
            }
            std::cout<<name<<" has "<<children.size()<<" tasks "<<std::endl;
            std::vector<ResponseWorkItem*>:: iterator iterator;
    for(iterator = children.begin(); iterator!= children.end(); ++iterator){
        std::cout<<" ["<<(*iterator)->getName()<< " : ";
        (*iterator)->getStatus();
        std::cout<<" ]"<<std::endl;
    }

           
    }
        
        std::string IncidentGroup:: getName()const{
            return name;
        }
        WorkItemIterator* IncidentGroup:: createIterator(){
            return new FullOperationalSweepIterator(this);
        }
        void IncidentGroup:: doFullSweep(FullOperationalSweepIterator*it){
            it->visitGroup(this);
        }
        void IncidentGroup:: doMedicalSweep(MedicalPriorityIterator* it){
            it->visitGroup(this);
        }
        ResponseTask::ResponseTask(const std::string& n){
            name =n;
        }
       

        void ResponseTask:: setState(TaskState* state){
          
        }
        TaskState* ResponseTask:: getState(){
            return currrentState;
        }
        void ResponseTask:: dispatch(){

        }
        void ResponseTask:: beginOperation(){

        }
        void ResponseTask:: complete(){

        }
        void ResponseTask::  execute() {
           
            
        }
        void ResponseTask:: getStatus(){
            if (currrentState!=nullptr) {
        std::cout << currrentState->getName();
         } else {
        std::cout << "status unkonwn";
            }
        }
        std::string ResponseTask:: getName() const{
            return name;
        }
        WorkItemIterator*ResponseTask:: createIterator() {
            return new FullOperationalSweepIterator(this);
        }

         RescueTask::RescueTask(const std::string& n):ResponseTask(n){

         }
        RescueTask::~RescueTask(){}
        void RescueTask::execute(){
            ResponseTask::execute();
            std::cout<<"Performing rescue tasks"<<std::endl;
        }
        void RescueTask:: searchArea(){
            std::cout<<"Searching Area"<<std::endl;
        }
        void RescueTask:: extractVictim(){
            std::cout<<"Extracting victim"<<std::endl;
        }
        MedicalTask::MedicalTask(const std::string& n):ResponseTask(n){
            
        }
        MedicalTask::~MedicalTask(){

        }
        void MedicalTask:: execute(){
            ResponseTask::execute();
            std::cout<<"Performing medical tasks"<<std::endl;
        }
        void MedicalTask:: assessPatient(){
            std::cout<<"assessing patient"<<std::endl;
        }
        void MedicalTask:: stabilizePatient(){
            std::cout<<"stabilizing patient"<<std::endl;
        }
        void MedicalTask:: transportPatient(){
            std::cout<<"transporting patient"<<std::endl;
        }
        void MedicalTask::doMedicalSweep(MedicalPriorityIterator* it){
            it->visitMedical(this);
        }