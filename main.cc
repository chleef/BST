#include "main.h"


int main(int argc, char *argv[]) {
    try{
/*
        BST tree;
        BST* root = NULL;

        root = tree.insert(root, 1);
        for(int i = 2; i < 16; i++)
            tree.insert(root, i);

        tree.display(root);
        cout << endl;

        tree.search(root, 5);

        tree.display(root);
        cout << endl;
*/
        auto start = chrono::steady_clock::now();

        ifstream File;

        if(argc < 2)
            cout << "need file argument" << endl;
        
        File.open(argv[1]);


        BST tree;
        BST* root = NULL;
        int hold;
        string holdString;
        stringstream ss;

        File >> hold;
        root = tree.insert(root, hold);

        getline(File, holdString);

        //cout << "holdString is: " << holdString << endl;

        ss << holdString;

        while(!ss.eof()) {
            ss >> hold;
        //    cout << "hold is: " << hold << endl;
            if(hold != -1)
                tree.insert(root, hold);
            hold = -1;
        }
        
        //cout << "hold is now: " << endl;
        
        getline(File, holdString);
        //cout << "holdString is now: " << holdString << endl;
        cout << "Initial tree: " << endl;
        tree.display(root);
        cout << endl;
        
        getline(File, holdString);

       // cout << "holdString is: " << holdString << endl;
        stringstream ss2;
        ss2 << holdString;

        while(!ss2.eof()) {
            ss2 >> hold;
        //    cout << "in search while, searching for: " << hold << endl;
            if(hold != -1)
                tree.search(root, hold);
            hold = -1;
        }

        //tree.display(root);
        cout << endl;
        getline(File, holdString);
        //cout << "holdString is: " << holdString << endl;

        getline(File, holdString);
        //cout << "holdString is: " << holdString << endl;
        stringstream ss3;
        ss3 << holdString;
        
        while(!ss3.eof()) {
            ss3 >> hold;
        //    cout << "in remove while, removing: " << hold << endl;
            if(hold != -1)
                tree.remove(root, hold);
            hold = -1;
        }

        cout << "Final tree structure:" << endl;
        tree.display(root);
        cout << endl;

        auto end = chrono::steady_clock::now();

        cout << "traversal count: " << tree.getTraversal() << endl;
        cout << "total time for program (ns): " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
    }
    catch(exception e){
        cout << "exception caught in main: " << e.what() << endl;
    }
    //cout << "end of main " << endl;
    return 0;
}