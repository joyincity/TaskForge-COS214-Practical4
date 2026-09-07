#include "WorkItemIterator.h"
#include "ResponseWorkItem.h"

FullOperationalSweepIterator::FullOperationalSweepIterator(ResponseWorkItem* root){
    currentIndex=0;
    if(root!=nullptr){
        root->doFullSweep(this);
    }
}
FullOperationalSweepIterator::~FullOperationalSweepIterator(){

}
    void FullOperationalSweepIterator:: visitLeaf(ResponseWorkItem* leaf){
    traversal.push_back(leaf);
}
void FullOperationalSweepIterator::visitGroup(IncidentGroup* group){
    traversal.push_back(group);
    std::vector<ResponseWorkItem*>:: iterator iterator;
    for(iterator = group->children.begin(); iterator != group->children.end(); ++iterator){
        (*iterator)->doFullSweep(this);
    }


}
        void FullOperationalSweepIterator:: first(){
            currentIndex=0;
        }
        bool FullOperationalSweepIterator::  hasNext(){
            if(currentIndex<traversal.size()){
                return true;
            }
            return false;
        }
        void FullOperationalSweepIterator:: next(){
            ++currentIndex;
        }
        ResponseWorkItem* FullOperationalSweepIterator:: current(){
            if(currentIndex<traversal.size()){
                return traversal[currentIndex];
            }else{
                return nullptr;
            }
        }

       MedicalPriorityIterator:: MedicalPriorityIterator(ResponseWorkItem* root){
            currentIndex =0;
            if(root!=nullptr){
                root->doMedicalSweep(this);
            }

       }
       MedicalPriorityIterator:: ~MedicalPriorityIterator(){
       }
       void MedicalPriorityIterator::visitNonMedical(ResponseWorkItem* node) {

}

       void MedicalPriorityIterator:: visitMedical(MedicalTask* task){
           priority.push_back(task);
       }
        void MedicalPriorityIterator:: visitGroup(IncidentGroup* group){
          std::vector<ResponseWorkItem*>:: iterator iterator;
           for(iterator = group->children.begin(); iterator != group->children.end(); ++iterator){
               (*iterator)->doMedicalSweep(this);
           }
       }
        void MedicalPriorityIterator:: first(){
            currentIndex =0;
        }
        bool MedicalPriorityIterator:: hasNext(){
            if(currentIndex<priority.size()){
                return true;
            }
            return false;
        }
        void MedicalPriorityIterator::  next(){
            ++currentIndex;
        }
        ResponseWorkItem*MedicalPriorityIterator:: current(){
            if(currentIndex<priority.size()){
                return priority[currentIndex];
            }else{
                return nullptr;
            }
        }

        
