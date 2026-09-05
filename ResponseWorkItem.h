#ifndef RESPONSEWORKITEM
#define RESPONSEWORKITEM
#include<iostream>
#include <vector>
#include <string>
#include "TaskState.h"

class ResponseWorkItem{
    
    public: 
    virtual ~ResponseWorkItem();
     virtual void execute() =0;
     virtual void getStatus()=0;
     virtual std::string getName() =0;

};
class IncidentGroup: public ResponseWorkItem{
    private:
     std::vector<ResponseWorkItem*> children;
     int teamSize;

    public:
        IncidentGroup(std::string n);
        IncidentGroup(std::string n, int ts);
        ~IncidentGroup();
        void add(ResponseWorkItem* item);
        void remove(ResponseWorkItem* item);
        void execute() override;
        void getStatus() override;
        std::string getName() override;



};
class FireTask: public ResponseWorkItem{
    private:
        TaskState* state;
    public:
        FireTask(std::string n);
        ~FireTask();
        void execute() override;
        void getStatus() override;
        std::string getName() override;
        void setState(TaskState* state);
        void getState();
        void dispatchCrew();
        void completeRescue();
};
class MedicalTask: public ResponseWorkItem{
    MedicalTask(std::string n);
    ~MedicalTask();
    void execute() override;
    void getStatus() override;
    std::string getName() override;
    void setState(TaskState* state);
    void getState();
    void assessPatient();
    void stabilizePatient();
    void transportPatient();

};
#endif