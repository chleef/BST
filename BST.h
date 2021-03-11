

#include <iostream>

using namespace std;

struct Node { //not going to mess up again -- going to use a node this time
    int num;
    Node* left;
    Node* right;
};

class BST {
    private:
        Node* root;
        unsigned traversal;

    public:
        BST();
        ~BST();
        void insert(int);
        Node* search(Node*, int);
        Node* remove(Node*, int);
        void display(Node*);
        unsigned getTraversal();
        void clear(Node*);
        Node* getRoot();
};

//default constructor
BST::BST() {
    root->num = 0;
    traversal = 0;
    root = NULL;
    root->left = NULL;
    root->right = NULL;
}

BST::~BST() {
     clear(this->root);

}

//insert method
void BST::insert(int val) {
    //increment traversal
    traversal++;
    Node* mover = this->root;
    Node* follower = NULL;
    Node* newNode = new Node;
    newNode->left = newNode->right = NULL;
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

    //cout << "through while loop in insert" << endl;
    if(follower == NULL) //we have nothing in our tree
        this->root = newNode;
    else if(newNode->num > follower->num)
        follower->right = newNode;
    else
        follower->left = newNode;
}

Node* BST::search(Node* root, int find) {
    //once again just up here?
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
}

Node* BST::remove(Node* root, int num) {
    //assuming I increment traveral up here:
    traversal++;
    bool removingRoot = false;
    if(this->root->num == num)
        removingRoot = true;
    if(root == NULL) //bottom of tree, haven't found num
        return NULL;
    else if(root->num == num){ //found it - time to remove
        //deal with the different cases
        //if we're at the leaf, good to remove
        if(root->left == NULL && root->right == NULL)
            delete root;
        //else if we only have one child we just have to connect those
        else if(root->left == NULL && root->right != NULL) {
            root = root->right;
        }
        else if(root->left != NULL && root->right == NULL) {
            root = root->left;
        }
        //else if we have a bunch of crap to deal with - two children
        else {
            //find the smallest number from the right side
            BST* temp = root->right;

            while(temp && temp->left != NULL) {
                temp = temp->left;
               // traversal++;
            }
            
            //set the one we want to remove equal to that number
            root->num = temp->num;

            if(removingRoot)
                this->root = root;

            //get rid of old temp
            root->right = remove(root->right, temp->num);
        }
    }
    else if(num > root->num) { //need to go to the right
        root->right = remove(root->right, num);
    }
    else { //need to go left
        root->left = remove(root->left, num);
    }
    return root;
}

void BST::display(BST* root) {
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
   // cout << "[";
    display(root->right);
    cout << "]";
}

unsigned BST::getTraversal(){
    return traversal;
}


void BST::clear(Node* root){
    /*
    if(root == NULL) {
        return;
    }
    clear(root->left);
    clear(root->right);

    delete root;
    traversal = 0;
    */
   if(root != NULL) {
       clear(root->left);
       clear(root->right);
       cout << "deleting " << root->num << endl;
       delete root;
   }
   traversal = 0;
} //end clear

Node* BST::getRoot(){
    return this->root;
}