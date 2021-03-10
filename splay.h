
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

    public:
        Splay();
        ~Splay();
        Node* insert(Node*, int);
        Node* search(Node*, int);
        Node* remove(Node*, int);
        void display(Node*);
        unsigned getTraversal();
        void clear(Node*);

};

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
Node* Splay::insert(Node* root, int val) {
    traversal++;
    Node* node = new Node;
    if(!this->root){
        //splay tree is empty
        
    }
} //end insert

//search method
Node* Splay::search(Node* root, int find) {
    traversal++;
    if(root == NULL) {
        //need to splay - got to the bottom
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
Splay* Splay::insert(Splay* root, int val) {

} //end remove

//display function
void Splay::display(Splay* root){
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