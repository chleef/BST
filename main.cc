#include "main.h"


int main(int argc, char *argv[]) {
    try{
        /*
        Splay splaytree;

        splaytree.insert(10);
        splaytree.display(splaytree.getRoot());
        cout << endl;
        splaytree.insert(60);
        splaytree.display(splaytree.getRoot());
        cout << endl;
        splaytree.insert(30);
        splaytree.display(splaytree.getRoot());
        cout << endl;
        splaytree.insert(40);
        splaytree.display(splaytree.getRoot());
        cout << endl;
        splaytree.insert(20);
        splaytree.display(splaytree.getRoot());
        cout << endl;
        splaytree.insert(45);
        splaytree.display(splaytree.getRoot());
        cout << endl;

        */



       
/*
        BST tree;

        //tree.insert(3);
        tree.insert(6);
        tree.insert(9);
        tree.insert(3);
        tree.insert(7);
        tree.insert(12);
        tree.insert(10);
        tree.insert(14);
        tree.insert(1);
        tree.insert(5);


        tree.display(tree.getRoot());
        cout << endl;

        tree.remove(6);

       // cout << tree.getRoot()->num << endl;
        tree.display(tree.getRoot());
        cout << endl;
*/

        auto start = chrono::steady_clock::now();

        ifstream File;

        if(argc < 2)
            cout << "need file argument" << endl;
        
        File.open(argv[1]);


        BST tree;
        int hold;
        string holdString;
        stringstream ss;

        File >> hold;
        tree.insert(hold);

        getline(File, holdString);

        //cout << "holdString is: " << holdString << endl;

        ss << holdString;

        while(!ss.eof()) {
            ss >> hold;
          //  cout << "hold is: " << hold << endl;
            if(hold != -1)
                tree.insert(hold);
            hold = -1;
        }
        
        //cout << "hold is now: " << endl;
        
        getline(File, holdString);
        //cout << "holdString is now: " << holdString << endl;
        cout << "Initial tree: " << endl;
        tree.display(tree.getRoot());
        cout << endl;
        
        getline(File, holdString);

       // cout << "holdString is: " << holdString << endl;
        stringstream ss2;
        ss2 << holdString;

        while(!ss2.eof()) {
            ss2 >> hold;
         //   cout << "in search while, searching for: " << hold << endl;
            if(hold != -1)
                tree.search(tree.getRoot(), hold);
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
        
       // cout << "About to start removing" << endl;
        while(!ss3.eof()) {
            ss3 >> hold;
          //  cout << "in remove while, removing: " << hold << endl;
            if(hold != -1)
                tree.remove(hold);
            hold = -1;
        }

        cout << "Final tree structure:" << endl;
        tree.display(tree.getRoot());
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