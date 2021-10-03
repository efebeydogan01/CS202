/*
* Title: Heaps
* Author: Efe Beydogan
* ID: 21901548
* Section: 1
* Assignment: 3
* Description: request header file
*/

#ifndef REQUEST_H
#define REQUEST_H
using namespace std;

class Request {
public:
    Request();
    Request( int reqId, int reqPriority, int reqRequestTime, int reqProcTime);

    int getId();
    int getPriority();
    int getReqTime();
    int getProcTime();

private:
    int id;
    int priority;
    int requestTime;
    int processTime;
};

#endif // REQUEST_H


