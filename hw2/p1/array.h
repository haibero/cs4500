#pragma once
#include <stdlib.h>
#include "object.h"
#include "string.h"
#include "node.h"


class Array : public Object {
  public:
  	size_t len_;
  	size_t count_;
    size_t lastElemIndex_;


    // Constructor
  	Array(size_t len) {
      // No size 0 arrays
      // if(len <= 0) {
      //   len_ = 1;
      // } else {
      //   len_ = len;
      // }
      len_ = len;
  		count_ = 0;
      lastElemIndex_ = -1;
  	}

  	// Destructor
    ~Array() {
    }

  	// inserts the given object into the array and returns the array
  	// virtual void insert(void* obj, size_t index) {}

  	// remove the item at the given index
  	//virtual void* remove(size_t index) {
    //}

  	// returns the length of the array
  	virtual size_t length() {
  		return len_;
  	}
    //
  	// returns the number of elements currently in the array (if implementing as resizeable arrayList, count of items may differ from total length)
  	virtual size_t count() {
  		return count_;
  	}

  	// // gets the object from data stored at index
  	// virtual void* get(size_t index){
  	// }


    //Increases the capacity of the array by double
    // virtual void grow(){
    //
    // }

    //Finds the index of the last element in the array
    // virtual size_t getLastIndex() {
    //   return
    // }
};

class ObjArray : public Array {
public:
  Object** array_;

  // Constructor
  ObjArray(size_t len) : Array(len) {
    array_ = new Object* [len];
  }

  void insert(Object* obj, size_t index) {
      if(index > len_ - 1) {
        exit(1);
      }
      array_[index]  = obj;
      count_++;
      if(index > lastElemIndex_) {
        lastElemIndex_ = index;
      }
  }

  Object* get(size_t index){
    if(index > len_ -1) {
      return nullptr;
    }
    return array_[index];
  }

  // remove the item at the given index
  Object* remove(size_t index) {
    if(index > len_ -1) {
      return nullptr;
    }
    Object* removed = get(index);
    array_[index] = nullptr;
    if (removed){
      count_--;
    }

    if(index == lastElemIndex_) {
      lastElemIndex_= getLastIndex();
    }
    return removed;
  }

  size_t index_of(Object* obj) { // Returns the index of the first occurrence of o, or >size() if not there
    for(int i = 0; i < len_; i++) {
      if (get(i)){
        if(obj -> equals(get(i))){
          return i;
        }
      }
    }
    return length() + 1;
  }

  void grow(){
    Object** temp_data = new Object* [len_ * 2];
    for(size_t i = 0; i < len_; i++) {
      temp_data[i] = array_[i];
    }
    array_ = temp_data;
    len_ *= 2;
  }

  // append given object to the array if there is space
  // doubles the size of the array if an item occupies the length-1 index
  void append(Object* to_add) {
    if(count_ + 1 >= len_) {
      grow();
    }
    array_[lastElemIndex_+1] = to_add;
    lastElemIndex_++;
    count_++;
  }

  size_t getLastIndex() {
      for(int i = len_ - 1; i >= 0; i--) {
        if(!array_[i]) {
          return i;
        }
      }
      return -1;
    }
};


class IntArray : public Array {
public:
	int** array_;

	IntArray(size_t len) : Array(len){
		array_ = new int* [len_];
	}

	// inserts the given object into the array and returns the array
  	void insert(int* obj, size_t index) {
      if(index > len_ - 1) {
        exit(1);
      }
      array_[index]  = obj;
      count_++;
      if(index > lastElemIndex_) {
        lastElemIndex_ = index;
      }
  	}

  	// remove the item at the given index
  	int* remove(size_t index) {
  		if (index > (len_ - 1)){
  			return nullptr;
  		}
  		int* removed = get(index);
  		array_[index] = nullptr;
      if (removed){
        count_--;
      }
  		
  		return removed;
  	}

  	// gets the object from data stored at index
  	int* get(size_t index){
      if(index > len_ -1) {
        return nullptr;
      }
      return array_[index];
  	}

    void push_back(int* obj){
      if(count_ + 1 >= len_) {
        grow();
      }
      array_[lastElemIndex_ + 1] = obj;
      lastElemIndex_++;
    }

    void grow(){
      int** temp_data = new int* [len_ * 2];
      for(size_t i = 0; i < len_; i++) {
        temp_data[i] = array_[i];
      }
      array_ = temp_data;
      len_ *= 2;
    }

    // append given object to the array if there is space
    // doubles the size of the array if an item occupies the length-1 index
    void append(int* to_add) {
      if(count_ + 1 >= len_) {
        grow();
      }
      array_[lastElemIndex_ + 1] = to_add;
      lastElemIndex_++;
      count_++;
    }

    size_t getLastIndex() {
      for(int i = len_ - 1; i >= 0; i--) {
        if(!array_[i]) {
          return i;
        }
      }
      return -1;
    }
};

class BoolArray : public Array {
public:
	bool** array_;

	BoolArray(size_t len) : Array(len){
		array_ = new bool* [len_];
	}

	// inserts the given object into the array and returns the array
  	void insert(bool* obj, size_t index) {
      if(index > len_ - 1) {
        exit(1);
      }
      array_[index]  = obj;
      count_++;
      if(index > lastElemIndex_) {
        lastElemIndex_ = index;
      }
  	}

  	// remove the item at the given index
  	bool* remove(size_t index) {
      if (index > (len_ - 1)){
        return nullptr;
      }
      bool* removed = get(index);
      array_[index] = nullptr;
      if (removed){
        count_--;
      }
      
      return removed;
  	}

