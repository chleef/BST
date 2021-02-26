

#include <iostream>

using namespace std;

class BST {
    private:
        int num;
        BST* left;
        BST* right;
        unsigned traversal;
    public:
        BST();
        BST(int);
        BST* insert(BST*, int);
        BST* search(BST*, int);
        void setNum(int);
        unsigned getTraversal();
};

//default constructor
BST::BST() {
    num = 0;
    left = NULL;
    right = NULL;
}

BST::BST(int num) {
    this->num = num;
    left = NULL;
    right = NULL;
}

//insert method
BST* BST::insert(BST* root, int val) {
    if(root == NULL){ //tree is empty
       // cout << "tree is empty" << endl;
        return new BST(val);
    }
    else if(val > root->num) { //need to go down the right side
        root->right = insert(root->right, val); //recursive call - start insert method over 
    }
    else {
        root->left = insert(root->left, val); //recursive call - start insert over down the left side
    }
    return root;
}

BST* BST::search(BST* root, int find) {
    if(root == NULL)
        return NULL;
    else if(root->num == find) 
        return root;
    else if(find > root->num) {//need to go to the right because num we're searching for is bigger
        return search(root->right, find); //recursively look at the next one
    }
    else { //need to go to the left
        return search(root->left, find);
    }
}


void BST::setNum(int num){
    this->num = num;
}

unsigned BST::getTraversal(){
    return traversal;
}