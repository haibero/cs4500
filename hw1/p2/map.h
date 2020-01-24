class Map {
public:
  size_t len_;
  Node** elems_;

  Map(){
    elems_ = NULL;
    len_ = 0;
  }

  void addElement(Node* elem) {
    Node** nodeArr = new Node* [len_ +1];
    if(elems_ == NULL) {
      nodeArr[len_] = elem;
    } else {
      for(size_t i = 0; i < len_; i++) {
        nodeArr[i] = elems_[i];
      }
      nodeArr[len_] = elem;
    }
    len_++;
    elems_ = nodeArr;
  }

  void removeElement(Object* key);
  void getValue(Object* key);
};
