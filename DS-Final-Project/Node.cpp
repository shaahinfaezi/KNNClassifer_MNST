#include "Node.h"

Node::Node(float* point,int label,int k) {

    this->point = new float[k];

    for (int i = 0; i < k; i++)
       this->point[i] = point[i];

    this->left = this->right =nullptr;
    
    this->label = label;

}