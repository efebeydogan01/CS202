/*
* Title: Heaps
* Author: Efe Beydogan
* ID: 21901548
* Section: 1
* Assignment: 3
* Description: printer simulator main file
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include "PriorityQueue.h"
#include "Request.h"
#include "simulator.h"
using namespace std;

int main( int argc, char *argv[]) {

    // get the command line values
    string filename = argv[1];
    string wait = argv[2];
    double avgWaitingTime;

    stringstream ss;
    ss << wait;
    ss >> avgWaitingTime;
//    string filename = "TEST1.txt";
//    double avgWaitingTime = 10;
    ifstream file;
    // open the file
    file.open( filename.c_str(), ios_base::in);
    // get the values from the file
    string requestCountStr, idStr, priorityStr, requestTimeStr, processTimeStr, text;
    int requestCount, id, priority, requestTime, processTime;

    getline( file, requestCountStr, '\n');

    istringstream( requestCountStr) >> requestCount;

    Request* requests = new Request[requestCount];
    int counter = 0;
    while ( file.eof() == false) {

        // get the requests
        getline( file, text, '\n');
        stringstream sstream( text);
        getline( sstream, idStr, ' ');
        istringstream( idStr) >> id;

        getline( sstream, priorityStr, ' ');
        istringstream( priorityStr) >> priority;

        getline( sstream, requestTimeStr, ' ');
        istringstream( requestTimeStr) >> requestTime;

        getline( sstream, processTimeStr, '\n');
        istringstream( processTimeStr) >> processTime;

        Request r( id, priority, requestTime, processTime);
        requests[counter] = r;
        counter++;
    }

    file.close();
    simulator s;

    s.findOptimum( requests, avgWaitingTime, requestCount);

    delete [] requests;
    return 0;
}
