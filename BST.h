

#include <iostream>

using namespace std;

class BST {
    private:
        int num;
        BST* root;
        BST* left;
        BST* right;
        unsigned traversal;
    public:
        BST();
        BST(int);
        ~BST();
        BST* insert(BST*, int);
        BST* search(BST*, int);
        BST* remove(BST*, int);
        void display(BST*);
        void setNum(int);
        unsigned getTraversal();
        void clear(BST*);
        BST* getRoot();
};

//default constructor
BST::BST() {
    num = 0;
    traversal = 0;
    root = NULL;
    left = NULL;
    right = NULL;
}

BST::BST(int num) {
    this->num = num;
    traversal = 0;
    root = NULL;
    left = NULL;
    right = NULL;
}

BST::~BST() {
     clear(this->root);
   //delete left;
   //delete right;
   cout << "Deleting: " << this->num << endl;
}

//insert method
BST* BST::insert(BST* root, int val) {
    //increment traversal
    traversal++;
    if(!root){ //tree is empty
        //cout << "root is NULL, adding: "<< val << endl;
        this->root = new BST(val);
        return root;
    }
    else if(val > root->num) { //need to go down the right side
        //cout << "val greater than root's, go right" << endl;
        root->right = insert(root->right, val); //recursive call - start insert method over 
    }
    else {
        //cout << "val less than root's, go left" << endl;
        root->left = insert(root->left, val); //recursive call - start insert over down the left side
    }
    return root;
}

BST* BST::search(BST* root, int find) {
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

BST* BST::remove(BST* root, int num) {
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

void BST::setNum(int num){
    this->num = num;
}

unsigned BST::getTraversal(){
    return traversal;
}


void BST::clear(BST* root){
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

BST* BST::getRoot(){
    return this->root;
}