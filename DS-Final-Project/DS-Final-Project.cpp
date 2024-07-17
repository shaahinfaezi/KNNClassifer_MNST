#include <iostream>
#include <stdio.h>

#include "KDTree.h"

#include "MNIST.h"

#include "KNNClassifier.h"

using namespace std;

int main()
{
	
	MNIST m;

	float ** data=m.input_Data("MNIST\\train.csv",784,10000);

	int * labels=m.input_Labels("MNIST\\train_labels.csv", 10000);


	KNNClassifier* KNNclassifier = new KNNClassifier(data, labels,5 );

	float** test_data = m.input_Data("MNIST\\test.csv", 784, 200);

	int* test_labels = m.input_Labels("MNIST\\test_labels.csv", 200);

	for (int i = 0; i < 200; i++) {

		cout << "The number : " << test_labels[i] << "  The predicted number : " << KNNclassifier->classify(test_data[i])<<endl<<endl;

	}

	cout<<"Accuracy : "<<KNNclassifier->accuracy(test_labels, KNNclassifier->classifyAll(test_data, 200), 200) << "%";





	return 0;
}


