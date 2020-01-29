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
    Map();

    /**
     * Destructor that delete Map object
     */
    ~Map();

public:
    /**
     * Returns the number of key-value pairs in this map.
     */
    int get_size();

    /**
     * Returns the capacity of the map.
     */
    int get_capacity();

    /**
     * increase or decrease the capacity of the map
     */
    void resize();

    /**
     * Put the given key value pair into the map
     * If the key is already associated with a value, the new value should overwrite the previous one
     * @return  val
     */
    Object* put(Object* key, Object* val);


    /**
     * Returns the value of which the specified key is mapped to, or nullptr if this map does not contain the given key
     * @param key   the key whose associated value is to be returned
     * @return  the value mapped to the given key, or nullptr if the key is not found
     */
    Object* get(Object* key);


    /**
     * Returns true if this map contains the given key
     * @param key   The key whose presence in this map is to be tested
     * @return  true if this map contains a mapping for the specified key, otherwise false
     */
    bool contains_key(Object* key);


    /**
     * Removes the mapping for the specified key from this map if present.
     * @param key
     * @return   value associated with the key, or nullptr if the key is not found
     */
    Object* remove(Object* key);


    /**
     * @return  a list of the keys contained in this map
     */
    Object** key_set();


    /**
     * @return  a list of values contained in this map
     */
    Object** values();

    size_t hash();

    bool equals(Object* object);
};