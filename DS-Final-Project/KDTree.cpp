#include "KDTree.h"
#include <math.h>
#include <iostream>
#include <stdio.h>


using namespace std;

float KDTree::sqrDistance(float* p0, float* p1) {

	float dist = 0.00;

	for (int i = 0; i < k; i++) {

		float diff = fabsf(p0[i] - p1[i]);

		dist += pow(diff, 2);

	}

	return dist;

}

Node* KDTree::nearest(Node* n0, Node* n1, float* target) {

	if (n0 == nullptr) return n1;

	if (n1 == nullptr) return n0;

	float d0 = sqrDistance(n0->point,target);

	float d1 = sqrDistance(n1->point, target);


	if (d0 < d1)
		return n0;
	else
		return n1;

}

KDTree::KDTree(int k){
	

	number_of_points = 0;

	this->k = k;

	root = nullptr;


}

KDTree* KDTree::createTree(float** points,int *label, int number_of_points) {


	for (int i = 0; i < number_of_points; i++) {

		root=insert(root,points[i],label[i], 0);

	}


	return this;
}

Node* KDTree::insert(Node* curr,float* point,int label, unsigned depth) {


	if (curr == NULL) {

		curr = new Node(point, label, k);

		number_of_points++;

		return curr;
	}


	int dimension = depth % k;

	//recursive traversal


	if (point[dimension] < curr->point[dimension])

		curr->left = insert(curr->left, point,label, depth + 1);

	else 

		curr->right = insert(curr->right, point,label, depth + 1);


		return curr;



}

Node* KDTree::findNearest(Node* root,float* point, unsigned depth) {

	Node* nextBranch = nullptr;

	Node* otherBranch = nullptr;

	if (root == nullptr) {

		return nullptr;

	}


	int dimension = depth % k;

	//traverse


	if (point[dimension] < root->point[dimension]) {

		nextBranch = root->left;

		otherBranch = root->right;

	}


	else if (point[dimension] > root->point[dimension]) {

		nextBranch = root->right;

		otherBranch = root->left;
		

	}

	//find the best node in the target subtree
	
	Node* temp = findNearest(nextBranch, point, depth + 1);

	Node* best = nearest(temp, root,point);

	float r2 = sqrDistance(point, best->point);  //the radius squared between the target point and the best point in the target subtree

	float rPrime2 = pow(point[depth]-root->point[depth], 2); //the distance squared between the target point and the other subtree(root)

	if (rPrime2 < r2) {//if rPrime is smaller than the radius we should find the closest in the other subtree


		temp = findNearest(otherBranch,point, depth + 1);

		best = nearest(temp, best,point);

	}

	return best;
}


bool KDTree::EqualPoints(float* p0, float* p1) {


	for (int i = 0; i < k; ++i)

		if (p0[i] != p1[i])
			return false;

	return true;

}

bool KDTree::pointExists(Node* root,float* point, unsigned depth) {

	if (root == NULL)
		return false;
	
	if (EqualPoints(root->point, point))
		return true;


	unsigned dimension = depth % k;

	
	if (point[dimension] < root->point[dimension])

		return pointExists(root->left, point, depth + 1);

	else
	return pointExists(root->right, point, depth + 1);
	
}



Node* KDTree::minOfThree(Node* x, Node* y, Node* z, unsigned d) {

	Node* result = x;

	if (y != nullptr && y->point[d] < result->point[d]) 

		result=y;

	
	if (z != nullptr && z->point[d] < result->point[d])

		result = z;


	return result;




}

Node* KDTree::Minimum(Node* root, unsigned d, unsigned depth) {

	if (root == NULL)

		return NULL;

	unsigned dimension = depth % k;


	if (dimension == d) {

		if (root->left == NULL)

			return root;

		return Minimum(root->left, d, depth + 1);



	}

	return minOfThree(root, Minimum(root->left, d, depth + 1), Minimum(root->right, d, depth + 1),d);
	

}

