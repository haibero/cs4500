#include "helper.h"  // Your file, with any C++ code that you need
#include "object.h"  // Your file with the CwC declaration of Object
#include "string.h"  // Your file with the String class
#include "node.h"
#include <ctype.h>
#include "array.h"


void FAIL() {
	printf("FAILED TEST\n");
	exit(1);
}
void OK(const char* m) { printf("%c\n", *m); }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }


// tests functionality for String class
void test1() {
	String* s1 = new String("abc");
	String* s2 = new String("abc");
	t_true(s1->equals(s2));
	t_false(s1->hash() == s2->hash());

	String* s3 = new String("wow");
	t_false(s1->equals(s3));

	// test cmp
	t_true(s1->cmp(s2) == 0);
	t_false(s1->cmp(s3) == 0);

	// test concat and size
	t_true(s1->size() == 3);

	String* s4 = s1->concat(s2);
	t_true(s4->size() == 6);

	String* s5 = new String("abcabc");
	t_true(s4->cmp(s5) == 0);


	printf("1\n");
	}

// test our StringArray class
void test2() {
	StringArray* a1 = new StringArray(2);
	t_true(a1->length() == 2);

	// test insert and count
	a1->insert(new String("abc"), 0);
	a1->insert(new String("abc"), 1);
	t_true(a1->get(0)->equals(a1->get(1)));
	t_true(a1->count() == 2);
	t_true(a1->length() == 2); // when reaching max capacity, resize the array


	// testing dynamic add
	//a1->insert(new String("123"), 2);
	a1->append(new String("123"));
	t_true(a1->count() == 3);
	t_true(a1->length() == 4);// when reaching max capacity, resize the array


	a1->remove(0);
	t_true(a1->count() == 2);
	a1->insert(new String("cba"), 0);
	t_false(a1->get(0)->equals(a1->get(1)));

	printf("2\n");

}

// test our IntArray class
void test3() {
	IntArray* a1 = new IntArray(2);
	t_true(a1->length() == 2);

	// test insert and count
	a1->insert(new int(10), 0);
	a1->insert(new int(10), 1);
	t_true(a1->get(0) == a1->get(1));
	t_true(a1->count() == 2);
	t_true(a1->length() == 2); // when reaching max capacity, resize the array


	// testing dynamic add
	//a1->insert(new int(20), 2);
	a1->append(new int(20));
	t_true(a1->count() == 3);
	t_true(a1->length() == 4); // when reaching max capacity, resize the array


	a1->remove(0);
	t_true(a1->count() == 2);
	a1->insert(new int(100), 0);
	t_false(a1->get(0) == a1->get(1));

	printf("3\n");

}

// test our BoolArray class
void test4() {
	BoolArray* a1 = new BoolArray(2);

	t_true(a1->length() == 2);


	// test insert and count
	a1->insert(new bool(true), 0);
	a1->insert(new bool(true), 1);
	t_true(a1->get(0) == a1->get(1));
	t_true(a1->count() == 2);
	t_true(a1->length() == 2); // when reaching max capacity, resize the array

	// testing dynamic add
	//a1->insert(new bool(true), 2);
	a1->append(new bool(true));
	t_true(a1->count() == 3);
	t_true(a1->length() == 4); // when reaching max capacity, resize the array

	a1->remove(0);
	t_true(a1->count() == 2);
	a1->insert(new bool(false), 0);
	t_false(a1->get(0) == a1->get(1));

	printf("4\n");

}

// test our FloatArray class
void test5() {
	FloatArray* a1 = new FloatArray(2);
	t_true(a1->length() == 2);

	// test insert and count
	a1->insert(new float(3.1), 0);
	a1->insert(new float(3.1), 1);
	t_true(a1->get(0) == a1->get(1));
	t_true(a1->count() == 2);
	t_true(a1->length() == 2); // when reaching max capacity, resize the array

	// testing dynamic add
	//a1->insert(new float(3.1), 2);
	a1->append(new float(3.1));
	t_true(a1->count() == 3);
	t_true(a1->length() == 4); // when reaching max capacity, resize the arra

	a1->remove(0);
	t_true(a1->count() == 2);
	a1->insert(new float(1.2), 0);
	t_false(a1->get(0) == a1->get(1));

	printf("5\n");

}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();

	return 0;
}
