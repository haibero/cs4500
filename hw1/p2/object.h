#pragma once
#include <iostream>
#include <stdio.h>

class Object {
  public:
    size_t hash_;

    Object() {
    }

    virtual bool equals(Object *other) {
      return this == other;
    }

    size_t hash() {
      if (hash_ == 0) hash_ = hash_me();

      return hash_;
    }

    size_t hash_me() {
      return reinterpret_cast<size_t>(this);
    }
};