  	// gets the object from data stored at index
  	bool* get(size_t index){
      if(index > len_ -1) {
        return nullptr;
      }
  		return array_[index];
  	}

    void grow(){
      bool** temp_data = new bool* [len_ * 2];
      for(size_t i = 0; i < len_; i++) {
        temp_data[i] = array_[i];
      }
      array_ = temp_data;
      len_ *= 2;
    }

    // append given object to the array if there is space
    // doubles the size of the array if an item occupies the length-1 index
    void append(bool* to_add) {
      if(count_ + 1 >= len_) {
        grow();
      }
      array_[lastElemIndex_ + 1] = to_add;
      lastElemIndex_++;
      count_++;
    }

    size_t getLastIndex() {
      for(int i = len_ - 1; i >= 0; i--) {
        if(!array_[i]) {
          return i;
        }
      }
      return -1;
    }
};

class FloatArray : public Array {
public:
  float** array_;

	FloatArray(size_t len) : Array(len){
		array_ = new float* [len_];
	}

	// inserts the given object into the array and returns the array
  	void insert(float* obj, size_t index) {
      if(index > len_ - 1) {
        exit(1);
      }
      array_[index]  = obj;
      count_++;
      if(index > lastElemIndex_) {
        lastElemIndex_ = index;
      }
  	}

  	// remove the item at the given index
  	float* remove(size_t index) {
  		if (index > (len_ - 1)){
  			return nullptr;
  		}
  		float* removed = get(index);
  		array_[index] = nullptr;
      if (removed){
        count_--;
      }
  		
  		return removed;
  	}

  	// gets the object from data stored at index
  	float* get(size_t index){
  	  if(index > len_ -1) {
        return nullptr;
      }
      return array_[index];
  	}

    void grow(){
      float** temp_data = new float* [len_ * 2];
      for(size_t i = 0; i < len_; i++) {
        temp_data[i] = array_[i];
      }
      array_ = temp_data;
      len_ *= 2;
    }

    // append given object to the array if there is space
    // doubles the size of the array if an item occupies the length-1 index
    void append(float* to_add) {
      if(count_ + 1 >= len_) {
        grow();
      }
      array_[lastElemIndex_ + 1] = to_add;
      lastElemIndex_++;
      count_++;
    }

    size_t getLastIndex() {
      for(int i = len_ - 1; i >= 0; i--) {
        if(!array_[i]) {
          return i;
        }
      }
      return -1;
    }
};


class StringArray : public Array {
public:
  String** array_;

  // Constructor
  StringArray(size_t len) : Array(len) {
    array_ = new String* [len];
  }

  void insert(String* obj, size_t index) {
      if(index > len_ - 1) {
        exit(1);
      }
      array_[index]  = obj;
      count_++;
      if(index > lastElemIndex_) {
        lastElemIndex_ = index;
      }
  }

  String* get(size_t index){
    if(index > len_ -1) {
      return nullptr;
    }
    return array_[index];
  }

  // remove the item at the given index
  String* remove(size_t index) {
    if(index > len_ -1) {
      return nullptr;
    }
    String* removed = get(index);
    array_[index] = nullptr;
    if (removed){
      count_--;
    }

    if(index == lastElemIndex_) {
      lastElemIndex_= getLastIndex();
    }
    return removed;
  }

  void grow(){
    String** temp_data = new String* [len_ * 2];
    for(size_t i = 0; i < len_; i++) {
      temp_data[i] = array_[i];
    }
    array_ = temp_data;
    len_ *= 2;
  }

  // append given object to the array if there is space
  // doubles the size of the array if an item occupies the length-1 index
  void append(String* to_add) {
    if(count_ + 1 >= len_) {
      grow();
    }
    array_[lastElemIndex_ + 1] = to_add;
    lastElemIndex_++;
    count_++;
  }

  size_t getLastIndex() {
      for(int i = len_ - 1; i >= 0; i--) {
        if(!array_[i]) {
          return i;
        }
      }
      return -1;
    }
};

class NodeArray : public Array {
public:
  Node** array_;

  // Constructor
  NodeArray(size_t len) : Array(len) {
    array_ = new Node* [len];
    for (int i = 0; i < len; i++)
    {
      array_[i] = nullptr;
    }
  }

  ~NodeArray () {
    delete [] array_;
  }

  void insert(Node* obj, size_t index) {
      if(index > len_ - 1) {
        exit(1);
      }
      array_[index]  = obj;
      count_++;
      if(index > lastElemIndex_) {
        lastElemIndex_ = index;
      }
  }

  Node* get(size_t index){
    if(index > len_ -1) {
      return nullptr;
    }

    return array_[index];
  }

  // remove the item at the given index
   Node* remove(size_t index) {
    if(index > len_ -1) {
      return nullptr;
    }
    Node* removed = get(index);
    array_[index] = nullptr;
    if (removed){
      count_--;
    }

    if(index == lastElemIndex_) {
      lastElemIndex_= getLastIndex();
    }
    return removed;
  }

  void grow(){
    Node** temp_data = new Node* [len_ * 2];
    for(size_t i = 0; i < len_; i++) {
      temp_data[i] = array_[i];
    }
    array_ = temp_data;
    delete(temp_data);
    len_ *= 2;
  }

  // append given object to the array if there is space
  // doubles the size of the array if an item occupies the length-1 index
  void append(Node* to_add) {
    if(count_ + 1 >= len_) {
      grow();
    }
    array_[lastElemIndex_ + 1] = to_add;
    lastElemIndex_++;
    count_++;
  }

  size_t getLastIndex() {
      for(int i = len_ - 1; i >= 0; i--) {
        if(!array_[i]) {
          return i;
        }
      }
      return -1;
    }
};
