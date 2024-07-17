#include "KNNClassifier.h"

#include <iostream>

using namespace std;

KNNClassifier::KNNClassifier(float** trainData, int* trainLabels, int k) {

	KD = new KDTree(784);

    this->trainData = trainData;

    this->trainLabels = trainLabels;

	KD = KD->createTree(trainData, trainLabels, 10000);

    this->k = k;

}



int Max(int arr[], int n)
{
    int i;

    int max = -1;

    int index_max;

    for (i = 0; i < n; i++)
        if (arr[i] > max && arr[i] != 0) {

            max = arr[i];

            index_max = i;

        }

            

    return index_max;
}


int KNNClassifier::classify(float* dataPoint) {

    KDTree* temp = new KDTree(784);

    temp = temp->createTree(trainData, trainLabels, 10000);

	int predictedLabel;

    int counter[10];

    for (int i = 0; i < 10; i++)
        counter[i] = 0;


  Node** KNN = temp->findMNearestFunction(temp->root, dataPoint, 0, k);


  
   for (int i = 0; i < k; i++) {

      

       counter[KNN[i]->label]+=1;


   }


   predictedLabel = Max(counter, 10);

  

   return predictedLabel;


}

int* KNNClassifier::classifyAll(float** dataPoints,int n) {

    int* predicted_labels = new int[n];

    for (int i = 0; i < n; i++) {

        predicted_labels[i] = classify(dataPoints[i]);

    }

    return predicted_labels;

}

float KNNClassifier::accuracy(int* labels_true, int* labels_predicted,int n) {

    int counter = 0;

    for (int i = 0; i < n; i++) {

        if (labels_predicted[i] == labels_true[i])
            counter++;


    }

    float ratio = (float)counter / (float)n* (float)100;

    return ratio;
}