#pragma once
#include <stdint.h>
#include <stdarg.h>
#include <cmath>
#include "../object.h"
#include "../string.h"


/**************************************************************************
 * Column ::
 * Represents one column of a data frame which holds values of a single type.
 * This abstract class defines methods overriden in subclasses. There is
 * one subclass per element type. Columns are mutable, equality is pointer
 * equality. */
class IntColumn;
class BoolColumn;
class FloatColumn;
class StringColumn;


class Column : public Object {
 public:
  size_t size_;
  char* type_;

  Column(size_t size) {
    size_ = size;
  }

  Column() {
    size_ = 0;
  }
  /** Type converters: Return same column under its actual type, or
   *  nullptr if of the wrong type.  */
  virtual IntColumn* as_int() {}
  virtual BoolColumn*  as_bool() {}
  virtual FloatColumn* as_float() {}
  virtual StringColumn* as_string() {}

  /** Type appropriate push_back methods. Calling the wrong method is
    * undefined behavior. **/
  virtual void push_back(int val) {
  }

  virtual void push_back(bool val) {

  }
  virtual void push_back(float val) {

  }
  virtual void push_back(String* val) {

  }

 /** Returns the number of elements in the column. */
  virtual size_t size() {
    return size_;
  }

  /** Return the type of this column as a char: 'S', 'B', 'I' and 'F'. */
  char get_type() {
    return *(this -> type_);
  }
};

/*************************************************************************
 * IntColumn::
 * Holds int values.
 */
class IntColumn : public Column {
 public:
  int** array_;

  IntColumn() : Column() {
    //Starting with 100 points
    array_ = new int* [100];
    size_t arrPointerIndex = floor(log2(size_));
    size_t arrIndex = (size_ % (int)(pow(2.0, arrPointerIndex)));
    for(size_t i = 0; i <= arrPointerIndex; i++){
      size_t indexForEach = pow(2.0, i);
      array_[i] = new int [indexForEach];
    }
    type_ = "I";
  }

  IntColumn(int n, ...) : Column(n) {
    array_ = new int* [100];
    type_ = "I";
    //Number of pointers in this array of pointers
    //size_t numArrayPointers = floor(n / 100);
    size_t numArrayPointers = floor(log2(size_));
    //Allocates the correct number of array pointers
    for(int i = 0; i <= numArrayPointers; i++){
      size_t indexForEach = pow(2.0, i);
      array_[i] = new int [indexForEach];
    }

    //Start to read the variable list
    va_list v1;
    va_start(v1,n);

    //Fills the array of array pointers
    for(int i = 0; i <= n; i++) {
      size_t arrPointerIndex = floor(log2(i));
      size_t arrIndex = (i % (int)(pow(2.0, arrPointerIndex)));
      array_[arrPointerIndex][arrIndex] = va_arg(v1, int);
    }

    va_end(v1);
  }

  int get(size_t idx) {
    size_t arrPointerIndex = floor(log2(idx));
    size_t arrIndex = (idx %  (int)(pow(2.0, arrPointerIndex)));
    return array_[arrPointerIndex][arrIndex];
  }

  IntColumn* as_int() {
    return this;
  }

  /** Set value at idx. An out of bound idx is undefined.  */
  void set(size_t idx, int val) {
    size_t arrPointerIndex = floor(log2(idx));
    size_t arrIndex = (idx % (int)(pow(2.0, arrPointerIndex)));
    array_[arrPointerIndex][arrIndex] = val;
  }
  size_t size() {
    return size_;
  }

  void push_back(int val) {
    size_t arrPointerIndex = floor(log2(size_));
    size_t arrIndex = (size_ % (int)(pow(2.0, arrPointerIndex)));
    if(size_ != 0 && arrIndex == 0){
      size_t newIndex = pow(2.0, arrPointerIndex);
      array_[arrPointerIndex] = new int [newIndex];
    }
    array_[arrPointerIndex][arrIndex] = val;
    size_++;
  }
};

