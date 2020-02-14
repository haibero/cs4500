#pragma once
#include "rower.h"
/*******************************************************************************
 *  PrintRower::
 *  A class for iterating through each row of a data frame. The intent
 *  is that this class should print the values of each row.
 *
 */

 class PrintRower : public Rower {
  public:
    PrintRower() {

    }

    bool accept(Row& r) {
      for(size_t i = 0 ; i < r.width(); i++){
        if(r.col_type(i) == 'I'){
          printf("< %d > ", r.get_int(i));
          continue;
        }
        if(r.col_type(i) == 'S'){
          printf("< %s > ", r.get_string(i)->c_str());
          continue;
        }
        if(r.col_type(i) == 'B'){
          printf("< %d > ", r.get_bool(i));
          continue;
        }
        if(r.col_type(i) == 'F'){
          printf("< %f > ", r.get_float(i));
          continue;
        }
      }
    printf("\n");
    return true;
 }
};
