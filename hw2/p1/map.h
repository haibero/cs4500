//
// Created by Jiawen Liu on 1/24/20.
//
//
// #ifndef PART2_Map_H
// #define PART2_Map_H
//
// #endif //PART2_Map_H
//


class Map : public Object {
public:
    /**
     * Default constructor that constructs an empty Map with
     * the default initial capacity 16
    */

    NodeArray* elems_;
    ObjArray* keys_;
    float cap_thresh = .75;

    Map() {
      elems_ = new NodeArray(16);
      keys_ = new ObjArray(0);
    }

    /**
     * Destructor that delete Map object
     */
    ~Map() {
      delete elems_;

    }

    /**
     * Returns the number of key-value pairs in this map.
     */
    size_t get_size(){
      return elems_ -> count(); //ask them to return size_t!!!!!
    }

    /**
     * Returns the capacity of the map.
     */
    size_t get_capacity(){
      return elems_ -> length(); //ask them to return size_t!!!!
    }

    /**
     * increase or decrease the capacity of the map
     */
    void resize() {
      if(((float) elems_ -> count_ / (float) elems_ -> len_) > cap_thresh) {
        elems_ -> grow();
      }
    }

    /**
     * Put the given key value pair into the map
     * If the key is already associated with a value, the new value should overwrite the previous one
     * @return  void
     */
    void put(Object* key, Object* val){
      size_t index = (key -> hash_) % get_capacity();
      printf("In put, key hash: %ld\n", key -> hash_);
      if(contains_key(key)) {
        remove(key);
      }
      Node* n1 = new Node(key, val);
      elems_-> insert(n1, index);
      resize();
    }


    /**
     * Returns the value of which the specified key is mapped to, or nullptr if this map does not contain the given key
     * @param key   the key whose associated value is to be returned
     * @return  the value mapped to the given key, or nullptr if the key is not found
     */
    Object* get(Object* key) {
      size_t index = (key -> hash_) % get_capacity();
      Node* temp = elems_ -> get(index);
      return temp -> value_;
    }


    /**
     * Returns true if this map contains the given key
     * @param key   The key whose presence in this map is to be tested
     * @return  true if this map contains a mapping for the specified key, otherwise false
     */
    bool contains_key(Object* key) {
      size_t index = (key -> hash_) % get_capacity();
      printf("Contains: %ld \n", key -> hash_);
      printf("Contains index: %ld \n", index);
      //printf("Get: %s", elems_ -> get(index) == nullptr);
      if (elems_ -> get(index)) {// -> key_ == key) {
        return 1;
      } else {
        printf("No key\n");
        return 0;
      }
    }


    /**
     * Removes the mapping for the specified key from this map if present.
     * @param key
     * @return   value associated with the key, or nullptr if the key is not found
     */
    Object* remove(Object* key) {
      printf("Hash: %ld \n", key->hash_);
      size_t index = (key -> hash_) % get_capacity();
      printf("Index: %ld \n", index);
      // printf("%s", elems_ -> get(index));// -> getValue());
      // return elems_ -> remove(index);
    }


    /**
     * @return  a list of the keys contained in this map
     */
    Object** key_set() {
      // for(size_t i = 0; i < l)
    }


    /**
     * @return  a list of values contained in this map
     */
    Object** values() {

    }

    size_t hash() {

    }

    bool equals(Object* object) {

    }
};