/*************************************************************************
 * BoolColumn::
 * Holds bool values.
 */
class BoolColumn : public Column {
 public:
  bool** array_;

  BoolColumn() : Column() {
    //Starting with 100 points
    array_ = new bool* [100];
    size_t arrPointerIndex = floor(log2(size_));
    size_t arrIndex = (size_ % (int)(pow(2.0, arrPointerIndex)));
    for(size_t i = 0; i <= arrPointerIndex; i++){
      size_t indexForEach = pow(2.0, i);
      array_[i] = new bool [indexForEach];
    }
    type_ = "B";
  }

  BoolColumn(int n, ...) : Column(n) {
    array_ = new bool* [100];
    type_ = "B";
    //Number of pointers in this array of pointers
    //size_t numArrayPointers = floor(n / 100);
    size_t numArrayPointers = floor(log2(size_));
    //Allocates the correct number of array pointers
    for(int i = 0; i <= numArrayPointers; i++){
      size_t indexForEach = pow(2.0, i);
      array_[i] = new bool [indexForEach];
    }

    //Start to read the variable list
    va_list v1;
    va_start(v1,n);

    //Fills the array of array pointers
    for(int i = 0; i <= n; i++) {
      size_t arrPointerIndex = floor(log2(i));
      size_t arrIndex = (i % (int)(pow(2.0, arrPointerIndex)));
      array_[arrPointerIndex][arrIndex] = va_arg(v1, int);
    }

    va_end(v1);
    }

  bool get(size_t idx) {
    size_t arrPointerIndex = floor(log2(idx));
    size_t arrIndex = (idx %  (int)(pow(2.0, arrPointerIndex)));
    return array_[arrPointerIndex][arrIndex];
  }

  BoolColumn* as_bool() {
    return this;
  }

  /** Set value at idx. An out of bound idx is undefined.  */
  void set(size_t idx, bool val) {
    size_t arrPointerIndex = floor(log2(idx));
    size_t arrIndex = (idx % (int)(pow(2.0, arrPointerIndex)));
    array_[arrPointerIndex][arrIndex] = val;
  }
  size_t size() {
    return size_;
  }

  void push_back(int val) {
    size_t arrPointerIndex = floor(log2(size_));
    size_t arrIndex = (size_ % (int)(pow(2.0, arrPointerIndex)));
    if(size_ != 0 && arrIndex == 0){
      size_t newIndex = pow(2.0, arrPointerIndex);
      array_[arrPointerIndex] = new bool [newIndex];
    }
    array_[arrPointerIndex][arrIndex] = val;
    size_++;
  }
};

/*************************************************************************
 * FloatColumn::
 * Holds float values.
 */
class FloatColumn : public Column {
 public:
  float** array_;

  FloatColumn() : Column() {
    array_ = new float* [100];
    size_t arrPointerIndex = floor(log2(size_));
    size_t arrIndex = (size_ % (int)(pow(2.0, arrPointerIndex)));
    for(size_t i = 0; i <= arrPointerIndex; i++){
      size_t indexForEach = pow(2.0, i);
      array_[i] = new float [indexForEach];
    }
    type_ = "F";
  }
  FloatColumn(int n, ...) : Column(n) {
    array_ = new float* [100];
    type_ = "F";
    //Number of pointers in this array of pointers
    //size_t numArrayPointers = floor(n / 100);
    size_t numArrayPointers = floor(log2(size_));
    //Allocates the correct number of array pointers
    for(int i = 0; i <= numArrayPointers; i++){
      size_t indexForEach = pow(2.0, i);
      array_[i] = new float [indexForEach];
    }

    //Start to read the variable list
    va_list v1;
    va_start(v1,n);

    //Fills the array of array pointers
    for(int i = 0; i <= n; i++) {
      size_t arrPointerIndex = floor(log2(i));
      size_t arrIndex = (i % (int)(pow(2.0, arrPointerIndex)));
      array_[arrPointerIndex][arrIndex] = va_arg(v1, int);
    }

    va_end(v1);
    }


