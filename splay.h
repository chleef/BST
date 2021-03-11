
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

//splay function
void Splay::splay(Node* splayNode){
    //cout << "inside splay" << endl;
    //check if it just needs a zig
    while(splayNode->parent != NULL) {
    //check which of the 4 possibilities its in
        if(splayNode->parent->parent == NULL) { //just need to zig
            //figure out left vs right rotate
            if(splayNode->parent->left== splayNode)
                rotateRight(splayNode->parent);
            else
                rotateLeft(splayNode->parent);
        }
        else if(splayNode->parent->left == splayNode){
            if(splayNode->parent->parent->left == splayNode->parent) {
                //aka case 1 zig zig from the left - need to right rotate twice
                rotateRight(splayNode->parent->parent);
                rotateRight(splayNode->parent);
            }
            else {
                 //aka case 2 zig zag - first right then left
                rotateRight(splayNode->parent);
                rotateLeft(splayNode->parent);
            }
        }
        else if(splayNode->parent->right == splayNode){
            if(splayNode->parent->parent->left == splayNode->parent){
            //case 3 - zig zag first left then right
                rotateLeft(splayNode->parent);
                rotateRight(splayNode->parent);
            }
            else {
                 //aka case 4 zig zig from the right - need to left rotate twice
                rotateLeft(splayNode->parent->parent);
                rotateLeft(splayNode->parent);
            }
        }
        else {
            cout << "oops should not be in here in splay - messed up some pointer" << endl;
            //should not be in here
        }
    } //end while loop
   //cout << "done with splay" << endl;
}

//rotateLeft
void Splay::rotateLeft(Node* node){
    Node* oldParent = node->parent;
    Node* rightNode = node->right;
    node->right = rightNode->left;

    if(rightNode->left != NULL)
        rightNode->left->parent = node;
    
    rightNode->parent = oldParent;
    if(oldParent == NULL)
        this->root = rightNode;
    else if(oldParent->right == node)
        oldParent->right = rightNode;
    else
        oldParent->left = rightNode;

    rightNode->left = node;
    node->parent = rightNode;
}

//rotateRight
void Splay::rotateRight(Node* node){
    //need to change leftNode's parent, right - and then their parent
    //need to change node's parent, left - and then their parent
    //need to change oldParent's right or left or neither if root
    Node* oldParent = node->parent;
    Node* leftNode = node->left;
    node->left = leftNode->right;
    //then change that node's parent
    if(leftNode->right != NULL) //not sure if necessary?
        leftNode->right->parent = node;
    leftNode->parent = oldParent;
    if(oldParent == NULL)
        this->root = leftNode;
    else if(oldParent->right == node)
        oldParent->right = leftNode;
    else
        oldParent->left = leftNode;

    leftNode->right = node;
    node->parent = leftNode;
}

//default constructor
Splay::Splay() {
    traversal = 0;
    root = NULL;
}

//destructor
Splay::~Splay() {
    clear(this->root);
}

//insert method
void Splay::insert(int val) {
    //cout << "inside insert" << endl;
    traversal++;
    Node* mover = this->root;
    Node* follower = NULL;
    Node* newNode = new Node;
    newNode->parent = newNode->left = newNode->right = NULL;
    newNode->num = val;
    while(mover != NULL){
        //move mover down to wherever newNode should be inserted, keep follower trailing
      //  cout << "inside while loop moving to wherever we should insert" << endl;
        follower = mover;
        if(newNode->num > mover->num){
            mover = mover->right;
        }
        else {
            mover = mover->left;
        }
    } //end while - once mover is Null we are where we want to be
    newNode->parent = follower;
    //cout << "through while loop in insert" << endl;
    if(follower == NULL) //we have nothing in our tree
        this->root = newNode;
    else if(newNode->num > follower->num)
        follower->right = newNode;
    else
        follower->left = newNode;

    splay(newNode);

} //end insert

//search method
Node* Splay::search(Node* root, int find) {
    traversal++;
    if(root == NULL) {
        //need to splay the parent?- got to the bottom
        splay(root->parent);
        return NULL;
    }
    else if(root->num == find) {
        //need to splay - found the node
        splay(root);
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
    search(this->root, val);
    if(root->num != val){
        //val wasnt in the 
    }

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

void Splay::clear(Node* root){
    if(root != NULL) {
        clear(root->left);
        clear(root->right);
        delete root;
    }
    traversal = 0;
}