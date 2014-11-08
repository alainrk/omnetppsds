//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2006-2008 OpenSim Ltd.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#ifndef __QUEUEING_FORK_H
#define __QUEUEING_FORK_H

#include "QueueingDefs.h"

namespace queueing {

class Job;

/**
 * See the NED declaration for more info.
 */
class QUEUEING_API Clone : public cSimpleModule
{
    private:
        bool changeMsgNames;
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        virtual void updateJobName(Job *job, int i);
};

}; //namespace

#endif



