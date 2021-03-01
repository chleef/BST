#include "main.h"


int main(int argc, char *argv[]) {
    try{

        ifstream File;

        if(argc < 2)
            cout << "need file argument" << endl;
        
        File.open(argv[1]);
    


        BST tree;
        BST* root = NULL;
        root = tree.insert(root, 50);
        tree.insert(root, 30);
        tree.insert(root, 40);
        tree.insert(root, 20);
        tree.insert(root, 70);
        tree.insert(root, 60);
        tree.insert(root, 80);
        tree.insert(root, 45);
        tree.insert(root, 46);
        tree.insert(root, 44);
        tree.insert(root, 35);


        tree.display(root);
        cout << endl;

        tree.remove(root, 30);

        tree.display(root);
        cout << endl;

        tree.remove(root, 80);

        tree.display(root);
        cout << endl;

    }
    catch(exception e){
        cout << "exception caught in main: " << e.what() << endl;
    }
    cout << "end of main " << endl;
    return 0;
}