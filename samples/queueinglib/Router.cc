//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2006-2008 OpenSim Ltd.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#include "Router.h"
#include <vector>
#include <omnetpp.h>

namespace queueing {

Define_Module(Router);

void Router::initialize()
{
    const char *algName = par("routingAlgorithm");
    if (strcmp(algName, "random") == 0) {
        routingAlgorithm = ALG_RANDOM;
    } else if (strcmp(algName, "roundRobin") == 0) {
        routingAlgorithm = ALG_ROUND_ROBIN;
    } else if (strcmp(algName, "minQueueLength") == 0) {
        routingAlgorithm = ALG_MIN_QUEUE_LENGTH;
    } else if (strcmp(algName, "minDelay") == 0) {
        routingAlgorithm = ALG_MIN_DELAY;
    } else if (strcmp(algName, "minServiceTime") == 0) {
        routingAlgorithm = ALG_MIN_SERVICE_TIME;
    } else if (strcmp(algName, "probabilityService") == 0) {
        routingAlgorithm = ALG_PROBAB;

        const char *probVecPar = par("probVec");
        cStringTokenizer tokenizer(probVecPar);
        const char *token;
        while ((token = tokenizer.nextToken())!=NULL)
            probVec.push_back(atof(token));

        if (probVec.size() == 0)
            throw cRuntimeError("At least one address must be specified in the probVec parameter!");
    }
    rrCounter = 0;
}

void Router::handleMessage(cMessage *msg)
{
    int outGateIndex = -1;  // by default we drop the message

    switch (routingAlgorithm)
    {
        case ALG_RANDOM:
            outGateIndex = par("randomGateIndex");
            break;
        case ALG_ROUND_ROBIN:
            outGateIndex = rrCounter;
            rrCounter = (rrCounter + 1) % gateSize("out");
            break;
        case ALG_MIN_QUEUE_LENGTH:
            // TODO implementation missing
            outGateIndex = -1;
            break;
        case ALG_MIN_DELAY:
            // TODO implementation missing
            outGateIndex = -1;
            break;
        case ALG_MIN_SERVICE_TIME:
            // TODO implementation missing
            outGateIndex = -1;
            break;
        case ALG_PROBAB:
            outGateIndex = getProbabGateOut();
            break;
        default:
            outGateIndex = -1;
            break;
    }

    EV << "Router OutGate index: " << outGateIndex;

    // send out if the index is legal
    if ( outGateIndex < 0 || outGateIndex >= gateSize("out"))
        error("Invalid output gate selected during routing");

    send(msg, "out", outGateIndex);
}

int Router::getProbabGateOut(){
    double tmp = (float) (rand() % 101);
    tmp = tmp /100;
    double sum = 0;
    int i;
    for (i=0;i<=probVec.size();i++){
        sum += probVec[i];
        if (tmp <= sum)
            return i;
    }
    return 0;
}

}; //namespace

