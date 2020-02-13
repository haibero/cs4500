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
class Column : public Object {
 public:
  size_t size_;

  Column(size_t size) {
    size_ = size;
  }

  Column() {
    size_ = 0;
  }
  /** Type converters: Return same column under its actual type, or
   *  nullptr if of the wrong type.  */
  // virtual IntColumn* as_int();
  // virtual BoolColumn*  as_bool();
  // virtual FloatColumn* as_float();
  // virtual StringColumn* as_string();

  /** Type appropriate push_back methods. Calling the wrong method is
    * undefined behavior. **/
  // virtual void push_back(int val);
  // virtual void push_back(bool val);
  // virtual void push_back(float val);
  // virtual void push_back(String* val);

 /** Returns the number of elements in the column. */
  virtual size_t size() {
    return size_;
  }

  /** Return the type of this column as a char: 'S', 'B', 'I' and 'F'. */
  char get_type();
};

/*************************************************************************
 * IntColumn::
 * Holds int values.
 */
class IntColumn : public Column {
 public:
  int** array_;

  IntColumn() : Column() {
    array_ = new int* [100];
  }

  IntColumn(int n, ...) : Column(n) {
    array_ = new int* [100];
    //Number of pointers in this array of pointers
    size_t numArrayPointers = floor(n / 100);
    //Allocates the correct number of array pointers
    for(int i = 0; i <= numArrayPointers; i++){
      array_[i] = new int [100];
    }

    //Start to read the variable list
    va_list v1;
    va_start(v1,n);

    //Fills the array of array pointers
    for(int i = 0; i <= n; i++) {
      int arrPointerIndex = floor(i/100);
      int arrIndex = i%100;
      array_[arrPointerIndex][arrIndex] = va_arg(v1, int);
    }

    va_end(v1);
    // if(size_ != 0 && size % 100 == 0){
    //   array_[size % 100] = new int* [100]
    // }
  }

  int get(size_t idx) {
    size_t arrPointerIndex = floor(idx/100);
    size_t arrIndex = idx%100;
    return array_[arrPointerIndex][arrIndex];
  }

  IntColumn* as_int();

  /** Set value at idx. An out of bound idx is undefined.  */
  void set(size_t idx, int val) {
    size_t arrPointerIndex = floor(idx/100);
    size_t arrIndex = idx%100;
    array_[arrPointerIndex][arrIndex] = val;
  }
  size_t size() {
    return size_;
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
    array_ = new bool* [100];
  }

  BoolColumn(bool n, ...) : Column(n) {
    array_ = new bool* [100];
    //Number of pointers in this array of pointers
    size_t numArrayPointers = floor(n / 100);
    //Allocates the correct number of array pointers
    for(size_t i = 0; i <= numArrayPointers; i++){
      array_[i] = new bool [100];
    }

    //Start to read the variable list
    va_list v1;
    va_start(v1,n);

    //Fills the array of array pointers
    for(size_t i = 0; i <= n; i++) {
      size_t arrPointerIndex = floor(i/100);
      size_t arrIndex = i%100;
      array_[arrPointerIndex][arrIndex] = va_arg(v1, bool);
    }

    va_end(v1);
  }

  bool get(size_t idx) {
    size_t arrPointerIndex = floor(idx/100);
    size_t arrIndex = idx%100;
    return array_[arrPointerIndex][arrIndex];
  }

  BoolColumn* as_bool();

  /** Set value at idx. An out of bound idx is undefined.  */
  void set(size_t idx, bool val) {
    size_t arrPointerIndex = floor(idx/100);
    size_t arrIndex = idx%100;
    array_[arrPointerIndex][arrIndex] = val;
  }
  size_t size() {
    return size_;
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
  }

  FloatColumn(float n, ...) : Column(n) {
    array_ = new float* [100];
    //Number of pointers in this array of pointers
    size_t numArrayPointers = floor(n / 100);
    //Allocates the correct number of array pointers
    for(size_t i = 0; i <= numArrayPointers; i++){
      array_[i] = new float [100];
    }

    //Start to read the variable list
    va_list v1;
    va_start(v1,n);

    //Fills the array of array pointers
    for(size_t i = 0; i <= n; i++) {
      size_t arrPointerIndex = floor(i/100);
      size_t arrIndex = i%100;
      array_[arrPointerIndex][arrIndex] = va_arg(v1, double);
    }
    va_end(v1);
  }


  float get(size_t idx) {
    size_t arrPointerIndex = floor(idx/100);
    size_t arrIndex = idx%100;
    return array_[arrPointerIndex][arrIndex];
  }


  FloatColumn* as_float();


  /** Set value at idx. An out of bound idx is undefined.  */
  void set(size_t idx, float val) {
    size_t arrPointerIndex = floor(idx/100);
    size_t arrIndex = idx%100;
    array_[arrPointerIndex][arrIndex] = val;
  }


  size_t size() {
    return size_;
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
    array_ = new String** [100];
  }

  StringColumn(int n, ...) : Column(n) {
    array_ = new String** [100];
    //Number of pointers in this array of pointers
    size_t numArrayPointers = floor(n / 100);
    //Allocates the correct number of array pointers
    for(size_t i = 0; i <= numArrayPointers; i++){
      array_[i] = new String* [100];
    }

    //Start to read the variable list
    va_list v1;
    va_start(v1,n);

    //Fills the array of array pointers
    for(size_t i = 0; i <= n; i++) {
      size_t arrPointerIndex = floor(i/100);
      size_t arrIndex = i%100;
      array_[arrPointerIndex][arrIndex] = va_arg(v1, String*);
    }
    va_end(v1);
  }


  StringColumn* as_string();

  /** Returns the string at idx; undefined on invalid idx.*/
  String* get(size_t idx) {
    size_t arrPointerIndex = floor(idx/100);
    size_t arrIndex = idx%100;
    return array_[arrPointerIndex][arrIndex];
  }


  /** Out of bound idx is undefined. */
  void set(size_t idx, String* val) {
    size_t arrPointerIndex = floor(idx/100);
    size_t arrIndex = idx%100;
    array_[arrPointerIndex][arrIndex] = val;
  }
  size_t size() {
    return size_;
  }
};
