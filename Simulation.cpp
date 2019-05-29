#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "Queue.h"
#include "DynamicArray.h"

using namespace std;
void displayFileInput
(
  const int numServers,
  const double customerArrivalRate,
  const int waitQueueLength,
  const int minServiceTime,
  const int maxServiceTime,
  const int arrivalStopTime
);
struct Customer
{
  char ID; // A-Z, repeated past 26
  int arrivalTime; // = time when customer arrives
  int serviceEndTime;// = time + rand(min to max service time)
};

int getRandomNumberOfArrivals(double averageArrivalRate);
int main()
{
  srand(time(0)); rand();
  char letter = 'A';
  ifstream fin;

  //for capturing data from file
  int numServers;
  double customerArrivalRate;
  int waitQueueLength;
  int minServiceTime;
  int maxServiceTime;
  int arrivalStopTime;

  

  fin.open("simulation.txt");

  //read input values
  fin >> numServers;
  fin.ignore();
  fin >> customerArrivalRate;
  fin.ignore();
  fin >> waitQueueLength;
  fin.ignore();
  fin >> minServiceTime;
  fin.ignore();
  fin >> maxServiceTime;
  fin.ignore();
  fin >> arrivalStopTime;
  
  displayFileInput(
    numServers,
    customerArrivalRate,
    waitQueueLength,
    minServiceTime,
    maxServiceTime,
    arrivalStopTime
  );
  if (minServiceTime > maxServiceTime) throw "Minimum service time must be less than maximum service time";
  //data structures
  
  Queue<Customer> waitingCustomers;
  DynamicArray<Customer> nowServing(numServers);
  DynamicArray<bool> isServerBusy(numServers);
  for (int i = 0; i < numServers; i++) isServerBusy[i] = false;

  for (int time = 0;; time++) // the clock time
  {
    
    // handle all services scheduled to complete at this clock time 
    for (int i = 0; i < numServers; i++)
    {//for each server
      if (isServerBusy[i])//if the server is busy
      {
        if (time == nowServing[i].serviceEndTime) isServerBusy[i] = false; //if the service end time of the customer that it's now serving equals the clock time set this server to idle
      }
    }
    // handle new arrivals -- can be turned away if wait queue is at maximum length
    if (time < arrivalStopTime) {//if clock time is less than the time at which new arrivals stop
      //get the #of of arrivals from the "Poisson process" (a whole number >= 0)
      for (int i = 0; i < getRandomNumberOfArrivals((maxServiceTime - minServiceTime) / 2); i++) 
      {//for each new arrival
        if (waitingCustomers.size() < waitQueueLength)
        {//if the wait queue is NOT full
          Customer temp;//create a new customer object
          temp.arrivalTime = time;//set its arrival time equal to the current clock time
          if (letter > 'Z') letter = 'A'; //reset letter counter
          temp.ID = letter;//assign it an ID tag(A - Z)
          letter++;        //increment letter for next time
          waitingCustomers.push(temp);//push the new customer onto the wait queue
        }
      }
    }
                // for idle servers, move customer from wait queue and begin service for each server
    for (int i = 0; i < numServers; i++)
    {
      if (isServerBusy[i] == false && !(waitingCustomers.empty()))
      {
        isServerBusy[i] = true;
        nowServing[i] = waitingCustomers.front();
        waitingCustomers.pop();
        nowServing[i].serviceEndTime = time + (minServiceTime + (rand() % maxServiceTime) + 1);
      }
    }
 

//output the summary
//output the current time
//output a visual prepresentation of the servers and the wait queue
//for each server
//output the server's index number (zero-based)
//show the ID of the customer being served by that server(blank if idle)

//for server 0 only, show the IDs of customers in the wait queue
    cout << "Time: " << time << endl;
    cout << "------|-----------|----------" << endl;
    cout << "server|now serving|wait queue" << endl;
    cout << "------|-----------|----------" << endl;
    Queue<Customer> temp = waitingCustomers; // refreshes per loop
    for (int i = 0; i < numServers; i++)
    {
      cout << right << setw(3) << i << setw(6) << nowServing[i].ID;
      if (i == 0) 
      { 
        cout << "          ";
        for (int j = 0; j < waitingCustomers.size(); j++)
        {
          cout << temp.front().ID;
          temp.pop();
        }
      }
      cout << endl;
    }
    cout << "-----------------------------" << endl;
                      if (time == arrivalStopTime) break;
                      cin.ignore(1000, 10);
  }
  
  system("pause");
  return 0;
}
int getRandomNumberOfArrivals(double averageArrivalRate)
{
  int arrivals = 0;
  double probOfnArrivals = exp(-averageArrivalRate);
  for (double randomValue = (double)rand() / RAND_MAX;
    (randomValue -= probOfnArrivals) > 0.0;
    probOfnArrivals *= averageArrivalRate / static_cast<double>(++arrivals));
  return arrivals;
}

void displayFileInput
(
  const int numServers,
  const double customerArrivalRate,
  const int waitQueueLength,
  const int minServiceTime,
  const int maxServiceTime,
  const int arrivalStopTime
)
{
  const int width = 24;
  cout << left << setw(width) << "number of servers:" << numServers << endl;
  cout << setw(width) << "customer arrival rate:" << customerArrivalRate << " per minute, for "
    << arrivalStopTime << " minutes" << endl;
  cout << setw(width) << "maximum queue length:" << waitQueueLength << endl;
  cout << setw(width) << "minimum service time:" << minServiceTime << endl;
  cout << setw(width) << "maximum service time:" << maxServiceTime << endl;
}