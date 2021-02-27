#include "BST.h"


using namespace std;


int main(int argc, char *argv[]) {
    try{

        BST tree;
        BST* root = NULL;
        tree.insert(root, 50);
        tree.insert(root, 30);
        tree.insert(root, 20);
        tree.insert(root, 40);
        tree.insert(root, 70);

        tree.display(root);


    }
    catch(exception e){
        cout << "exception caught in main: " << e.what() << endl;
    }
    cout << "end of main " << endl;
}