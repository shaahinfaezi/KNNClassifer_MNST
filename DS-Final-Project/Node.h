#ifndef Node_H
#define Node_H


class Node {
	
public:

	float *point;

	Node* left;

	Node* right;

	int label;

	Node(float* point,int label,int k);

	Node() {
		left = right = nullptr;

		point = nullptr;
	};

};








#endif //Node_H

