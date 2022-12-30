/** 
  * Assignment 3 for COSE213 Data Structures
  *
  * Won-Ki Jeong (wkjeong@korea.ac.kr)
  *
  * 2021. 5. 9
  *
  */
#include <string>
#include <algorithm>

// destructor
template <class HashMapElemType>
HashMap<HashMapElemType>::~HashMap() 
{
	// ToDo
	for(int i=0; i<capacity; i++){
		HashMapElemType *curNode = ht[i];
		HashMapElemType *prevNode;
		while(curNode!=NULL){
			prevNode = curNode;
			curNode = curNode -> link;
			delete prevNode;
		}
		ht[i]=NULL;
	}
	delete[] ht;
}
	
template <class HashMapElemType>
HashMapElemType* 
HashMap<HashMapElemType>::find(const KeyType k) 
{ 
	// ToDo
	unsigned int hash_key = hashfunction(k);
	std::string data = k;
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	if(ht[hash_key%divisor]==NULL) return NULL;

	HashMapElemType *elem = ht[hash_key%divisor];

	while(elem!=NULL){
		if(elem->key == data){
			return elem;
		}
		else elem = elem -> link;
	}
	return NULL;

}
	
template <class HashMapElemType>
void 
HashMap<HashMapElemType>::insert(const KeyType k, const ValType v) 
{
	// ToDo
	unsigned int hash_key = hashfunction(k);
	HashMapElemType *newNode = new HashMapElemType;
	std::string data = k;
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	newNode->key =data;
	newNode->val = v;
	newNode -> link = NULL;

	if(ht[hash_key%divisor]==NULL){
		ht[hash_key%divisor] = newNode;
	}
	else{
		HashMapElemType *curNode = ht[hash_key%divisor];
		HashMapElemType *prevNode;
		while(curNode!=NULL){
			if(curNode -> key ==data){
				curNode -> val = v;
				return;
			}
			prevNode =curNode;
			curNode = curNode -> link;
		}
		prevNode -> link = newNode;
	}
	mapsize++;

}
		
template <class HashMapElemType>
bool 
HashMap<HashMapElemType>::remove(const KeyType k) 
{
	// ToDo	
	unsigned int hash_key = hashfunction(k);
	std::string data = k;
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	if(ht[hash_key%divisor]==NULL) return false;
	else{
		HashMapElemType* delNode = NULL;
		if(ht[hash_key%divisor]->key == data){
			delNode = ht[hash_key%divisor];
			ht[hash_key%divisor] = ht[hash_key%divisor]->link;
			free(delNode);
			mapsize--;
			return true;
		}
		else{
			HashMapElemType *curNode = ht[hash_key%divisor];
			HashMapElemType *nextNode = curNode -> link;
			while(nextNode!=NULL){
				if(nextNode -> key == data){
					curNode -> link = nextNode -> link;
					delNode= nextNode;
					free(delNode);
					mapsize--;
					return true;
				}
				curNode = nextNode;
				nextNode= nextNode -> link;
			}
		}
	}
	return false;
	
}
	
template <class HashMapElemType>
unsigned int 
HashMap<HashMapElemType>::hashfunction(const KeyType k)
{
	// ToDo	
	int hash_val = 0;
	int p = 31;
	std::string data = k;
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	for(int i=0; i<k.length(); i++){
		hash_val += ((hash_val * p )+ (int)data[i]) %divisor;
	}
	return hash_val;
}


template <class HashMapElemType>
void 
HashMap<HashMapElemType>::print()
{
	// ToDo
	struct wordTable{
		KeyType key;
		ValType val;
	};

	wordTable WT[mapsize];
	int WTindex=0;
	for(int i=0; i<capacity; i++){
		if(ht[i]==NULL) continue;
		else{
			HashMapElemType *curNode = ht[i];
			while(curNode!=NULL){
				WT[WTindex].key=curNode->key;
				WT[WTindex].val= curNode->val;
				WTindex++;
				curNode = curNode -> link;

			}
		}
		
	}

	
	for(int i=0; i<WTindex-1; i++){
		for(int j = i+1; j<WTindex; j++){
			wordTable tmp;
			if(WT[i].val < WT[j].val){
				tmp.key = WT[i].key;
				tmp.val = WT[i].val;

				WT[i].key = WT[j].key;
				WT[i].val = WT[j].val;

				WT[j].key = tmp.key;
				WT[j].val = tmp.val;
			}
			else if(WT[i].val == WT[j].val){
				if(WT[i].key > WT[j].key){
					tmp.key = WT[i].key;
					tmp.val = WT[i].val;

					WT[i].key = WT[j].key;
					WT[i].val = WT[j].val;

					WT[j].key = tmp.key;
					WT[j].val = tmp.val;
				}
			}
		}
	}
	
	
	for(int i=0; i<WTindex; i++){
		std::cout << WT[i].key << " : " << WT[i].val<< std::endl;
	}
	
	std::cout << "\n\n";
	
}