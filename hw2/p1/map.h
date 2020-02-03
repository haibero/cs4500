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
      elems_ = new NodeArray(32);
      keys_ = new ObjArray(8);
    }

    /**
     * Destructor that delete Map object
     */
    ~Map() {
      delete elems_;
      delete keys_;
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
        reallocate();
      }
    }

    void reallocate() {
      NodeArray* tempArray = new NodeArray(elems_ -> len_);
      for(int i = 0; i < keys_ -> count_; i++) {
        size_t oriIndex = (keys_ -> get(i) -> hash_) % (get_capacity() / 2);
        size_t newIndex = (keys_ -> get(i) -> hash_) % get_capacity();
        tempArray -> insert(elems_ -> get(oriIndex), newIndex);
      }
      elems_ = tempArray;
    }

    /**
     * Put the given key value pair into the map
     * If the key is already associated with a value, the new value should overwrite the previous one
     * @return  void
     */
    void put(Object* key, Object* val){
      size_t index = (key -> hash_) % get_capacity();
      if(contains_key(key)) {
        remove(key);
      }
      Node* n1 = new Node(key, val);
      elems_-> insert(n1, index);
      keys_-> append(key);
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
      if (temp){
        return temp -> value_;
      }
      
      return nullptr;
    }


    /**
     * Returns true if this map contains the given key
     * @param key   The key whose presence in this map is to be tested
     * @return  true if this map contains a mapping for the specified key, otherwise false
     */
    bool contains_key(Object* key) {
      size_t index = (key -> hash_) % get_capacity();
      if (elems_ -> get(index)) {
        if(elems_ -> get(index) -> key_->equals(key)){
          return 1;
        } 
      }
      return 0;
    }


    /**
     * Removes the mapping for the specified key from this map if present.
     * @param key
     * @return   value associated with the key, or nullptr if the key is not found
     */
    Object* remove(Object* key) {
      size_t index = (key -> hash_) % get_capacity();
      keys_ -> remove(keys_ -> index_of(key));
      return elems_ -> remove(index);
    }


    /**
     * @return  a list of the keys contained in this map
     */
    Object** key_set() {
      Object** keys;
      for(size_t i = 0; i < keys_ -> len_; i++ ){
        keys[i] = keys_->get(i);
      }
      return keys;
    }


    /**
     * @return  a list of values contained in this map
     */
    Object** values() {
      Object** value_list = new Object * [keys_->count_];
      for(size_t i = 0; i < keys_ -> count_; i++ ) {
        value_list[i] = get(keys_->get(i));
      }
      return value_list;
    }

    size_t hash() {

    }

    bool equals(Object* object) {

    }
};
