#include "WorkItemIterator.h"

FullOperationalSweepIterator::FullOperationalSweepIterator(ResponseWorkItem* root){
    currentIndex=0;
}
FullOperationalSweepIterator::~FullOperationalSweepIterator(){

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

       }
       MedicalPriorityIterator:: ~MedicalPriorityIterator(){
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