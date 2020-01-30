#pragma once
#include <stdlib.h>
#include "Object.h"

class Array : public Object {
  public:
  	size_t len_;
  	size_t count_;
  	

    // Constructor
  	Array(size_t len) {
  		len_ = len;
  		count_ = 0;
  	}

  	// Destructor
  	virtual ~Array() {}

  	// inserts the given object into the array and returns the array
  	virtual void insert(void* obj, size_t index) {

  	}

  	// remove the item at the given index
  	virtual void* remove(size_t index) {

  	}

  	// returns the length of the array
  	virtual size_t length() {
  		return len_;
  	}
    
  	// returns the number of elements currently in the array (if implementing as resizeable arrayList, count of items may differ from total length)
  	virtual size_t count() {
  		return count_;
  	}

  	// gets the object from data stored at index
  	virtual void* get(size_t index){

  	}

  	virtual void push_back(void* obj){
  		
  	}

};

class IntArray : public Array {
public:
	int** array;

	IntArray(size_t len){
		len_ = len;
		count_ = 0;
		array = new int[len_];
	}

	// inserts the given object into the array and returns the array
  	void insert(void* obj, size_t index) {
  		array[index] = (int) obj;
  	}

  	// remove the item at the given index
  	int* remove(size_t index) {
  		if (index > (len_ - 1)){
  			exit(1);
  		}
  		int* removed = get(index);
  		array[index] = NULL;
  		count_ = count_ - 1;
  		return removed;
  	}

  	// gets the object from data stored at index
  	int* get(size_t index){
  		return array[index];
  	}
};

class BoolArray : public Array {
public:
	bool** array;

	BoolArray(size_t len){
		len_ = len;
		count_ = 0;
		array = new bool[len_];
	}

	// inserts the given object into the array and returns the array
  	void insert(void* obj, size_t index) {
  		array[index] = (bool) obj;
  	}

  	// remove the item at the given index
  	bool* remove(size_t index) {
  		if (index > (len_ - 1)){
  			exit(1);
  		}
  		int* removed = get(index);
  		array[index] = NULL;
  		count_ = count_ - 1;
  		return removed;
  	}

  	// gets the object from data stored at index
  	bool* get(size_t index){
  		return array[index];
  	}

};

class FloatArray : public Array {
public:

	FloatArray(size_t len){
		len_ = len;
		count_ = 0;
		array = new float[len_];
	}

	// inserts the given object into the array and returns the array
  	void insert(void* obj, size_t index) {
  		array[index] = (float) obj;
  	}

  	// remove the item at the given index
  	float* remove(size_t index) {
  		if (index > (len_ - 1)){
  			exit(1);
  		}
  		int* removed = get(index);
  		array[index] = NULL;
  		count_ = count_ - 1;
  		return removed;
  	}

  	// gets the object from data stored at index
  	float* get(size_t index){
  		return array[index];
  	}
};

class StringArray : public Array {
public:

	StringArray(size_t len){
		len_ = len;
		count_ = 0;
	}
};





