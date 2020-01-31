#include <stdlib.h>

class Array : public Object {
  public:
  	size_t len_;
  	size_t count_;
    size_t lastElemIndex_;


    // Constructor
  	Array(size_t len) {
  		len_ = len;
  		count_ = 0;
      lastElemIndex_ = 0;
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
    return array_[index];
  }

  // remove the item at the given index
  Object* remove(size_t index) {
    if(index > len_ -1) {
      exit(1);
    }
    Object* removed = get(index);
    array_[index] = nullptr;
    count_--;

    if(index == lastElemIndex_) {
      lastElemIndex_= getLastIndex();
    }
    return removed;
  }

  void grow(){
    Object** temp_data = new Object* [len_ * 2];
    for(size_t i = 0; i < len_; i++) {
      temp_data[i] = array_[i];
    }
    array_ = temp_data;
    len_ *= 2;
  }

  size_t getLastIndex() {
    for(int i = len_ - 1; i >= 0; i--) {
      if(!array_[i]) {
        return i;
      }
    }
  }

  // append given object to the array if there is space
  // doubles the size of the array if an item occupies the length-1 index
  void append(Object* to_add) {
    if(count_ + 1 >= len_) {
      grow();
    }
    array_[lastElemIndex_ + 1] = to_add;
    lastElemIndex_++;
    count_++;
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
  	int remove(size_t index) {
  		if (index > (len_ - 1)){
  			exit(1);
  		}
  		int removed = get(index);
  		array_[index] = nullptr;
  		count_ -= 1;
  		return removed;
  	}

  	// gets the object from data stored at index
  	int get(size_t index){
      int* elem = array_[index];
      if(elem) {
  		    return *array_[index];
      } else {
        exit(1);
      }
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
  	bool remove(size_t index) {
  		if (index > (len_ - 1)){
  			exit(1);
  		}
  		bool removed = get(index);
  		array_[index] = NULL;
  		count_ = count_ - 1;
  		return removed;
  	}

  	// gets the object from data stored at index
  	bool get(size_t index){
  		return *array_[index];
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
  	float remove(size_t index) {
  		if (index > (len_ - 1)){
  			exit(1);
  		}
  		float removed = get(index);
  		array_[index] = nullptr;
  		count_ = count_ - 1;
  		return removed;
  	}

  	// gets the object from data stored at index
  	float get(size_t index){
  		return *array_[index];
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
    return array_[index];
  }

  // remove the item at the given index
  String* remove(size_t index) {
    if(index > len_ -1) {
      exit(1);
    }
    String* removed = get(index);
    array_[index] = nullptr;
    count_--;

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

  size_t getLastIndex() {
    for(int i = len_ - 1; i >= 0; i--) {
      if(!array_[i]) {
        return i;
      }
    }
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
};

class NodeArray : public Array {
public:
  Node** array_;

  // Constructor
  NodeArray(size_t len) : Array(len) {
    array_ = new Node* [len];
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
    return array_[index];
  }

  // remove the item at the given index
   Node* remove(size_t index) {
    if(index > len_ -1) {
      exit(1);
    }
    Node* removed = get(index);
    array_[index] = nullptr;
    count_--;

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
    len_ *= 2;
  }

  size_t getLastIndex() {
    for(int i = len_ - 1; i >= 0; i--) {
      if(!array_[i]) {
        return i;
      }
    }
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
};
