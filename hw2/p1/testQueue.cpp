#pragma once
#include "object.h"
#include "queue.h"
#include <stdlib.h>
#include <iostream>

void FAIL() {   exit(1);    }
void OK(const char* m) { std::cout << m << "\n"; }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }

// //tests strings
// void test1() {
//   String * s = new String("Hello");
//   String * t = new String("World");
//   String * s1 = new String(" Hello ");
//   String * s2 = new String("He");
//   String * u = s->concat(t);
//   t_true(s->equals(s));
//   t_false(s->equals(t));
//   t_false(s->equals(u));
//   t_true(s->compare(s) == 0);
//   t_false(s->compare(t) != 0);
//   t_false(s->equals(s1));
//   t_true(s->equals(s1->trim()));
//   t_true(s->contains(s2));
  
//   OK("1");
// }

// void test1() {
//   Queue * a = new Queue();
//   String * s1 = new String("hey");
//   String * s2 = new String("nick");
//   String * s3 = new String("bye");
//   String * s4 = new String("barry");
//   a->enqueue(s1);
//   a->enqueue(s2);
//   a->enqueue(s3);
//   a->enqueue(s4);
//   t_true(a->size() == 4);
//   a->dequeue();
//   t_true(a->size() == 3);
//   a->dequeue();
//   a->dequeue();
//   t_true(a->size() == 1);
//   String * temp = (String *) a->peek();
//   //printf("%s\n", temp->val_);
//   //t_true(a->peek()->equals(s4));
//   printf("test 1 passed\n");
// }

//tests strings
void test1() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * s1 = new String(" Hello ");
  String * s2 = new String("He");
  String * u = s->concat(t);
  t_true(s->equals(s));
  t_false(s->equals(t));
  t_false(s->equals(u));
  t_true(s->compare(s) == 0);
  t_true(s->compare(t) != 0);
  t_false(s->equals(s1));
  //s1->trim();
  //t_true(s->equals(s1));
  t_true(s->contains(s2));
  
  OK("1");
}

//tests queues
void test2() {
  Queue * a = new Queue();
  Queue * b = new Queue();
  Object * s = new String("Hello");
  Object * t = new String("World");
  Object * s1 = new String("Hello");
  Object * s2 = new String("He");
  a->enqueue(s);
  a->enqueue(t);
  b->enqueue(s1);
  b->enqueue(s2);
  
  t_true((a->peek())->equals(b->peek()));
  t_true((a->dequeue())->equals(b->dequeue()));
  t_false((a->dequeue())->equals(b->dequeue()));
  //t_false((a->peek())->equals(b->peek()));
  t_true((a->size()) == b->size());
  //b->dequeue();
  //t_false((a->size()) == b->size());
  OK("2");
}

//tests queues
void test3() {
  Queue * a = new Queue();
  Queue * b = new Queue();
  Queue * c = new Queue();
  Object * s = new String("Hello");
  Object * t = new String("World");
  Object * s1 = new String("Hello");
  Object * s2 = new String("He");
  a->enqueue(s);
  a->enqueue(t);
  a->enqueue(s1);
  b->enqueue(s1);
  b->enqueue(s2);
  b->enqueue(s2);
  c->enqueue(t);
  c->enqueue(s1);
  /*
    a - "Hello", "World", "Hello"
    b - "Hello", "He", "He"
    c - "World", "Hello"
  */

  t_true((a->peek())->equals(b->peek()));
  t_false(a->equals(c));

  t_true((a->dequeue())->equals(b->dequeue()));
  t_true(a->equals(c));
  t_false(b->equals(c));
  /*
    a - "World", "Hello"
    b - "He", "He"
    c - "World", "Hello"
  */

  t_false((a->dequeue())->equals(b->dequeue()));
  t_false((a->peek())->equals(b->peek()));
  t_false(a->equals(c));
  t_false(a->equals(b));
  t_true((a->size()) == b->size());
  t_false((a->size()) == (c->size()));
  /*
    a - "Hello"
    b - "He"
    c - "World", "Hello"
  */

  b->dequeue();
  t_false((a->size()) == b->size());
  /*
    a - "Hello"
    b - 
    c - "World", "Hello"
  */

  a->dequeue();
  c->dequeue();
  c->dequeue();
  /*
    a - 
    b - 
    c - 
  */

  t_true(a->equals(c));
  t_true(b->equals(c));
  OK("3");
}

int main() {
  test1();
  test2();
  test3();
  return 0;
}
