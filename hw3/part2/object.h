#pragma once
#include <cstdlib>


class Object {
public:
  /** CONSTRUCTORS & DESTRUCTORS **/

  /* Default Object constructor */
  Object();

  /* Default Object destructor, to be overriden by subclasses */
  virtual ~Object();


  /** VIRTUAL METHODS **/

  /* Returns whether two objects are equal, to be overriden by subclasses */
  virtual bool equals(Object* obj);

  /* Returns an object's hash value. Identical objects should have identical hashes */
  virtual size_t hash();
};




