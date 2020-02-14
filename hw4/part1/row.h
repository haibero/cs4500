#pragma once
#include "../object.h"
#include "column.h"
/*************************************************************************
 * Row::
 *
 * This class represents a single row of data constructed according to a
 * dataframe's schema. The purpose of this class is to make it easier to add
 * read/write complete rows. Internally a dataframe hold data in columns.
 * Rows have pointer equality.
 */
class Row : public Object {
 public:
  Schema* schema_;
  // Array of Columns, each column of size 1
  Column** cells_;
  size_t idx_;
  /** Build a row following a schema. */
  Row(Schema& scm){
    schema_ = &scm;
    cells_ = new Column* [scm.width()];
  }

  /** Setters: set the given column with the given value. Setting a column with
    * a value of the wrong type is undefined. */
  void set(size_t col, int val){
    cells_[col] = new IntColumn();
    cells_[col]->as_int()->set(0, val);
  }

  void set(size_t col, float val){
    cells_[col] = new FloatColumn();
    cells_[col]->as_float()->set(0, val);
  }
  void set(size_t col, bool val){
    cells_[col] = new BoolColumn();
    cells_[col]->as_bool()->set(0, val);
  }
  /** The string is external. */
  void set(size_t col, String* val){
    cells_[col] = new StringColumn();
    cells_[col]->as_string()->set(0, val);
  }

  /** Set/get the index of this row (ie. its position in the dataframe. This is
   *  only used for informational purposes, unused otherwise */
  void set_idx(size_t idx){
    idx_ = idx;
  }

  size_t get_idx(){
    return idx_;
  }

  /** Getters: get the value at the given column. If the column is not
    * of the requested type, the result is undefined. */
  int get_int(size_t col){
    return cells_[col]->as_int()->get(0);
  }

  bool get_bool(size_t col){
    return cells_[col]->as_bool()->get(0);
  }
  float get_float(size_t col){
    return cells_[col]->as_float()->get(0);
  }

  String* get_string(size_t col){
    return cells_[col]->as_string()->get(0);
  }


  /** Number of fields in the row. */
  size_t width(){
    return schema_->width();
  }

   /** Type of the field at the given position. An idx >= width is  undefined. */
  char col_type(size_t idx){
    return schema_->col_type(idx);
  }

  /** Given a Fielder, visit every field of this row. The first argument is
    * index of the row in the dataframe.
    * Calling this method before the row's fields have been set is undefined. */
  // void visit(size_t idx, Fielder& f)

};
