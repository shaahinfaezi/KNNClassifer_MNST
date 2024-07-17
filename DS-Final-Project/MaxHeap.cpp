
#include "MaxHeap.h"

#include <iostream>

using namespace std;

MaxHeap::MaxHeap(unsigned m):m(m),size(0) {

	maxHeap = new float[m];

    Nodes = new Node*[m];


}


void MaxHeap::Insert(float key, Node* keyNode) {

    size += 1;


    maxHeap[size- 1] = key;

    Nodes[size - 1] = new Node;

    Nodes[size - 1] = keyNode;


    Heapify(maxHeap, size, size - 1,Nodes);


}

void MaxHeap::RemoveRoot() {

    float lastElement = maxHeap[size - 1];

    Node* lastNode = Nodes[size - 1];

    Nodes[0] = lastNode;

    maxHeap[0] = lastElement;

    size -= 1;


     Heapify(maxHeap, size, 0,Nodes);


}

void swap(float* a, float* b,Node* A,Node* B)
{
    float tmp = *a;
    *a = *b;
    *b = tmp;

    Node* temp = A;

    A = B;

    B = temp;

}

void MaxHeap::Heapify(float* arr, int N, int i,Node** Nodes) {

    int largest = i; // Initialize largest as root

    int l = 2 * i + 1; // left = 2*i + 1

    int r = 2 * i + 2; // right = 2*i + 2

    

    if (l < N && arr[l] > arr[largest])
        largest = l;

   

    if (r < N && arr[r] > arr[largest])
        largest = r;

  

    if (largest != i) {
        swap(&arr[i], &arr[largest],Nodes[i],Nodes[largest]);




        Heapify(arr, N, largest,Nodes);
    }

}



float min(float a,float b) {

    if (a < b)
        return a;

    else
        return b;

}

Node* MaxHeap::findMinimumElement()
{
    float minimumElement = maxHeap[size/2];

    unsigned index = size / 2;


    for (unsigned i = 1 + size / 2; i < size; ++i) {

        if (min(minimumElement, maxHeap[i]) == maxHeap[i])
            index = i;

        minimumElement = min(minimumElement, maxHeap[i]);

    }

    

    return Nodes[index];
}

