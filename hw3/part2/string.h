#pragma once
#include "object.h"
#include <cstdlib>
#include <cstring>
#include <cstdio> 


class String : public Object {
public:
  /** CONSTRUCTORS & DESTRUCTORS **/

  /* Creates a String copying s */
  String(char* s);

  /* Copies a String copying the value from s */
  String(String* s);

  /* Clears String from memory */
  ~String();


  /** INHERITED METHODS **/

  /* Inherited from Object, generates a hash for a String */
  size_t hash();

  /* Inherited from Object, checks equality between an String and an Object */
  bool equals(Object* obj);


  /** STRING METHODS **/
  
  /** Compares strings based on alphabetical order
   * < 0 -> this String is less than String s
   * = 0 -> this String is equal to String s
   * > 0 -> this String is greater than String s
   */
  int cmp(String* s);

  /* Creates a new String by combining two existing Strings */
  String* concat(String* s);

  /* Returns the current length of the String */
  size_t size();
};