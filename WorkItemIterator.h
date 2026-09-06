#ifndef WORKITEMITERATOR
#define WORKITEMITERATOR

#include <vector>

 class ResponseWorkItem;

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
        int currentIndex;
    public:
        FullOperationalSweepIterator(ResponseWorkItem* root);
        ~FullOperationalSweepIterator();
        void first();
        bool hasNext();
        void next();
        ResponseWorkItem* current();

};
class MedicalPriorityIterator: public WorkItemIterator{
    private:
        std::vector<ResponseWorkItem*> priority;
        int currentIndex;

    public:
        MedicalPriorityIterator(ResponseWorkItem* root);
        ~MedicalPriorityIterator();
        void first();
        bool hasNext();
        void next();
        ResponseWorkItem* current();
};

#endif