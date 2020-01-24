#include "object.h"

class Node {
public:
  Object key_;
  Object value_;
  Node* next_;

  Node() {
    key_ = new Object();
    value_ = new Object();
    next_ = NULL;
  }

  Object getKey() {
    return key_;
  }

  Object getValue() {
    return value_;
  }

  void setValue(Object value) {
    value_ = value;
  }

  Node* getNext(){
    return next_;
  }

  void setNext(Node* next) {
    next_ = next;
  }
};
