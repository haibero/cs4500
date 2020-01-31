#pragma once
#include "object.h"
#include "array.h"

class Queue : public Object {
public:
  size_t FIRST = 0;
  ObjArray* q;


  Queue(){
    q = new ObjArray(8);
  }
  
  /**
   *  adds an object to the end of this queue
   */
  void enqueue(Object* o) {
    q->append(o);
  }
  
  /**
   *  Pops the first object in this queue
   */
  Object* dequeue() {
    Object* removed = q->remove(FIRST);
    ObjArray* new_q = new ObjArray(q->len_);
    for (int i = 0; i < q->count(); ++i)
    {
      new_q->insert(q->get(i+1), i);
    }
    ObjArray* old_q = q;
    q = new_q;
    delete old_q;

    return removed;
  }
  
  /**
   * Returns the first object in this queue without removing.
   */
  Object* peek() {
    if (size() < 1){
      exit(1);
    }
    
    return q->get(FIRST);
  }
  
  /**
   * Returns the size of this queue.
   */
  size_t size() {
    return q->count();
  }
  
  size_t hash() {
    size_t hashNum = 0;
    for (size_t i = 0; i < size(); i++){
      hashNum += q->get(i)->hash();
    }
    return hashNum;
  }
  
  bool equals(Object* other) {
    Queue* otherTemp = dynamic_cast<Queue*>(other);
    if (otherTemp == NULL){
      return false;
    }
    if (size() == otherTemp->size()){
      for (int i = 0; i < size(); i++){
        if (!q->get(i)->equals(otherTemp->q->get(i))){
          return false;
        }
      }
    }else{
      return false;
    }
    
    return true;
  }
  

};