  float get(size_t idx) {
    size_t arrPointerIndex = floor(log2(idx));
    size_t arrIndex = (idx %  (int)(pow(2.0, arrPointerIndex)));
    return array_[arrPointerIndex][arrIndex];
  }


  FloatColumn* as_float() {
    return this;
  }


  /** Set value at idx. An out of bound idx is undefined.  */
  void set(size_t idx, float val) {
    size_t arrPointerIndex = floor(log2(idx));
    size_t arrIndex = (idx % (int)(pow(2.0, arrPointerIndex)));
    array_[arrPointerIndex][arrIndex] = val;
  }


  size_t size() {
    return size_;
  }

  void push_back(float val) {
    size_t arrPointerIndex = floor(log2(size_));
    size_t arrIndex = (size_ % (int)(pow(2.0, arrPointerIndex)));
    if(size_ != 0 && arrIndex == 0){
      size_t newIndex = pow(2.0, arrPointerIndex);
      array_[arrPointerIndex] = new float [newIndex];
    }
    array_[arrPointerIndex][arrIndex] = val;
    size_++;
  }
};

/*************************************************************************
 * StringColumn::
 * Holds string pointers. The strings are external.  Nullptr is a valid
 * value.
 */
class StringColumn : public Column {
 public:
  String*** array_;

  StringColumn() : Column() {
    //Starting with 100 points
    array_ = new String** [100];
    size_t arrPointerIndex = floor(log2(size_));
    size_t arrIndex = (size_ % (int)(pow(2.0, arrPointerIndex)));
    for(size_t i = 0; i <= arrPointerIndex; i++){
      size_t indexForEach = pow(2.0, i);
      array_[i] = new String* [indexForEach];
    }
    type_ = "S";
  }

  StringColumn(int n, ...) : Column(n) {
    array_ = new String** [100];
    type_ = "S";
    //Number of pointers in this array of pointers
    size_t numArrayPointers = floor(log2(size_));
    //Allocates the correct number of array pointers
    for(size_t i = 0; i <= numArrayPointers; i++){
      size_t indexForEach = pow(2.0, i);
      array_[i] = new String* [indexForEach];
    }

    //Start to read the variable list
    va_list v1;
    va_start(v1,n);

    //Fills the array of array pointers
    for(size_t i = 0; i <= n; i++) {
      size_t arrPointerIndex = floor(log2(i));
      size_t arrIndex = (i % (int)(pow(2.0, arrPointerIndex)));
      array_[arrPointerIndex][arrIndex] = va_arg(v1, String*);
    }
    va_end(v1);
  }


  StringColumn* as_string() {
    return this;
  }

  /** Returns the string at idx; undefined on invalid idx.*/
  String* get(size_t idx) {
    size_t arrPointerIndex = floor(log2(idx));
    size_t arrIndex = (idx %  (int)(pow(2.0, arrPointerIndex)));
    return array_[arrPointerIndex][arrIndex];
  }


  /** Out of bound idx is undefined. */
  void set(size_t idx, String* val) {
    size_t arrPointerIndex = floor(log2(idx));
    size_t arrIndex = (idx % (int)(pow(2.0, arrPointerIndex)));
    array_[arrPointerIndex][arrIndex] = val;
  }
  size_t size() {
    return size_;
  }

  void push_back(String* val) {
    size_t arrPointerIndex = floor(log2(size_));
    size_t arrIndex = (size_ % (int)(pow(2.0, arrPointerIndex)));
    if(size_ != 0 && arrIndex == 0){
      size_t newIndex = pow(2.0, arrPointerIndex);
      array_[arrPointerIndex] = new String* [newIndex];
    }
    array_[arrPointerIndex][arrIndex] = val;
    size_++;
  }

  // void resize() {
  //   String*** tempArr =
  // }
};
