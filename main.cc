#include "main.h"


int main(int argc, char *argv[]) {
    try{

        ifstream File;

        if(argc < 2)
            cout << "need file argument" << endl;
        
        File.open(argv[1]);


        BST tree;
        BST* root = NULL;
        int hold;
        string throwaway;

        File >> hold;
        root = tree.insert(root, hold);

        while(File >> hold) {
            cout << "hold is: " << hold << endl;
            tree.insert(root, hold);
        }
        
        cout << "hold is now: " << endl;
        
        tree.display(root);
        cout << endl;
        
        char throwaway2;
        File >> throwaway2;
        cout << "throwaway2: " << throwaway2 << endl;
        getline(File, throwaway);
        cout << "throwaway: " << throwaway << endl;
        getline(File, throwaway);
        cout << "throwaway: " << throwaway << endl;
        getline(File, throwaway);
        cout << "throwaway: " << throwaway << endl;
        getline(File, throwaway);
        cout << "throwaway: " << throwaway << endl;

        while(File >> hold) {
            cout << "in search while, searching for: " << hold << endl;
            tree.search(root, hold);
        }

        tree.display(root);
        cout << endl;

        File >> throwaway;
        File >> throwaway;
        
        while(File >> hold) {
            cout << "in remove while, removing: " << hold << endl;
            tree.remove(root, hold);
        }

        tree.display(root);
        cout << endl;
/*
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
*/



       // tree.remove(root, 30);


      //  tree.remove(root, 80);


    }
    catch(exception e){
        cout << "exception caught in main: " << e.what() << endl;
    }
    cout << "end of main " << endl;
    return 0;
}