#include <iostream>
#include "BinarySearchTree.h"
#include "AvlTree.h"
using namespace std;

    // Test program
int main( )
{
    BinarySearchTree<int> t;
//    int NUMS = 400000;
    int NUMS = 10;
    const int GAP  = 3 ;
    const int CAP  = 19;
    int i;
    int key ;

    key = CAP/2;
    for( i = 1 ; i <= NUMS ; i++ ){
        key = (key + GAP) % CAP ;
        t.insert( key );
    }




    AvlTree<int> a;
//    int NUMS = 400000;
    int NUM = 10;
    const int gap  = 3 ;
    const int cap  = 19;
    int k;
    int Key ;

    Key = cap/2;
    for( k = 1 ; k <= NUM ; k++ ){
        Key = (Key + gap) % cap ;
        a.insert( Key );
    }

   cout << "The height of the binary tree is " << t.height() << endl;
   cout << "The height of the AVL tree is " << a.height() << endl;



return 0;

}
