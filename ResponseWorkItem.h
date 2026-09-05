#ifndef RESPONSEWORKITEM
#define RESPONSEWORKITEM
#include<iostream>
#include <vector>
#include <string>

class TaskState;
class WorkItemIterator;

class ResponseWorkItem{
    
    public: 
    virtual ~ResponseWorkItem(){};
     virtual void execute() =0;
     virtual void getStatus()=0;
     virtual std::string getName()const =0;
     virtual WorkItemIterator* createIterator()=0;

};
class IncidentGroup: public ResponseWorkItem{
    private:
     std::vector<ResponseWorkItem*> children;
     int teamSize;

    public:
        IncidentGroup(const std::string& n);
        IncidentGroup(const std::string& n, int ts);
        ~IncidentGroup();
        void add(ResponseWorkItem* item);
        void remove(ResponseWorkItem* item);
        void execute() override;
        void getStatus() override;
        std::string getName()const override;
        WorkItemIterator* createIterator() override;



};
class ResponseTask: public ResponseWorkItem{
    private:
        TaskState* currrentState;
    public:
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

};
#endif