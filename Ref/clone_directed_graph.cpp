#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
	int nodeVal;
	vector<ListNode*> neighbors;
};

ListNode *graphClone(ListNode* graph) {
	if(!graph) {
		return NULL;
	}

	unordered_map<ListNode*, ListNode*> map;
	queue<ListNode*> q;
	q.push(graph);

	ListNode* graphCopy = new ListNode();
	graphCopy->nodeVal = graph->nodeVal;
	map[graph] = graphCopy;

	while(!q.empty()) {
		ListNode* node = q.front();
		q.pop();
		int noNeighbors = node->neighbors.size();
		for(int i = 0; i < noNeighbors; i++) {
			ListNode* neighbor = node->neighbors[i];
			if(map.find(neighbor) == map.end()) {
				ListNode* newNeighbour = new ListNode();
				newNeighbour->nodeVal = neighbor->nodeVal;
				map[neighbor] = newNeighbour;
				map[node]->neighbors.push_back(newNeighbour);
				q.push(neighbor);
			}
			else {
				map[node]->neighbors.push_back(map[neighbor]);
			}
		}
	}

	return graphCopy;
}

void printGraph(ListNode* graph) {
	queue<ListNode*> q;
	q.push(graph);
	while(!q.empty()) {
		ListNode* temp = q.front();
		q.pop();
		cout<<temp->nodeVal<<" --> ";
		int noNeighbors = temp->neighbors.size();
		for(int i = 0; i < noNeighbors; i++) {
			ListNode* neighbor = temp->neighbors[i];
			cout<<neighbor->nodeVal<<" ";
			q.push(neighbor);
		}
		cout<<endl;
	}
	return;
}

int main(int argc, char* argv[]) {
	ListNode* node1 = new ListNode();
	ListNode* node2 = new ListNode();
	ListNode* node3 = new ListNode();
	ListNode* node4 = new ListNode();
	ListNode* node5 = new ListNode();
	ListNode* node6 = new ListNode();
	ListNode* node7 = new ListNode();
	ListNode* node8 = new ListNode();
	ListNode* node9 = new ListNode();
	ListNode* node10 = new ListNode();
	ListNode* node11 = new ListNode();
	ListNode* node12 = new ListNode();
	ListNode* node13 = new ListNode();
	node1->nodeVal = 1;
	node2->nodeVal = 2;
	node3->nodeVal = 3;
	node4->nodeVal = 4;
	node5->nodeVal = 5;
	node6->nodeVal = 6;
	node7->nodeVal = 7;
	node8->nodeVal = 8;
	node9->nodeVal = 9;
	node10->nodeVal = 10;
	node11->nodeVal = 11;
	node12->nodeVal = 12;
	node13->nodeVal = 13;
	node1->neighbors.push_back(node2);
	node1->neighbors.push_back(node3);
	node2->neighbors.push_back(node4);
	node2->neighbors.push_back(node5);
	node2->neighbors.push_back(node6);
	node3->neighbors.push_back(node7);
	node3->neighbors.push_back(node2);
	node4->neighbors.push_back(node8);
	node4->neighbors.push_back(node9);
	node7->neighbors.push_back(node10);
	node7->neighbors.push_back(node11);
	node6->neighbors.push_back(node12);
	node6->neighbors.push_back(node13);

	printGraph(node1);
	cout<<"Cloned graph as follows"<<endl<<endl;
	printGraph(graphClone(node1));

	return 0;
}
