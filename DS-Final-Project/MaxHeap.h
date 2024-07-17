#ifndef MaxHeap_H
#define MaxHeap_H

#include "Node.h"

class MaxHeap {

private:


	unsigned m;


public:

	unsigned size;

	float* maxHeap;

	Node** Nodes;

	MaxHeap(unsigned m);

	void Insert(float key,Node* keyNode);

	void RemoveRoot();

	void Heapify(float* arr, int N, int i, Node** Nodes);

	Node* findMinimumElement();

};








#endif //MaxHeap_H

