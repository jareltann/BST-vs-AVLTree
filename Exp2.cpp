#include <iostream>
#include "AvlTree.h"
#include "BinarySearchTree.h"
#include <time.h>
using namespace std;


double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds

        return (finish - start)/(double)(CLOCKS_PER_SEC/1000);
   }



    // Test program
int main( )
{


//Binary Search Tree

    BinarySearchTree<int> T3;

    int NUMS = 20000;
    const int GAP  = 3 ;
    const int CAP  = 20000;
    int key ;

    key = CAP/2;


double total_time_T3 = 0;
clock_t start, finish;
int total_depth_T3 = 0;

  for( int i = 1 ; i < NUMS+1 ; i++ ){
        key = (key + GAP) % CAP ;
	start = clock();
        T3.insert( key );
	finish = clock();
        double T3_time = elapsed_time(start, finish);
	total_time_T3 += T3_time;
    }


for (int m=1;m<NUMS+1;m++){
        total_depth_T3 += T3.depth(m);
}


double total_sequence_T3 = 0;
double T3_max_time = 0;
double T3_sequence_time;
int T3_max_depth = 0;
int T3_current_depth;

for (int a =1 ; a < NUMS+1; a++){

        start = clock();
        T3.contains(a);
        finish = clock();
	T3_current_depth = T3.depth(a);
	T3_sequence_time = elapsed_time(start, finish);
	total_sequence_T3 += T3_sequence_time;

	if (T3_sequence_time > T3_max_time){
		T3_max_time = T3_sequence_time;
	}

	if (T3_current_depth > T3_max_depth){
		T3_max_depth = T3_current_depth;
	}

}

double T3_min_time = T3_max_time;
int T3_min_depth = T3_max_depth;


for (int b =1 ; b < NUMS+1; b++){

        start = clock();
        T3.contains(b);
        finish = clock();
        T3_sequence_time = elapsed_time(start, finish);
	T3_current_depth = T3.depth(b);

        if (T3_sequence_time < T3_min_time){
                T3_min_time = T3_sequence_time;
        }

	if (T3_current_depth < T3_min_depth){
		T3_min_depth = T3_current_depth;
	}

}


double T3_mean_time = total_sequence_T3/NUMS;


//AVL Tree

    AvlTree<int> T4;

    int NUM = 20000;
    const int gap  = 3 ;
    const int cap  = 20000;
    int Key ;

    key = cap/2;

double total_time_T4 = 0;
int total_depth_T4 = 0;


  for( int k = 1 ; k < NUM+1 ; k++ ){
        Key = (Key + gap) % cap ;
        start = clock();
        T4.insert( Key );
        finish = clock();
        double T4_time = elapsed_time(start, finish);
        total_time_T4 += T4_time;
    }


for (int n = 1; n < NUM+1; n++){
        total_depth_T4 += T4.depth(n);
}




double total_sequence_T4 = 0;
double T4_max_time = 0;
double T4_sequence_time;
int T4_max_depth = 0;
int T4_current_depth;

for (int c =1 ; c < NUMS+1; c++){

        start = clock();
        T4.contains(c);
        finish = clock();
        T4_current_depth = T4.depth(c);
        T4_sequence_time = elapsed_time(start, finish);
        total_sequence_T4 += T4_sequence_time;

        if (T4_sequence_time > T4_max_time){
                T4_max_time = T4_sequence_time;
        }

        if (T4_current_depth > T4_max_depth){
                T4_max_depth = T4_current_depth;
        }

}

double T4_min_time = T4_max_time;
int T4_min_depth = T4_max_depth;


for (int d =1 ; d < NUM+1; d++){

        start = clock();
        T4.contains(d);
        finish = clock();
        T4_sequence_time = elapsed_time(start, finish);
        T4_current_depth = T4.depth(d);

        if (T4_sequence_time < T4_min_time){
                T4_min_time = T4_sequence_time;
        }

        if (T4_current_depth < T4_min_depth){
                T4_min_depth = T4_current_depth;
        }

}


double T4_mean_time = total_sequence_T4/NUM;



double T3_avg_time = total_time_T3/NUMS;
double T4_avg_time = total_time_T4/NUM;

int avg_depth_T3 = total_depth_T3/NUMS;
int avg_depth_T4 = total_depth_T4/NUM;

cout << "The average insertion time for Binary Search Tree (T3) is " << T3_avg_time << " milliseconds." << endl;
cout << "The average insertion time for AVL Tree (T4) is " << T4_avg_time << " milliseconds." << endl;
cout << "The height of Binary Search Tree (T3) is " << T3.height() << endl;
cout << "The height of AVL Tree (T4) is " << T4.height() << endl;
cout << "The average key depth of of Binary Search Tree (T3) is " << avg_depth_T3 << endl;
cout << "The average key depth of of AVL Tree (T4) is " << avg_depth_T4 << endl;
cout << "The max time for membership check of Binary Search Tree (T3) is " << T3_max_time << " milliseconds." <<  endl;
cout << "The max time for membership check of AVL Tree (T4) is " << T4_max_time << " milliseconds." <<  endl;
cout << "The min time for membership check of Binary Search Tree (T3) is " << T3_min_time << " milliseconds." <<  endl;
cout << "The min time for membership check of AVL Tree (T4) is " << T4_min_time << " milliseconds." <<  endl;
cout << "The mean time for membership check of Binary Search Tree (T3) is " << T3_mean_time << " milliseconds." <<  endl;
cout << "The mean time for membership check of AVL Tree (T4) is " << T4_mean_time << " milliseconds." <<  endl;
cout << "The max depth of search for membership check of Binary Search Tree (T3) is " << T3_max_depth <<  endl;
cout << "The max depth of search for membership check of AVL Tree (T4) is " << T4_max_depth <<  endl;
cout << "The min depth of search for membership check of Binary Search Tree (T3) is " << T3_min_depth <<  endl;
cout << "The min depth of search for membership check of AVL Tree (T4) is " << T4_min_depth <<  endl;



    return 0;
}
