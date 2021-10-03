/*
* Title: Heaps
* Author: Efe Beydogan
* ID: 21901548
* Section: 1
* Assignment: 3
* Description: request main file
*/

#include "Request.h"

using namespace std;

Request::Request() {
    id = 0;
    priority = 0;
    requestTime = 0;
    processTime = 0;
}

Request::Request( int reqId, int reqPriority, int reqRequestTime, int reqProcTime) {
    id = reqId;
    priority = reqPriority;
    requestTime = reqRequestTime;
    processTime = reqProcTime;
}

int Request::getId() {
    return id;
}

int Request::getPriority() {
    return priority;
}

int Request::getReqTime() {
    return requestTime;
}

int Request::getProcTime() {
    return processTime;
}

