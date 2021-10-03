/*
* Title: Heaps
* Author: Efe Beydogan
* ID: 21901548
* Section: 1
* Assignment: 3
* Description: printer simulator cpp file
*/

#include "simulator.h"
#include "Request.h"
#include "PriorityQueue.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

simulator::simulator() {
}

void simulator::findOptimum( Request*& arr, double avgWaitTime, int requests) {
    int* printers;
    bool* available;
    string* message;

    PriorityQueue* pq;
    double wait = -1;
    int messageCount = 0;
    int counter = 1;
    double sumWait = 0;
    int timePassed = 0;
    bool finished = false;

    while ( wait < 0 || wait > avgWaitTime) {
        pq = new PriorityQueue( requests);
        wait = -1;
        messageCount = 0;
        sumWait = 0;
        timePassed = 0;
        int copyIndex = 0;
        finished = false;
        // holds the times at which the printers become available
        printers = new int[counter];
        // holds the messages for printing
        message = new string[requests];
        // holds the availability of the printers
        available = new bool[counter];
        // initialize the printers to be accessible at minute 0
        for ( int i = 0; i < counter; i++) {
            printers[i] = 0;
            // all the printers are available at first
            available[i] = true;
            message[i] = "";
        }
        int checked = 0;
        while ( !finished) {
            // while the pq is empty, insert requests
            while ( pq->pqIsEmpty() && !finished) {
                // pass the time until requests arrive
                timePassed++;
                // if the next request will arive later it means all the requests will arrive later so don't do the rest of the loop
                if ( arr[checked].getReqTime() > timePassed) {
                    continue;
                }
                for ( int i = checked; i < requests; i++) {
                    // insert requests that have arrived and haven't been processed
                    if ( arr[i].getReqTime() <= timePassed) {
                        pq->pqInsert( arr[i]);
                        // keep the index of the first request that hasn't been processed so don't have to check the whole array all the time
                        checked = i + 1;
                        // finish if the last request has been processed
                        if ( i == requests - 1) {
                            finished = true;
                        }
                    }
                }
            }
            while ( !pq->pqIsEmpty()) {
                // the printers which have finished will become available
                for ( int i = 0; i < counter; i++) {
                    if ( printers[i] <= timePassed) {
                        available[i] = true;
                    }
                }
                int printerNum;
                bool processed = false;
                // find available printer
                for ( printerNum = 0; printerNum < counter; printerNum++) {
                // if the printer is available, it will print
                if ( available[printerNum] ) {
                    Request r;
                    pq->pqDelete( r);
                    // printer isn't available any more
                    available[printerNum] = false;
                    // printer will again be available after the current request is processed
                    printers[printerNum] = timePassed + r.getProcTime();
                    processed = true;
                    // add the wait time for calculating average wait time
                    sumWait += timePassed - r.getReqTime();

                    // add the message
                    ostringstream sstream;
                    sstream << "Printer " << printerNum << "  prints print request " << r.getId() << " at minute " << timePassed << " (wait: " <<
                                timePassed - r.getReqTime() <<  " mins)";
                    message[messageCount] = sstream.str();
                    messageCount++;
                    // break out of the loop after request has been processed
                    break;
                }
            }
            // if the request hasn't been processed or has waited before being processed
            if ( !processed) {
                // we must find the printer that will become available soonest
                int minP = printers[0];
                int index = 0;
                for ( int i = 1; i < counter; i++) {
                    if ( printers[i] < minP) {
                        minP = printers[i];
                        index = i;
                    }
                }
                // pass the time until the request can be handled
                timePassed = minP;
                // when the time passes while a printer is waited to be available, other requests may have come
                for ( int j = checked; j < requests; j++) {
                    // insert requests that have arrived and haven't been processed
                    if ( arr[j].getReqTime() <= timePassed) {
                        pq->pqInsert( arr[j]);
                        checked = j + 1;
                        // finish if the last request has been processed
                        if ( j == requests - 1) {
                            finished = true;
                        }
                    }
                }
                Request r;
                pq->pqDelete( r);
                // set the time the printer will become available again
                printers[index] = timePassed + r.getProcTime();
                available[index] = false;
                // increase the amount of time waited
                int tmp = timePassed - r.getReqTime();
                sumWait += tmp;
                // add the message
                ostringstream sstream;
                sstream << "Printer " << index << " prints print request " << r.getId() << " at minute " << timePassed << " (wait: " << tmp << " mins)";
                message[messageCount] = sstream.str();
                messageCount++;
                }
            }
        }
        delete pq;
        delete [] printers;
        delete [] available;
        // calculate the waiting time
        wait = sumWait / requests;
        // if the desired time is reached, break
        if ( wait <= avgWaitTime) {
            break;
        }
        // increase the number of printers and try again
        counter++;
        delete [] message;
    }

    cout << "Minimum number of printers required: " << counter << endl;
    cout << endl;
    cout << "Simulation with " << counter << " printers:" << endl;
    cout << endl;
    for ( int i = 0; i < messageCount; i++) {
        cout << message[i] << endl;
    }
    cout << endl;
    cout << "Average waiting time: " << wait << " minutes" << endl;
    delete [] message;
}

