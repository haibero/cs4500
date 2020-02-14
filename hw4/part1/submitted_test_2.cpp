#include <gtest/gtest.h>
#include "dataframe.h" 

#define GT_TRUE(a)   ASSERT_EQ((a),true)
#define GT_FALSE(a)  ASSERT_EQ((a),false)
#define GT_EQUALS(a, b)   ASSERT_EQ(a, b)
#define ASSERT_EXIT_ZERO(a)  \
  ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*")

void test() {
  Schema s("SSIFF");

  DataFrame df(s);
  for(size_t i = 0; i <  50; i++) {
    if(i % 2 == 0){
      IntColumn* i = new IntColumn();
      df.add_column(i, nullptr);
    }else{
      if (i % 3 == 0)
      {
        BoolColumn* b = new BoolColumn();
        df.add_column(b, nullptr);
      }else{
        StringColumn* s = new StringColumn();
        df.add_column(s, nullptr);
      }
    }
  }
  GT_EQUALS(s.col_type(5+2), 'I');
  GT_EQUALS(s.col_type(5+4), 'I');
  GT_EQUALS(s.col_type(5+3), 'B');
  GT_EQUALS(s.col_type(5+9), 'B');
  GT_EQUALS(s.col_type(5+19), 'S');
  GT_EQUALS(s.col_type(5+23), 'S');
  exit(0);
}

TEST(a4, t3){ ASSERT_EXIT_ZERO(test); }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}