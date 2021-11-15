/*
 * AUTHOR: BIBEK DHUNGANA
 * DATE: November 2, 2021
 * FILENAME: Dhunagan_Bibek_Lab10
 * DESCRIPTION:This code is used for breadth first traversal of the graph.
 */

 //including all the required headers files.
#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

//class to store information about the graph
class Graph {
public:
	//constructor
	Graph(int numberOfVertices) {
		this->numberOfVertices = numberOfVertices;
		adjacentList.resize(numberOfVertices);
		visitedVerticesList.resize(numberOfVertices, 0);
	}
	//method to add edges
	void addEdge(int source, int destination) {
		adjacentList.at(source).push_back(destination);
		adjacentList.at(destination).push_back(source);
	}
	//breadth firstSearch function
	void breadthFirstSearch(int startVertex) {
		q1.push(startVertex);
		visitedVerticesList[startVertex] = 1;
		while (!q1.empty()) {
			int vertex = q1.front();
			cout << "Visited " << vertex << endl;
			q1.pop();
			for (int i : adjacentList.at(vertex)) {
				if (visitedVerticesList[i] == 0) {
					q1.push(i);
					visitedVerticesList.at(i) = 1;
				}
			}
		}
	}
private:
	//instance variables
	//for number of vertices.
	int numberOfVertices;

	//vector of list of adjacent vertices.//could also be used 2dimensional array here.
	vector< list<int> > adjacentList;

	//vector to track the visited vertices.
	vector<int> visitedVerticesList;

	//queue used for traversal.
	queue<int> q1;
};

int main() {
	//creating graph with 4 vertices
	Graph g(4);

	//adding edges as given in the diagram
	g.addEdge(0, 2);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);

	//calling breadthFirstSearch staring from vertex 2.
	cout << "The breadth fisrt search traversal of the given graph:" << endl;
	g.breadthFirstSearch(2);

	return 0;
}
