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

    cout << "Start of BSTtest" << endl;

    key = CAP/2;
    for( i = 1 ; i <= NUMS ; i++ ){
        key = (key + GAP) % CAP ;
        t.insert( key );
    }

    if( NUMS < 40 ){
	cout << "Links:"<< endl;
	t.displayLinks();
	}


    AvlTree<int> a;
//    int NUMS = 400000;
    int NUM = 10;
    const int gap  = 3 ;
    const int cap  = 19;
    int k;
    int Key ;

    cout << "Start of AVLtest" << endl;

    Key = cap/2;
    for( k = 1 ; k <= NUM ; k++ ){
        Key = (Key + gap) % cap ;
        a.insert( Key );
    }

    if( NUM < 40 ){
        cout << "Links:"<< endl;
        a.displayLinks();
        }



return 0;

    }
