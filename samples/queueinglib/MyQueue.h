//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef MYQUEUE_H_
#define MYQUEUE_H_

#include "QueueingDefs.h"

namespace queueing {

class Job;

class QUEUEING_API MyQueue : public cSimpleModule {

private:
    ///////////////// MY /////////////////
    int capacitySTOP;
    int capacityRESTART;
    bool congestionModeSTOP; // If true, MyQueue rejects new users
    ///////////////// MY /////////////////

    simsignal_t droppedSignal;
    simsignal_t queueLengthSignal;
    simsignal_t queueingTimeSignal;
    simsignal_t busySignal;

    Job *jobServiced;
    cMessage *endServiceMsg;
    cQueue queue;
    int capacity;
    bool fifo;

    Job *getFromQueue();

public:
    MyQueue();
    virtual ~MyQueue();
    int length();

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();

    // hook functions to (re)define behaviour
    virtual void arrival(Job *job);
    virtual simtime_t startService(Job *job);
    virtual void endService(Job *job);
};

}; //namespace

#endif
