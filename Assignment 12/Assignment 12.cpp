#include <iostream>
#include <ctime>
using namespace std;

struct BST
{
        int data;
        BST * left;
        BST * right;
};

BST* create(int data);
BST* insert_BST(BST* root, const int data);
void bst_to_array(BST* b,int array[],int* n);
int main() {
	srand(time(NULL));
	const int SIZE = 10; //size of the array
	int numbers[SIZE];
	BST* tree = NULL;
	for(int i = 0; i < SIZE; i++){
		numbers[i] = (rand() % 100) + 1;
	}
	for(int i = 0; i < SIZE; i++){
		tree = insert_BST(tree, numbers[i]);
	}
	
	cout << endl << "------Printing original array------" << endl;
	for(int i = 0; i < SIZE; i ++){
		cout << numbers[i] << " ";
	}
	
	int n = 0;
	int numbersInOrder[SIZE];
	cout << endl;
	bst_to_array(tree, numbersInOrder, &n);

	cout << endl << endl << "------Printing in order array------" << endl;
	for(int i = 0; i < n; i ++){
		cout << numbersInOrder[i] << " ";
	}
	cout << endl;
	
}

BST* create(int data){
	BST* n = new BST();
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

BST* insert_BST(BST* root, const int data){
	if(root == NULL){
		root = create(data);
	} else if (data <= root->data){
		root->left = insert_BST(root->left, data);
	} else if (data > root->data){
		root->right = insert_BST(root->right, data);
	}
	return root;
}

void bst_to_array(BST* b,int array[],int* n){
	if(b != NULL){
		bst_to_array(b->left, array, n);
		array[*n] = b->data;
		*n += 1;
		bst_to_array(b->right, array, n);
	}
}