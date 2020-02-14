//#include "schema.h"
//#include "column.h"
#include "dataframe.h"


// #define GT_TRUE(a)   ASSERT_EQ((a),true)
// #define GT_FALSE(a)  ASSERT_EQ((a),false)
// #define GT_EQUALS(a, b)   ASSERT_EQ(a, b)
// #define ASSERT_EXIT_ZERO(a)  \
//   ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*")

void test() {
//  Schema* sc1 = new Schema("SBF");
//   IntColumn* i = new IntColumn(100, 10, 23, 41, 10, 23, 41,10, 23, 41, 10, 23, 41, 10, 23, 41,10, 23, 41, 40, 40,
//   10, 23, 41, 10, 23, 41,10, 23, 41, 10, 23, 41, 10, 23, 41,10, 23, 41, 40, 40,
// 10, 23, 41, 10, 23, 41,10, 23, 41, 10, 23, 41, 10, 23, 41,10, 23, 41, 40, 40,
// 10, 23, 41, 10, 23, 41,10, 23, 41, 10, 23, 41, 10, 23, 41,10, 23, 41, 40, 40,
// 10, 23, 41, 10, 23, 41,10, 23, 41, 10, 23, 41, 10, 23, 41,10, 23, 41, 40, 2, 3);
//   printf("%d\n", i->get(99));
 
//  StringColumn* strCol = new StringColumn(2, new String("test1"), new String("test2"));
//   String* num = strCol -> get(1);
//   strCol -> set(1, new String("test3"));
//   printf("%s \n", num->cstr_);
//   String* num2 = strCol -> get(1);
//   printf("%s \n", num2->cstr_);


//  BoolColumn* boolCol = new BoolColumn(2, true, false);
//   bool b1 = boolCol -> get(1);
//   boolCol -> set(1, true);
//   printf("%d \n", b1);
//   bool b2 = boolCol -> get(1);
//   printf("%d \n", b2);

//  FloatColumn* floatCol = new FloatColumn(2, 2.123, 4.234);
//   printf("Type: %c \n", floatCol -> get_type());
//   printf("Size: %ld \n", floatCol -> size());
//   float f1 = floatCol -> get(0);
//   printf("%f \n", f1);
//   float f2 = floatCol -> get(1);
//   printf("%f \n", f2);
//   printf("Size: %ld \n", floatCol -> size());
//   floatCol -> set(1, 69.42);
//   float f3 = floatCol -> get(1);
//   printf("%f \n", f3);
//   printf("Size: %ld \n", floatCol -> size());
//   floatCol -> push_back(2131.2);
//   float f4 = floatCol -> get(2);
//   printf("%f \n", f4);
//   printf("Size: %ld \n", floatCol -> size());
 //
 //
 //  DataFrame* df1 = new DataFrame(*sc1);
 //
 //
  Schema s("IISFB");

  DataFrame df(s);
  Row  r(df.get_schema());
  String* ss = new String("Test1");
  for(size_t i = 0; i <  1000; i++) {
    r.set(0,(int)i);
    r.set(1,(int)i+1);
    r.set(2, ss);
    r.set(3, (float)4.567);
    if (i % 2 == 0){
      //printf("%zu\n", i);
      r.set(4, true);
    }else{
      r.set(4, false);
    }
    
    df.add_row(r);
  }

  if(df.get_bool(3,4)){
    printf("true\n");
  }else{
    printf("false\n");
  }

  // Schema s("II");
  // DataFrame df(s);
  // Row r(df.get_schema());
  // for(int i = 0; i < 100*100; i++) {
  //   r.set(0, i);
  //   r.set(1, i+1);
  //   df.add_row(r);
  // }
  
  //df.print();
  //assert(df.get_int(0,1) == 1);
  // GT_EQUALS(df.get_int((size_t)0,1), 1);
}
//
// TEST(a4, t1){ ASSERT_EXIT_ZERO(test); }

int main(int argc, char **argv) {
    // testing::InitGoogleTest(&argc, argv);
    // return RUN_ALL_TESTS();
    // int** array_ = new int* [100];
    test();
    // size_t arrPointerIndex = floor(log2(size));
    // size_t arrIndex = (size - (pow(2.0, arrPointerIndex)));
    // size_t indexForEach = pow(2.0 arrPointerIndex);
    // printf("i:%d \n",arrPointerIndex);
    // printf("j:%d \n", arrIndex);
    // printf("index:%f \n", pow(2.0, arrPointerIndex));
    //
    // for(size_t i = 0; i <= arrPointerIndex; i++){
    //   size_t arrIndex = size - pow(i, 2);
    //   // printf("i:%d \n",arrPointerIndex);
    //   // printf("j:%d \n", arrIndex);
    //   // printf("index:%d \n", pow((double)arrPointerIndex, 2.0));
    //   array_[i] = new int [int(pow(arrPointerIndex, 2))];
    // }
    //
    // int** array_ = new int* [100];
    // size_t arrPointerIndex = floor(log2(size));
    // size_t arrIndex = (size - (pow(2.0, arrPointerIndex)));
    // for(size_t i = 0; i <= arrPointerIndex; i++){
    //   size_t indexForEach = pow(2.0, i);
    //   array_[i] = new int [indexForEach];
    //   printf("%d \n",arrPointerIndex);
    //   printf("%d \n",arrIndex);
    //   printf("%d \n",indexForEach);
    // }
    // printf("%d \n",arrPointerIndex);
    // printf("%d \n",arrIndex);
}
