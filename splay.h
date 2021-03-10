
#include <iostream>

using namespace std;

struct Node { //not going to mess up again -- going to use a node this time
    int num;
    Node *parent;
    Node *left;
    Node *right;
};

class Splay{
    private:
        Node* root;
        unsigned traversal;

        void splay(Node*);
        void rotateLeft(Node*);
        void rotateRight(Node*);
    public:
        Splay();
        ~Splay();
        void insert(int);
        Node* search(Node*, int);
        Node* remove(Node*, int);
        void display(Node*);
        unsigned getTraversal();
        Node* getRoot();
        void clear(Node*);

};

void Splay::splay(Node* splayNode){
    //check if it just needs a zig

    //check which of the 4 possibilities its in
    //zig zig from left -- rotate left twice?
    //zig zag
    //zig zig from right
    //zig zag otherway
}

//default constructor
Splay::Splay() {
    traversal = 0;
    root = NULL;
}

//destructor
Splay::~Splay() {
    //call clear
}

//insert method
void Splay::insert(int val) {
    traversal++;
    Node* mover = this->root;
    Node* follower = NULL;
    Node* newNode = new Node;
    newNode->parent = newNode->left = newNode->right = NULL;
    newNode->num = val;
    while(mover != NULL){
        //move mover down to wherever newNode should be inserted, keep follower trailing
        follower = mover;
        if(newNode->num > mover->num){
            mover = mover->right;
        }
        else {
            mover = mover->left;
        }
    } //end while - once mover is Null we are where we want to be
    newNode->parent = follower;

    if(follower == NULL) //we have nothing in our tree
        this->root = newNode;
    else if(newNode->num > follower->num)
        follower->right = newNode;
    else
        follower->left = newNode;

    //then SPLAY***************************************************************
    
} //end insert

//search method
Node* Splay::search(Node* root, int find) {
    traversal++;
    if(root == NULL) {
        //need to splay the parent?- got to the bottom
        return NULL;
    }
    else if(root->num == find) {
        //need to splay - found the node
        return root;
    }
    else if(find > root->num) {//need to go to the right because num we're searching for is bigger
        return search(root->right, find); //recursively look at the next one
    }
    else { //need to go to the left
        return search(root->left, find);
    }
} //end search

//remove method
Node* Splay::remove(Node* root, int val) {

} //end remove

//display function
void Splay::display(Node* root){
    // cout << "in display" << endl;
    if(root == NULL ) {//done
        cout << "[";
        return;
    }
    cout << "[";
    cout << root->num;

    if(root->left == NULL && root->right == NULL) {
        return;
    }

    display(root->left);
    cout << "]";
    display(root->right);
    cout << "]";
}

unsigned Splay::getTraversal(){
    return traversal;
}

Node* Splay::getRoot(){
    return this->root;
}