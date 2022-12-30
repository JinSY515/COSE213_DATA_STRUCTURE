#include "wordfrequency.h"
 
 /** 
  * Assignment 3 for COSE213 Data Structures
  *
  * Won-Ki Jeong (wkjeong@korea.ac.kr)
  *
  * 2021. 5. 9
  *
  */
 
using namespace std;

int main()
{
	typedef MapElem<std::string,int> ElemType;
	typedef HashMap<WordFreqElem> MapType;	

	// Map Test
	MapType myMap;
	
	myMap.insert("Jessica", 43);
	myMap.insert("James", 35);
	myMap.insert("Tom", 12);
	myMap.insert("Kevin", 27);
	myMap.print();

	// Word Frequency Test
	WordFrequency freqChecker;
	
	freqChecker.ReadText("steve_jobs.txt");//"cat_in_the_hat.txt");
	freqChecker.ReadText("input.txt");//"cat_in_the_hat.txt");
	freqChecker.ReadText("cat_in_the_hat.txt");
	
	cout << "# of occurence of word 'tea' : " << freqChecker.GetFrequency("tea") << endl;
	cout << "# of occurence of word 'coffee' : " << freqChecker.GetFrequency("coffee") << endl;
	cout << "# of occurence of word 'you' : " << freqChecker.GetFrequency("you") << endl;
	
	cout << "Print all results" << endl;
	freqChecker.PrintAllFrequency();
	
	
	return 0;
}
