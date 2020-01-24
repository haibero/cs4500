class Node {
public:
  String* key_;
  Object* value_;
  Node* next_;

  Node() {
    key_ = new String();
    value_ = new Object();
    next_ = NULL;
  }

  Node(String* key, Object* value) {
    key_ = key;
    value_ = value;
    next_ = NULL;
  }

  String* getKey() {
    return key_;
  }

  Object* getValue() {
    return value_;
  }

  void setValue(Object* value) {
    value_ = value;
  }

  Node* getNext(){
    return next_;
  }

  void setNext(Node* next) {
    next_ = next;
  }
};
