/** 
  * Assignment 4 for COSE213 Data Structures
  *
  * Won-Ki Jeong (wkjeong@korea.ac.kr)
  *
  * 2021. 6. 1
  *
  */
  
#include "LinkedBinaryTree.h"
#include "SearchTree.h" 
#include "AVLTree.h"

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <iostream>
 
using namespace std;
typedef Entry<int, float> EntryType;
void f3(int e, int f, int nElem, SearchTree<EntryType>	st_test, AVLTree<EntryType>	avl, int *key ){
	clock_t tm;
	// Search tree erase and find test
	std::cout << "\n---------------------------\n";
	std::cout << " 3. erase and find randomly   erase : find = " << e << " : " << f << std::endl;
	std::cout << "---------------------------\n";
	
	int e_num , f_num;
	e_num = nElem*e/100;
	f_num = nElem*f/100;
	std::cout << e_num << " " << f_num << std::endl;
	tm = clock();
	
	int num_elem = nElem;
	while(e_num >0 && f_num >0){
		int g = rand()%2;
		if(g){
			st_test.erase(key[num_elem]);
			num_elem++;
			e_num--;
		}
		else{
			st_test.find(key[num_elem]);
			num_elem++;
			f_num--;
		}
	}
	for(int i=0; i<e_num; i++){
		st_test.erase(key[num_elem]);
		num_elem++;
	}
	for(int i=0; i<f_num; i++){
		st_test.find(key[num_elem]);
		num_elem++;
	}

	tm = clock() - tm;
		printf ("[Search Tree : Erase and Find] It took me %f seconds.\n",((float)tm)/(float)CLOCKS_PER_SEC);

	
	e_num = nElem*e/100;
	f_num = nElem*f/100;
	//search tree erase and find test
	tm = clock();

	num_elem = nElem;
	while(e_num >0 && f_num >0){
		int g = rand()%2;
		if(g){
			avl.erase(key[num_elem]);
			num_elem++;
			e_num--;
		}
		else{
			avl.find(key[num_elem]);
			num_elem++;
			f_num--;
		}
	}
	for(int i=0; i<e_num; i++){
		avl.erase(key[num_elem]);
		num_elem++;
	}
	for(int i=0; i<f_num; i++){
		avl.find(key[num_elem]);
		num_elem++;
	}

	tm = clock() - tm;
	printf ("[AVL Tree : Erase and Find] It took me %f seconds.\n\n",((float)tm)/(float)CLOCKS_PER_SEC);


}
int main()
{
	typedef Entry<int, float> EntryType;
	std::cout << "LinkedBinaryTree\n";
	LinkedBinaryTree<EntryType> t;
	
	std::cout << "Size : " << t.size() << std::endl;
	
	t.addRoot();
	
	std::cout << "Size : " << t.size() << std::endl;
	
	
	//
	//
	
	SearchTree<EntryType>	st;
	
	std::cout << "Size : " << st.size() << std::endl;
	st.insert(1, 2.5);
	st.insert(3, 4.5);
	st.insert(7, 5.5);
	st.insert(2, 1.5);
	st.insert(3, 8.5);
	std::cout << "Size : " << st.size() << std::endl;

	for(SearchTree<EntryType>::Iterator it = st.begin(); it != st.end(); ++it)
	{
			std::cout << (*it).key() << " , " << (*it).value() << std::endl;
	}
		
	st.erase(3);
	st.insert(7, 8);
	std::cout << "Size : " << st.size() << std::endl;
	for(SearchTree<EntryType>::Iterator it = st.begin(); it != st.end(); ++it)
	{
			std::cout << (*it).key() << " , " << (*it).value() << std::endl;
	}	
	
	std::cout << "------------" << std::endl;
	
	st.insert(9, 11);
	st.insert(6, 1);
	st.insert(10, 9.5);
	std::cout << "Size : " << st.size() << std::endl;
	for(SearchTree<EntryType>::Iterator it = st.begin(); it != st.end(); ++it)
	{
			std::cout << (*it).key() << " , " << (*it).value() << std::endl;
	}

	std::cout << "------------" << std::endl;

	st.insert(7,7);
	st.insert(8, 10.5);
	st.insert(9, 10);
	st.insert(100,10);
	st.insert(90, 33);
	st.insert(2, 1);
	st.insert(23, 23);	


	std::cout << "Size : " << st.size() << std::endl;
	for(SearchTree<EntryType>::Iterator it = st.begin(); it != st.end(); ++it)
	{
			std::cout << (*it).key() << " , " << (*it).value() << std::endl;
	}
	//
	//
	std::cout << (*st.find(1)).key() <<std::endl;
	AVLTree<EntryType>	avl;
	
	// random test
	int nElem = 1000000; //100; //100000; //100000000;
	
	int *key = new int[nElem*2];
	float *val = new float[nElem*2];
	
	std::srand(std::time(0)); // use current time as seed for random generator
   
		  
	// initialize
	for(int i=0; i<nElem*2; i++)
	{
		key[i] = std::rand();
		val[i] = (float) std::rand()/RAND_MAX * 20000;
	}
	
	clock_t tm;
	
	std::cout << "\n---------------------------\n";
	std::cout << " 1. insert only\n";
	std::cout << "---------------------------\n";
	// Search tree Insert test
	SearchTree<EntryType>	st_test;

	tm =clock();
	for(int i=0; i<nElem; i++){
		st_test.insert(key[i], val[i]);
		
	}
	tm = clock() - tm;
	printf ("[Search Tree : Insert] It took me %f seconds.\n",((float)tm)/(float)CLOCKS_PER_SEC);

  //
  // AVL tree Insert test
  //
    tm = clock();
	for(int i=0; i<nElem; i++)
	{
		avl.insert(key[i], val[i]);
	}
	tm = clock() - tm;
	/*
	std::cout << "------------------------------\n";

	for(AVLTree<EntryType>::Iterator it = avl.begin(); it != avl.end(); ++it)
	{
			std::cout << (*it).key() << " , " << (*it).value() <<std::endl;
	}
		std::cout << "------------------------------\n";
	*/
	printf ("[AVL Tree : Insert] It took me %f seconds.\n",((float)tm)/(float)CLOCKS_PER_SEC);
	
	std::cout << "\n---------------------------\n";
	std::cout << " 2. find only\n";
	std::cout << "---------------------------\n";
	// Search Tree Find Test
	tm =clock();
	for(int i=nElem; i<nElem*2; i++){
		st_test.find(key[i]);
	}
	tm= clock() -tm;
	printf ("[Search Tree : Find] It took me %f seconds.\n",((float)tm)/(float)CLOCKS_PER_SEC);

  //
  // AVL tree Find test
  //	
  
	tm = clock();
	for(int i=nElem; i<nElem*2; i++)
	{
		avl.find(key[i]);
	}
	tm = clock() - tm;
	printf ("[AVL Tree : Find] It took me %f seconds.\n",((float)tm)/(float)CLOCKS_PER_SEC);

	
	f3(20, 80, nElem, st_test, avl, key);
	f3(40, 60, nElem, st_test, avl, key);
	f3(50, 50, nElem, st_test, avl, key);
	f3(60, 40, nElem, st_test, avl, key);
	f3(80, 20, nElem, st_test, avl, key);

	return 0;
}

