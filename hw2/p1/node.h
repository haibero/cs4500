//Node class to implement a map
class Node : public Object {
public:
  Object* key_;
  Object* value_;
  Node* next_;

  Node() {
    key_ = new Object();
    value_ = new Object();
    next_ = NULL;
    hash_ = hash();
  }
  //Node contructor
  Node(Object* key, Object* value) {
    key_ = key;
    value_ = value;
    next_ = NULL;
    hash_ = hash();
  }

  Node(String* key, String* value) {
    key_ = key;
    value_ = value;
    next_ = NULL;
    hash_ = hash();
  }

  //Gets the key of this node
  //Returns: Object*
  Object* getKey() {
    return key_;
  }

  //Gets the value of this node
  //Returns: Object*
  Object* getValue() {
    return value_;
  }

  //Sets the value of this node
  void setValue(Object* value) {
    value_ = value;
  }

  //Gets the next node
  //Returns Node*
  Node* getNext(){
    return next_;
  }

  //Sets the next node to be linked
  void setNext(Node* next) {
    next_ = next;
  }

  size_t hash() {
    if (hash_ == 0) hash_ = key_ -> hash_me();
    return hash_;
  }

};
