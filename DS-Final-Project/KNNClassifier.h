#ifndef KNNClassifier_H
#define KNNClassifier_H

#include "KDTree.h";

#include "MNIST.h"


class KNNClassifier {

private:

	int k;

	KDTree* KD;

	float** trainData;
	
	int* trainLabels;

public:

	KNNClassifier(float** trainData, int* trainLabels , int k);

	int classify(float* dataPoint);

	int* classifyAll(float** dataPoints, int n);

	float accuracy(int* labels_true, int* labels_predicted, int n);


};









#endif //KNNClassifier_H
