#include <iostream>
#include "BinarySearchTree.h"
#include <time.h>
using namespace std;


double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 

	return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
   }



    // Test program
int main( )
{
//Tall and skinny

    BinarySearchTree<int> T1;

//    cout << "Start of T1 tall and skinny test" << endl;


    for(int i = 1 ; i < 20001 ; i++ ){
        T1.insert(i);
    }

//Realistic and natural tree

    BinarySearchTree<int> T2;

    int NUMS = 20000;
    const int GAP  = 3 ;
    const int CAP  = 20000;
    int key ;

    cout << "Start of BST test" << endl;

    key = CAP/2;


  for( int j = 1 ; j < NUMS+1 ; j++ ){
        key = (key + GAP) % CAP ;
        T2.insert( key );
    }

double total_time_T1 = 0;
double total_time_T2 = 0;

int total_depth_T1 = 0;
int total_depth_T2 = 0;

clock_t start, finish; //used for getting the time

for (int m=1;m<NUMS+1;m++){

	start = clock();
	T1.contains(m);
	finish = clock();
	double T1_time = elapsed_time(start, finish);
        total_depth_T1 += T1.depth(m);


	start = clock();
	T2.contains(m);
	finish = clock();
	double T2_time = elapsed_time(start, finish);
        total_depth_T2 += T2.depth(m);


	total_time_T1 += T1_time;
	total_time_T2 += T2_time;

	cout << "Time taken to find " << m << " in tall and skinny tree (T1) is " << T1_time << " milliseconds."<<endl;
        cout << "Time taken to find " << m << " in realistic BST (T2) is " << T2_time << " milliseconds."<<endl;

}


	double avg_time_T1 = total_time_T1/NUMS;
	double avg_time_T2 = total_time_T2/NUMS;
	int avg_depth_T1 = total_depth_T1/NUMS;
	int avg_depth_T2 = total_depth_T2/NUMS;

        cout << "The total time taken for sequence membership check in tall and skinny tree (T1) is " << total_time_T1 << " milliseconds."<<endl;
        cout << "The total time taken for sequence membership check in tall and skinny tree (T2) is " << total_time_T2 << " milliseconds."<<endl;
        cout << "The average time taken for sequence membership check in tall and skinny tree (T1) is " << avg_time_T1 << " milliseconds."<<endl;
        cout << "The average time taken for sequence membership check in tall and skinny tree (T2) is " << avg_time_T2 << " milliseconds."<<endl;

	cout << "The average depth of search for T1 is " << avg_depth_T1 << endl;
	cout << "The average depth of search for T2 is " << avg_depth_T2 << endl; 

return 0;
}
