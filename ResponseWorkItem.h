#ifndef RESPONSEWORKITEM_H
#define RESPONSEWORKITEM_H

//component
#include <string>
class WorkItemIterator;

class ResponseWorkItem{
    protected:
        std::string name;
    public:
        ResponseWorkItem(const std::string& name);
        virtual ~ResponseWorkItem();
        virtual void execute() = 0;
        virtual std::string getStatus() const = 0;
        virtual WorkItemIterator* createIterator() = 0;
        std::string getName() const;
};

#endif //RESPONSEWORKITEM_H
#ifndef RESPONSEWORKITEM
#define RESPONSEWORKITEM
#include<iostream>
#include <vector>
#include <string>

class TaskState;
class WorkItemIterator;
class FullOperationalSweepIterator;
class MedicalPriorityIterator;

class ResponseWorkItem{
    
    public: 
    virtual ~ResponseWorkItem(){};
     virtual void execute() =0;
     virtual void getStatus()=0;
     virtual std::string getName()const =0;
     virtual WorkItemIterator* createIterator()=0;
     virtual void doFullSweep(FullOperationalSweepIterator* it);
     virtual void doMedicalSweep(MedicalPriorityIterator*it);

};
class IncidentGroup: public ResponseWorkItem{
   friend class FullOperationalSweepIterator;
   friend class MedicalPriorityIterator;
    private:
     std::string name;
     std::vector<ResponseWorkItem*> children;
     

    public:
        IncidentGroup(const std::string& n);
       
        ~IncidentGroup();
        void add(ResponseWorkItem* item);
        void remove(ResponseWorkItem* item);
        void execute() override;
        void getStatus() override;
        std::string getName()const override;
        WorkItemIterator* createIterator() override;
        virtual void doFullSweep(FullOperationalSweepIterator* it)override;
     virtual void doMedicalSweep(MedicalPriorityIterator*it)override;



};
class ResponseTask: public ResponseWorkItem{
    private:
        std::string name;
        TaskState* currrentState;
    public:
        ResponseTask(const std::string& n);
        virtual ~ResponseTask(){};
        void setState(TaskState* state);
        TaskState* getState();
        void dispatch();
        void beginOperation();
        void complete();
        void execute() override;
        void getStatus() override;
        std::string getName()const override;
        WorkItemIterator* createIterator() override;
    

};
class RescueTask: public ResponseTask{
    
    public:
        RescueTask(const std::string& n);
        ~RescueTask();
        void execute() override;
        void searchArea();
        void extractVictim();
};
class MedicalTask: public ResponseTask{
    public:

        MedicalTask(const std::string& n);
        ~MedicalTask();
        void execute()override;
        void assessPatient();
        void stabilizePatient();
        void transportPatient();
     virtual void doMedicalSweep(MedicalPriorityIterator*it)override;

};
#endif
