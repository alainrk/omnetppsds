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

#include <MyQueue.h>
#include "Job.h"

namespace queueing {

Define_Module(MyQueue);

MyQueue::MyQueue()
{
    jobServiced = NULL;
    endServiceMsg = NULL;
}

MyQueue::~MyQueue()
{
    delete jobServiced;
    cancelAndDelete(endServiceMsg);
}

void MyQueue::initialize()
{
    ///////////////// MY /////////////////
    capacitySTOP = par("capacitySTOP");
    capacityRESTART = par("capacityRESTART");
    congestionModeSTOP = false;
    ///////////////// MY /////////////////

    droppedSignal = registerSignal("dropped");
    queueingTimeSignal = registerSignal("queueingTime");
    queueLengthSignal = registerSignal("queueLength");
    emit(queueLengthSignal, 0);
    busySignal = registerSignal("busy");
    emit(busySignal, false);

    endServiceMsg = new cMessage("end-service");
    fifo = par("fifo");
    capacity = par("capacity");
    queue.setName("queue");
}

void MyQueue::handleMessage(cMessage *msg)
{
    if (msg==endServiceMsg)
    {
        endService( jobServiced );
        if (queue.empty())
        {
            jobServiced = NULL;
            emit(busySignal, false);
        }
        else
        {
            jobServiced = getFromQueue();
            emit(queueLengthSignal, length());
            simtime_t serviceTime = startService( jobServiced );
            scheduleAt( simTime()+serviceTime, endServiceMsg );
        }
    }
    else
    {
        Job *job = check_and_cast<Job *>(msg);
        arrival(job);

        if (!jobServiced)
        {
        // processor was idle
            jobServiced = job;
            emit(busySignal, true);
            simtime_t serviceTime = startService( jobServiced );
            scheduleAt( simTime()+serviceTime, endServiceMsg );
        }
        else
        {
            ///////////////// MY /////////////////
            // Congestion Mode Active
            if (congestionModeSTOP == true){
                // Queue length reached restart value
                if (queue.length() <= capacityRESTART){
                    congestionModeSTOP = false;
                    // Job can continue
                }
                // Queue length still over restart value
                else {
                    EV << "CapacityMAX full! Job dropped.\n";
                    if (ev.isGUI()) bubble("Dropped!");
                    emit(droppedSignal, 1);
                    delete job;
                    return;
                }
            }
            // Congestion Mode Not Active
            else {
                // Queue length reached stop value
                if (queue.length() >= capacitySTOP){
                    congestionModeSTOP = true;

                    EV << "CapacityMAX full! Job dropped.\n";
                    if (ev.isGUI()) bubble("Dropped!");
                    emit(droppedSignal, 1);
                    delete job;
                    return;

                }
                // Queue length still under stop value
                else {
                    // Job has to stop
                }
            }
            ///////////////// MY /////////////////


            // check for container capacity
            if (capacity >=0 && queue.length() >= capacity)
            {
                EV << "Capacity full! Job dropped.\n";
                if (ev.isGUI()) bubble("Dropped!");
                emit(droppedSignal, 1);
                delete job;
                return;
            }
            queue.insert( job );
            emit(queueLengthSignal, length());
            job->setQueueCount(job->getQueueCount() + 1);
        }
    }

    if (ev.isGUI()) getDisplayString().setTagArg("i",1, !jobServiced ? "" : "cyan3");
}

Job *MyQueue::getFromQueue()
{
    Job *job;
    if (fifo)
    {
        job = (Job *)queue.pop();
    }
    else
    {
        job = (Job *)queue.back();
        // FIXME this may have bad performance as remove uses linear search
        queue.remove(job);
    }
    return job;
}

int MyQueue::length()
{
    return queue.length();
}

void MyQueue::arrival(Job *job)
{
    job->setTimestamp();
}

simtime_t MyQueue::startService(Job *job)
{
    // gather queueing time statistics
    simtime_t d = simTime() - job->getTimestamp();
    emit(queueingTimeSignal, d);
    job->setTotalQueueingTime(job->getTotalQueueingTime() + d);
    EV << "Starting service of " << job->getName() << endl;
    job->setTimestamp();
    return par("serviceTime").doubleValue();
}

void MyQueue::endService(Job *job)
{
    EV << "Finishing service of " << job->getName() << endl;
    simtime_t d = simTime() - job->getTimestamp();
    job->setTotalServiceTime(job->getTotalServiceTime() + d);
    send(job, "out");
}

void MyQueue::finish()
{
}

}; //namespace

