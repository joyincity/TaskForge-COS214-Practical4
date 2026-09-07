#ifndef WORKITEMITERATOR
#define WORKITEMITERATOR

#include <vector>

 class ResponseWorkItem;
 class IncidentGroup;
 class MedicalTask;

class WorkItemIterator{
    public:
        virtual ~WorkItemIterator(){};
        virtual void first()=0;
        virtual bool hasNext() =0;
        virtual void next() =0;
        virtual ResponseWorkItem* current()=0;


};
class FullOperationalSweepIterator: public WorkItemIterator{
    private:
        std::vector<ResponseWorkItem*> traversal;
        std::size_t currentIndex;
        
    public:
        FullOperationalSweepIterator(ResponseWorkItem* root);
        ~FullOperationalSweepIterator();
        void first();
        bool hasNext();
        void next();
        ResponseWorkItem* current();
        void visitLeaf(ResponseWorkItem* leaf);
        void visitGroup(IncidentGroup* group);

};
class MedicalPriorityIterator: public WorkItemIterator{
    private:
        std::vector<ResponseWorkItem*> priority;
        std::size_t currentIndex;
        
        

    public:
        MedicalPriorityIterator(ResponseWorkItem* root);
        ~MedicalPriorityIterator();
        void first();
        bool hasNext();
        void next();
        ResponseWorkItem* current();
        void visitNonMedical(ResponseWorkItem* node);
        void visitMedical(MedicalTask* task);
        void visitGroup(IncidentGroup* group);
        
};

#endif