Node* KDTree::deletePoint(Node* root,float* point,unsigned depth) {

	if (root == NULL)
		return NULL;


	unsigned dimension = depth % k;

	if (EqualPoints(root->point, point)) { // If the point to be deleted is present at root


		if (root->right != NULL) {//If right child is not NULL

			Node* min = Minimum(root->right, dimension, 0);

			for (size_t i = 0; i < k; ++i)
			{
				root->point[i] = min->point[i];

			}

			root->right= deletePoint(root->right, min->point, depth + 1);




		}

		else if (root->left != NULL) {//If left child is not NULL

			Node* min = Minimum(root->left, dimension, 0);

			for (size_t i = 0; i < k; i++)
			{
				root->point[i] = min->point[i];

			}

			root->right = deletePoint(root->left, min->point, depth + 1);

			


		}

		else {// If node to be deleted is leaf node

			delete root;

			number_of_points--;

			return NULL;


		}



		return root;

	}

	//If current node doesn't equal to the target point

	if (point[dimension] < root->point[dimension])

		root->left = deletePoint(root->left, point, depth + 1);

	else

		root->right = deletePoint(root->right, point, depth + 1);

	return root;

}


Node** KDTree::findMNearestFunction(Node* root, float* point, unsigned depth, int m){

	MaxHeap* Heap = new MaxHeap(m);

	findMNearest(root,point,depth,m,Heap);

	return Heap->Nodes;

}


void KDTree::InOrder(Node* node) {

	if (node == NULL)
		return;

	
	InOrder(node->left);
	
	for (unsigned i = 0; i < k; i++) {

		cout << node->point[i] << " ";

	}

	cout << endl;

	InOrder(node->right);
	

}





Node* KDTree::findMNearest(Node* root, float* point, unsigned depth, int m,MaxHeap* Heap) {


	if (m < 1 || root == nullptr) return nullptr;

	Node* nextBranch=nullptr;

	Node* otherBranch = nullptr;

	if (m >number_of_points){


		// when more neighbors asked than nodes in tree

		//traverse all


		InOrder(root);

		return nullptr;
	}


	if (Heap->size < m) {

		Heap->Insert(sqrDistance(root->point, point), root);

	}



		int dimension = depth % k;

		//traverse


		if (point[dimension] < root->point[dimension]) {


				nextBranch = root->left;

				otherBranch = root->right;

		}


		else  {
				
				nextBranch = root->right;

				otherBranch = root->left;

		}

		Node * temp=findMNearest(nextBranch, point, depth + 1, m, Heap);

		//find the best node in the target subtree


		Node* bestSoFar = nearest(temp, root, point);

		if (sqrDistance(bestSoFar->point, point) < sqrDistance(Heap->findMinimumElement()->point, point)) {

			Heap->RemoveRoot();

			Heap->Insert(sqrDistance(bestSoFar->point, point), bestSoFar);

		}

		

		float r2 = sqrDistance(Heap->findMinimumElement()->point, point);  //the radius squared between the target point and the best point in the target subtree

		float rPrime2 = pow(fabs(point[depth] - root->point[depth]), 2); //the distance squared between the target point and the other subtree(root)

		if (rPrime2 < r2 || Heap->size<m) {//if rPrime is smaller than the radius we should find the closest in the other subtree



			Node* temp = findMNearest(otherBranch, point, depth + 1, m, Heap);
				

			bestSoFar = nearest(bestSoFar, temp, point);
	
					if (sqrDistance(bestSoFar->point, point) < sqrDistance(Heap->findMinimumElement()->point, point)) {

						Heap->RemoveRoot();

						Heap->Insert(sqrDistance(bestSoFar->point, point), bestSoFar);

					}



			

		}

		return bestSoFar;
	
}

//float** KDTree::searchRange(Node* root,float* lower_bounds, float* upper_bounds) {
//
//	double distsum = 0.0;
//
//	size_t i;
//
//	for (i = 0; i < dimension; i++) {
//
//		if (point[i] < node->lobound[i]) {  // lower than low boundary
//
//			distsum += distance->coordinate_distance(point[i], node->lobound[i], i);
//
//			if (distsum > dist) return false;
//
//		}
//
//		else if (point[i] > node->upbound[i]) {  // higher than high boundary
//
//			distsum += distance->coordinate_distance(point[i], node->upbound[i], i);
//
//			if (distsum > dist) return false;
//		}
//	}
//	return true;	
//
//
//	double curdist = distance->distance(point, node->point);
//
//	if (curdist <= r) {
//
//		range_result->push_back(node->dataindex);
//
//	}
//	if (node->loson != NULL && this->bounds_overlap_ball(point, r, node->loson)){
//
//		range_search(point, node->loson, r, range_result);
//
//	}
//	if (node->hison != NULL && this->bounds_overlap_ball(point, r, node->hison)) {
//
//		range_search(point, node->hison, r, range_result);
//	}
//
//}