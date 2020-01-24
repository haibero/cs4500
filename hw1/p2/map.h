#include "node.h"

class Map {
public:
  size_t size_;
  Node** elems_;

  Map(size_t size) {
    size_ = size;
    elems_ = (Node**) malloc(sizeof(node*)*size);
     int i;
     for(i=0;i<size;i++)
        elem_[i] = NULL;
    }
};
