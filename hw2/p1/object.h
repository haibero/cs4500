#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>

class Object {
  public:
    size_t hash_;

    Object() {
      hash_ = 0;
    }

    virtual bool equals(Object *other) {
      return this == other;
    }

    size_t hash() {
      if (hash_ == 0) hash_ = hash_me();

      return hash_;
    }

    virtual size_t hash_me() {
      return reinterpret_cast<size_t>(this);
    }
};
