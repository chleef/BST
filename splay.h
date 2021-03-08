
#include <iostream>

using namespace std;

class Splay{
    private:
        int num;
        Splay* left;
        Splay* right;
        unsigned traversal;

    public:
        Splay();
        Splay(int);
        ~Splay();
        Splay* insert(Splay*, int);
        Splay* search(Splay*, int);
        Splay* remove(Splay*, int);
        void display(Splay*);
        unsigned getTraversal();

};

//default constructor
Splay::Splay() {
    num = 0;
    traversal = 0;
    left = NULL;
    right = NULL;
}

//parameter constructor
Splay::Splay(int num) {
    this->num = num;
    traversal = 0;
    left = NULL;
    right = NULL;
}

//destructor
Splay::~Splay() {
    delete left;
    delete right;
}

//insert method
Splay* Splay::insert(Splay* root, int val) {

} //end insert

//search method
Splay* Splay::search(Splay* root, int find) {
    traversal++;
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