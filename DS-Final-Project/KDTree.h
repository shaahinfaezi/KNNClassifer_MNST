#ifndef KDTREE_H
#define KDTREE_H

#include "Node.h"
#include "MaxHeap.h"


class KDTree {

private:

	int k;


public:

	Node* root;

	int number_of_points;

	KDTree(int k);

	KDTree* createTree(float** points, int* label, int number_of_points);

	Node* insert(Node* curr,float* point, int label, unsigned depth);

	Node* findNearest(Node* root,float* point, unsigned depth);

	Node* findMNearest(Node* root, float* point, unsigned depth, int m, MaxHeap* Heap);

	float** searchRange(float* lower_bounds, float* upper_bounds);//ezafe

	bool pointExists(Node* root, float* point, unsigned depth);

	Node* deletePoint(Node* root, float* point, unsigned depth);

	float sqrDistance(float* p0, float* p1);

	Node* nearest(Node* n0, Node* n1, float* target);

	bool EqualPoints(float* p0, float* p1);

	Node* minOfThree(Node* x, Node* y, Node* z, unsigned d);

	Node* Minimum(Node* root, unsigned d, unsigned depth);

	Node** findMNearestFunction(Node* root, float* point, unsigned depth, int m);

	void InOrder(Node* node);


};








#endif //KDTREE_H

