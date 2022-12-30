#include "wordfrequency.h"
#include <iostream>
#include <fstream>
#include <sstream>

/** 
  * Assignment 3 for COSE213 Data Structures
  *
  * Won-Ki Jeong (wkjeong@korea.ac.kr)
  *
  * 2021. 5. 9
  *
  */

WordFrequency::WordFrequency()
{
	// ToDo
  map = new WordFreqMap;
  
}

WordFrequency::~WordFrequency()
{
	// ToDo
  //(*map).~HashMap();
}

void WordFrequency::ReadText(const char* filename)
{
	// ToDo
  if(!(*map).isEmpty()){
    map = new WordFreqMap;
  }
  std::ifstream read;
  std::string str;
  read.open(filename);
  if(!read.is_open()){
    std::cout <<"Cannot open the file\n";
    return;
  }

 while(1){  
    if(read.eof()) break;
    getline(read, str, '\n');
    
    for(int i=0; i<str.length(); i++){
      if(!isalpha(str[i])){
        str[i]=' ';
      }
    }
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::istringstream iss(str);
   do{
      std::string sub;
      iss >> sub;
      
      if(sub == "" || sub == "\n") continue;
      else IncreaseFrequency(sub);
      sub.clear();
    }while(iss);
    str.clear();

  }
  read.close();

}

int WordFrequency::GetFrequency(const std::string word)
{
	// ToDo
  WordFreqElem *tmp;
  tmp = (*map).find(word);
  if(tmp) return tmp->val;
  return 0;
}

void WordFrequency::IncreaseFrequency(const std::string word)
{
	// ToDo
  int freq = GetFrequency(word);
  (*map).insert(word, freq+1);

}