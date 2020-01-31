#pragma once
#include "object.h"

// lang :: CwC

/**
  * ClassName - purpose and interpretation
  *
  * @author Barry Yung <yung.b@northeastern.edu>
  */


class String: public Object {
  public:
    const char* val_; //Characters of the string
    size_t len_; //Length of the string

    String(){
      val_ = "";
      len_ = 0;
      hash_ = hash();
    }

    String(const char* val) {
      val_ = val;
      len_ = strlen(val);
      hash_ = hash();
    }

    ~String() {
      delete [] val_;
     }

     size_t hash() {
       if (hash_ == 0) hash_ = hash_me();
       return hash_;
     }

     size_t hash_me() {
       size_t hashNum = 0;
       for(size_t i = 0; i < len_; i++){
         hashNum += size_t(val_[i]);
       }

       return hashNum;
     }


     bool equals(Object* o) {
       if(o == nullptr) {
         return false;
       }
       String* temp = dynamic_cast<String*> (o);
       if(temp == nullptr) {
         return false;
       }
       return strcmp(val_, temp -> val_) == 0;
     }

     int cmp(String* const s) {
       return strcmp(val_, s -> val_);
     }

    char get(size_t i) {
      if(i < len_){
      return val_[i];
      }
    }

    String* concat(String* val) {
      size_t newLen = len_ + val -> len_;
      char* newString = new char[newLen];
      for(size_t i = 0; i < len_; i++){
        newString[i] = val_[i];
      }
      for(size_t j = 0; j < val->len_; j++) {
        newString[j + len_] = val -> val_[j];
      }
      return new String(newString);
    }

    size_t size() {
      return len_;
    }

    /**
     * Checks if this String contains the given String.
     */
    bool contains(String* sub) {
      const char* result = strstr(val_, sub->val_);
      if (result){
        return true;
      }
      return false;
    }

     /**
     * Removes leading and trailing spaces from this String
     */
    void trim() {

    }

    /**
     * Alphanumerically ompares the given String to this String
     * Returns 0 if equal, 1 if if the given String is alphumerically higher,
     * or -1 if the given String is alphanumerically lower.
    */
    int compare(String* s) {
      return cmp(s);
    }

};
