//
// Created by Jiawen Liu on 1/24/20.
//

#ifndef PART2_Map_H
#define PART2_Map_H

#endif //PART2_Map_H

#pragma once;
#include "object.h"

class Map : public Object {
public:
    /**
     * Default constructor that constructs an empty Map with
     * the default initial capacity 16
    */

    Node** elems_;
    Object** keys_;
    size_t capacity_;
    size_t size_;

    Map() {
      for(int i = 0; i < capacity, i++){
        elems_[i] == nullptr;
      }
      keys_ == nullptr;
      capacity_ = 16;
      size_ = 0;
    }

    /**
     * Destructor that delete Map object
     */
    ~Map();

public:
    /**
     * Returns the number of key-value pairs in this map.
     */
    int get_size(){
      return size_; //ask them to return size_t!!!!!
    }

    /**
     * Returns the capacity of the map.
     */
    int get_capacity(){
      return capacity_; //ask them to return size_t!!!!
    }

    /**
     * increase or decrease the capacity of the map
     */
    void resize() {
      //Double if at cap
      //Halve if at
    }

    /**
     * Put the given key value pair into the map
     * If the key is already associated with a value, the new value should overwrite the previous one
     * @return  void
     */
    void put(Object* key, Object* val){
      size_t index = (key -> hash_) % capacity_;
      if(contains_key(key)) {
        remove(key);
        size_--;
      }
      Node* n1 = new Node(key, val);
      elems_-> insert(n1, index);
      size_++;
      if(get_size() >= get_capacity()) {
        resize();
      }
    }


    /**
     * Returns the value of which the specified key is mapped to, or nullptr if this map does not contain the given key
     * @param key   the key whose associated value is to be returned
     * @return  the value mapped to the given key, or nullptr if the key is not found
     */
    Object* get(Object* key) {
      size_t index = (key -> hash_) % capacity_;
      Node* temp = elems_ -> get(index);
      return temp -> val_;
    }


    /**
     * Returns true if this map contains the given key
     * @param key   The key whose presence in this map is to be tested
     * @return  true if this map contains a mapping for the specified key, otherwise false
     */
    bool contains_key(Object* key) {
      // if (get(key) == nullptr) {
      //   return 0;
      // } else {
      //   return 1;
      // }
      return keys_ -> isIn(key);
    }


    /**
     * Removes the mapping for the specified key from this map if present.
     * @param key
     * @return   value associated with the key, or nullptr if the key is not found
     */
    Object* remove(Object* key) {
      keys -> remove(key);
    }


    /**
     * @return  a list of the keys contained in this map
     */
    Object** key_set() {
      for(size_t i = 0; i < l)
    }


    /**
     * @return  a list of values contained in this map
     */
    Object** values();

    size_t hash() {

    }

    bool equals(Object* object);
};
