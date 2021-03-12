

#include <iostream>

using namespace std;

struct BSTNode { //not going to mess up again -- going to use a node this time
    int num;
    BSTNode* left;
    BSTNode* right;
};

class BST {
    private:
        BSTNode* root;
        unsigned traversal;

        BSTNode* remove(BSTNode*&, int);
        BSTNode* findMin(BSTNode*);
    public:
        BST();
        ~BST();
        void insert(int);
        void remove(int);
        BSTNode* search(BSTNode*, int);
        void display(BSTNode*);
        unsigned getTraversal();
        void clear(BSTNode*);
        BSTNode* getRoot();
};

//default constructor
BST::BST() {
   // cout << "in constructor" << endl;
    root = NULL;
    traversal = 0;
   // cout << "end constructor" << endl;
}

BST::~BST() {
   // cout << "in destructor " << endl;
     clear(this->root);
    root = NULL;
   // cout << "out of destructor " << endl;
}

//insert method
void BST::insert(int val) {
    //increment traversal
    //traversal++;
    /*
    if(root == NULL) {
        BSTNode* node = new BSTNode;
        node->num = val;
        node->left = node->right = NULL;
        root = node;
    }
    else if(root->num < val){
        insert(root->right, val);
    }
    else {
        insert(root->left, val);
    }
*/
    traversal++;
    BSTNode* mover = this->root;
    BSTNode* follower = NULL;
    BSTNode* newNode = new BSTNode;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->num = val;
    while(mover != NULL){
        traversal++;
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

BSTNode* BST::search(BSTNode* root, int find) {
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
//public remove
void BST::remove(int num){
    remove(this->root, num);
    return;
}
//private findmin function
BSTNode* BST::findMin(BSTNode* node){
    traversal++;
    if(node == NULL)
        return NULL;
    else if(node->left == NULL)
        return node;
    else 
        return findMin(node->left);
}


//private remove
BSTNode* BST::remove(BSTNode* &node, int num) {
    traversal++;
    BSTNode* temp;
    if(node == NULL) //not in the tree
        return NULL;
    else if(num > node->num){
        remove(node->right, num);
    }
    else if(num < node->num) {
        remove(node->left, num);
    }
    else { //we found it
        if(node->left == NULL && node->right == NULL){ //removing a leaf
           // cout << "in remove leaf, removing: " << node->num << endl;
            temp = node;
            node = NULL;
            delete temp;
            //cout << "node now: " << node->num << endl;
        }
        else if(node->left != NULL && node->right == NULL){ //just one child
            temp = node;
            node = node->left;
            delete temp;
        }
        else if(node->left == NULL && node->right != NULL) { //just one child
            temp = node;
            node = node->right;
            delete temp;
        }
        else{ //root we're removing has two children
        //find smallest node on right side
            temp = findMin(node->right);

            node->num = temp->num;

            remove(node->right, node->num);

        //set num of current node to that, delete that smallest node
        }
        return node;
    } //end else we found it

    //assuming I increment traveral up here:
    /*
    traversal++;
    bool removingRoot = false;
    if(this->root->num == num)
        removingRoot = true;
    if(node == NULL) //bottom of tree, haven't found num
        return;
    else if(node->num == num){ //found it - time to remove
        //deal with the different cases
        //if we have a bunch of crap to deal with - two children
        if(node->left != NULL && node->right != NULL) {
            //find the smallest number from the right side
            BSTNode* temp = node->right;
            while(temp != NULL && temp->left != NULL) {
                temp = temp->left;
            }
            
            //set the one we want to remove equal to that number
            node->num = temp->num;

            if(removingRoot) //set the tree's root equal to this node
                this->root = node;

            //cout << "this root now: " << this->root->num << endl;
            //cout << "this root left now: " << this->root->left->num << endl;
            //cout << "this root right now: " << this->root->right->num << endl;
            //get rid of old temp
            remove(temp, temp->num);

        } //end dealing with two children
        else {
            BSTNode* temp = NULL;
            if(node->right != NULL){ //only one node on the right
                temp = node;
                node = node->right;
            }
            else if(node->left != NULL){//only one node on the left 
                temp = node;
                node = node->left;
            }
            else { //no children
                temp = node;
                node = NULL;
                //cout some stuff
            }
            if(removingRoot)
                this->root = node;
            
            cout << "Deleting: " << temp->num << endl;
            cout << "node: " << node << endl;
            delete temp;
        } //end else
    } //done finding it
    else if(num > node->num) { //need to go to the right - didnt find it
        remove(node->right, num);
    }
    else { //need to go left - didnt find it
        remove(node->left, num);
    }
    return;
    */
} //end remove

void BST::display(BSTNode* root) {
    //cout << "in display" << endl;
    if(root == NULL ) {//done
        cout << "[";
        return;
    }
    //cout << "root is not null" << endl;
    cout << "[";
    cout << root->num;
    
    if(root->left == NULL && root->right == NULL) {
        //cout << "Inside if both left and right are null" << endl;
        return;
    }
    //cout << "root left is " << root->left->num << endl;
    //cout << "root right is " << root->right->num << endl;
    display(root->left);
    cout << "]";
   // cout << "[";
    display(root->right);
    cout << "]";
}

unsigned BST::getTraversal(){
    return traversal;
}


void BST::clear(BSTNode* node){
    /*
    if(node == NULL) {
        return;
    }
    clear(node->left);
    clear(node->right);

    delete node;
    traversal = 0;
    */
   //cout << "inside clear, getting rid of  " << node->num << endl;
  // cout << "node's left " << node->left << endl;
   
   if(node != NULL) {
      // cout << "about to clear the left" << endl;
       clear(node->left);
       //cout << "on to the right" << endl;
       clear(node->right);
       //cout << "deleting" << endl;
      // cout << "deleting " << root->num << endl;
       delete node;
   }
   else { //node is null
    //   cout << "node is null";
   }
   traversal = 0;
   
} //end clear

BSTNode* BST::getRoot(){
    return this->root;
}