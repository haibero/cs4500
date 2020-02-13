#include "../object.h"
#include "column.h"
#include "schema.h"
/****************************************************************************
 * DataFrame::
 *
 * A DataFrame is table composed of columns of equal length. Each column
 * holds values of the same type (I, S, B, F). A dataframe has a schema that
 * describes it.
 */
class DataFrame : public Object {
 public:

  Schema* schema_;
  Column*** dataframe_;

  /** Create a data frame with the same columns as the given df but with no rows or rownmaes */
  DataFrame(DataFrame& df){
    schema_ = new Schema(*df.schema_);
    dataframe_ = new Column** [100];
    size_t numColPointers = floor((schema_ -> width_) / 100);
    for(int i = 0; i <= numColPointers; i++){
      dataframe_[i] = new Column* [100];
    }
  }

  /** Create a data frame from a schema and columns. All columns are created
    * empty. */
  DataFrame(Schema& schema){
    schema_ = new Schema(schema);
    dataframe_ = new Column** [100];
    size_t numColPointers = floor((schema_ -> width_) / 100);
    for(int i = 0; i <= numColPointers; i++){
      dataframe_[i] = new Column* [100];
    }
  }

  /** Returns the dataframe's schema. Modifying the schema after a dataframe
    * has been created in undefined. */
  Schema& get_schema(){
    return *schema_;
  }

  /** Adds a column this dataframe, updates the schema, the new column
    * is external, and appears as the last column of the dataframe, the
    * name is optional and external. A nullptr colum is undefined. */
  void add_column(Column* col, String* name){
    printf("width_: %zu\n", schema_-> width());
    size_t indexColPointer = floor((schema_ -> width_) / 100);
    size_t indexCol = (schema_ -> width_) % 100;
    if(schema_->width_ != 0 && indexCol == 0){
      dataframe_[indexColPointer] = new Column* [100];
    }
    printf("%zu\n", indexColPointer);
    printf("%zu\n", indexCol);
    dataframe_[indexColPointer][indexCol] = col;
    schema_->add_column(col->get_type(), name);
  }

  /** Return the value at the given column and row. Accessing rows or
   *  columns out of bounds, or request the wrong type is undefined.*/
  int get_int(size_t col, size_t row){
    size_t indexColPointers = floor(col / 100);
    size_t indexCol = col % 100;
    return dataframe_[indexColPointers][indexCol]->as_int()->get(row);
  }

  bool get_bool(size_t col, size_t row){
    size_t indexColPointers = floor(col / 100);
    size_t indexCol = col % 100;
    return dataframe_[indexColPointers][indexCol]->as_bool()->get(row);
  }

  float get_float(size_t col, size_t row){
    size_t indexColPointers = floor(col / 100);
    size_t indexCol = col % 100;
    return dataframe_[indexColPointers][indexCol]->as_float()->get(row);
  }

  String*  get_string(size_t col, size_t row){
    size_t indexColPointers = floor(col / 100);
    size_t indexCol = col % 100;
    return dataframe_[indexColPointers][indexCol]->as_string()->get(row);
  }

  /** Return the offset of the given column name or -1 if no such col. */
  int get_col(String& col){
    return schema_->col_idx(col.c_str());
  }

  /** Return the offset of the given row name or -1 if no such row. */
  int get_row(String& col){
    return schema_->row_idx(col.c_str());
  }

  /** Set the value at the given column and row to the given value.
    * If the column is not  of the right type or the indices are out of
    * bound, the result is undefined. */
  void set(size_t col, size_t row, int val){
    size_t indexColPointers = floor(col / 100);
    size_t indexCol = col % 100;
    dataframe_[indexColPointers][indexCol]->as_int()->set(row, val);
  }

  void set(size_t col, size_t row, bool val){
    size_t indexColPointers = floor(col / 100);
    size_t indexCol = col % 100;
    dataframe_[indexColPointers][indexCol]->as_bool()->set(row, val);
  }

  void set(size_t col, size_t row, float val){
    size_t indexColPointers = floor(col / 100);
    size_t indexCol = col % 100;
    dataframe_[indexColPointers][indexCol]->as_float()->set(row, val);
  }

  void set(size_t col, size_t row, String* val){
    size_t indexColPointers = floor(col / 100);
    size_t indexCol = col % 100;
    dataframe_[indexColPointers][indexCol]->as_string()->set(row, val);
  }
  //
  // /** Set the fields of the given row object with values from the columns at
  //   * the given offset.  If the row is not form the same schema as the
  //   * dataframe, results are undefined.
  //   */
  // void fill_row(size_t idx, Row& row)
  //
  // /** Add a row at the end of this dataframe. The row is expected to have
  //  *  the right schema and be filled with values, otherwise undedined.  */
  // void add_row(Row& row)
  //
  /** The number of rows in the dataframe. */
  size_t nrows(){
    return schema_->length();
  }

  /** The number of columns in the dataframe.*/
  size_t ncols(){
    return schema_->width();
  }
  //
  // /** Visit rows in order */
  // void map(Rower& r)
  //
  // /** Create a new dataframe, constructed from rows for which the given Rower
  //   * returned true from its accept method. */
  // DataFrame* filter(Rower& r)
  //
  // /** Print the dataframe in SoR format to standard output. */
  // void print()
};
