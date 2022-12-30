#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>

/**
  * Assignment 3 for COSE213 Data Structures
  *
  * Won-Ki Jeong (wkjeong@korea.ac.kr)
  *
  * 2021. 5. 9
  *
  */


// Map element
template <class KeyType, class ValType>
class MapElem
{
public:
	typedef KeyType ktype;
	typedef ValType vtype;

	KeyType key;
	ValType val;

	MapElem* link;
};

//
// Map data structure
//
template <class HashMapElemType>
class HashMap
{
public:
	typedef typename HashMapElemType::ktype KeyType;
	typedef typename HashMapElemType::vtype ValType;

	// constructor
	HashMap(unsigned int c = 1000) {
		mapsize  = 0;
		capacity = c;
		divisor  = c - (1-c%2); // biggest odd number smaller than c
		ht = new HashMapElemType* [capacity];
		for(int i=0; i<capacity; i++) ht[i] = NULL;
	};

	// destructor
	~HashMap();

	// Modify below functions
	int size() { return mapsize; };

	bool isEmpty() { return (mapsize == 0); };

	// ToDo
	HashMapElemType* find(const KeyType k);

	void insert(const KeyType k, const ValType v);

	bool remove(const KeyType k);

	void print();

private: // Member function
	// Hash function
	unsigned int hashfunction(const KeyType k);

private: // Member variables
	// Hash Table
	HashMapElemType** ht;

	unsigned int mapsize, capacity, divisor;
};

#ifndef HASHMAP_HPP
#define HASHMAP_HPP
#include "map.txx"
#endif

#endif
