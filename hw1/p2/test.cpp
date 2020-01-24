#include "object.h"
#include "string.h"
#include "node.h"
#include "map.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
  String* o1 = new String("Test");
  String* o2 = new String("Value");
  printf("%s", o1 -> val_);
  Node* n1 = new Node(o1, o2);
  Map* m1 = new Map();
  m1 -> addElement(n1);
}
