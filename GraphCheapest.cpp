#include <fstream>
#include <iostream>
#include <list>
#include <queue>

#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#include <cstdlib>

struct Node
{
  string name;
  double cost;
  bool isVisited;
  list<pair<int, double> > neighbors;
  int prev;
  
};

struct Terminus
{
	int index; //node's index in the database array
	int prev; //the index of the preceding node in the path
	double cost; // the cost of getting to index's node from prev's node
};

bool operator<(const Terminus& a, const Terminus& b) {
	return b.cost < a.cost; //reversed for lo to hi
}

pair<stack<int>, double> getCheapestRoute(int iStart, int iEnd, vector<Node>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it; // to iterate over neighbors
// TO DO -- write this function
  for (int i = 0; i < database.size(); i++)
  {
	  database[i].isVisited = false;
	  database[i].cost = 0;
	  database[i].prev = -1;
  }
  priority_queue<Terminus> toDo;
  Terminus ter;
  ter.index = iStart;
  ter.prev = -1;
  ter.cost = 0;
  toDo.push(ter);
  while (!toDo.empty()) {
	  ter = toDo.top();
	  toDo.pop();
	  if (database[ter.index].isVisited == true) continue;
	  else { 
		  database[ter.index].isVisited = true;
		  database[ter.index].cost = ter.cost;
		  database[ter.index].prev = ter.prev;
		  if (ter.index == iEnd) break;
	  }
	  for (it = database[ter.index].neighbors.begin(); it != database[ter.index].neighbors.end(); ++it) {
		  if (database[it->first].isVisited == true) continue;
		  else {
			  Terminus neighborTer;
			  neighborTer.cost = it->second;
			  neighborTer.index = it->first;
			  
			  neighborTer.prev = ter.index;
			  toDo.push(neighborTer);
		  }
	  }
  }
  
  result.second = database[iEnd].cost;
  int index = iEnd;
  while (index != iStart) {
	  result.first.push(index);
	  index = database[index].prev;
  }
  result.first.push(iStart);
  return result;
}

int main()
{
  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";  

  // process the input file
  vector<Node> database;
  while (fin.good()) // EOF loop
  {
    string fromCity, toCity, cost;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    getline(fin, cost);
    fin.ignore(1000, 10); // skip the separator

    // add nodes for new cities included in the edge
    int iToNode = -1, iFromNode = -1, i;
    for (i = 0; i < database.size(); i++) // seek "to" city
      if (database[i].name == fromCity)
        break;
    if (i == database.size()) // not in database yet
    {
      // store the node if it is new
      Node fromNode = {fromCity};
	  
      database.push_back(fromNode);
    }
    iFromNode = i; 

    for (i = 0; i < database.size(); i++) // seek "from" city
      if (database[i].name == toCity)
        break;
    if (i == database.size()) // not in vector yet
    {
      // store the node if it is new
      Node toNode = {toCity};
      database.push_back(toNode);
    }
    iToNode = i; 

    // store bi-directional edges
    double edgeCost = atof(cost.c_str());
    database[iFromNode].neighbors.push_back(pair<int, double>(iToNode, edgeCost));
    database[iToNode].neighbors.push_back(pair<int, double>(iFromNode, edgeCost));
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    string fromCity, toCity;
    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;

    // find the from city
    int iFrom;
    for (iFrom = 0; iFrom < database.size(); iFrom++)
      if (database[iFrom].name == fromCity)
        break;

    cout << "Enter the destination city [blank to exit]: ";
    getline(cin, toCity);
    if (toCity.length() == 0) break;

    // find the destination city
    int iTo;
    for (iTo = 0; iTo < database.size(); iTo++)
      if (database[iTo].name == toCity)
        break;
	double cost = 0;
    cout << "Route";
    pair<stack<int>, double> result = getCheapestRoute(iFrom, iTo, database);
	for (; !result.first.empty(); result.first.pop()) {
		cost += database[result.first.top()].cost;
		cout << '-' << database[result.first.top()].name;
	}
	
	cout << "\nTotal miles: " << cost;

    cout << endl;
  }
}