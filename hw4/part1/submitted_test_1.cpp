#include <gtest/gtest.h>
#include "dataframe.h" 

#define GT_TRUE(a)   ASSERT_EQ((a),true)
#define GT_FALSE(a)  ASSERT_EQ((a),false)
#define GT_EQUALS(a, b)   ASSERT_EQ(a, b)
#define ASSERT_EXIT_ZERO(a)  \
  ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*")

void test() {
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
      r.set(4, true);
    }else{
      r.set(4, false);
    }
    
    df.add_row(r);
  }
  GT_TRUE(df.get_bool((size_t)4, (size_t)0));
  //GT_FALSE(df.get_bool((size_t)1, 4));
  //GT_TRUE(df.get_bool((size_t)7, 4));
  //GT_FALSE(df.get_bool((size_t)60, 4));
  //GT_TRUE(df.get_bool((size_t)993, 4));
  
  exit(0);
}

TEST(a4, t2){ ASSERT_EXIT_ZERO(test); }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}