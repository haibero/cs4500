#include <stdio.h>
#include <string.h>
#include "../string.h"
/*************************************************************************
 * Schema::
 * A schema is a description of the contents of a data frame, the schema
 * knows the number of columns and number of rows, the type of each column,
 * optionally columns and rows can be named by strings.
 * The valid types are represented by the chars 'S', 'B', 'I' and 'F'.
 */
class Schema : public Object {
 public:
   char* columnTypes_;
   String** columnNames_;
   String** rowNames_;
   size_t width_;
   size_t length_;

  /** Copying constructor */
  Schema(Schema& from) {
    columnTypes_ = from.columnTypes_;
    columnNames_ = from.columnNames_;
    width_ = from.width_;
  }

  Schema(Schema& from, bool add_row_info): Schema(from) {
    rowNames_ = from.rowNames_;
    length_ = from.length_;
  }

  /** Create an empty schema **/
  Schema() {
    columnTypes_ = new char [100];
    columnNames_ = new String* [100];
    rowNames_ = new String* [100];
    width_ = 0;
    length_ = 0;
  }

  /** Create a schema from a string of types. A string that contains
    * characters other than those identifying the four type results in
    * undefined behavior. The argument is external, a nullptr argument is
    * undefined. **/
  Schema(const char* types) : Schema() {
    for(size_t i = 0; i < strlen(types); i++) {
      columnTypes_[i] = types[i];
    }
    width_ = strlen(types);
  }

  /** Add a column of the given type and name (can be nullptr), name
    * is external. Names are expectd to be unique, duplicates result
    * in undefined behavior. */
  void add_column(char typ, String* name) {
    width_++;
    columnNames_[width_] = name;
    columnTypes_[width_] = typ;
  }

  /** Add a row with a name (possibly nullptr), name is external.  Names are
   *  expectd to be unique, duplicates result in undefined behavior. */
  void add_row(String* name) {
    length_++;
    rowNames_[length_] = name;
  }

  /** Return name of row at idx; nullptr indicates no name. An idx >= width
    * is undefined. */
  String* row_name(size_t idx) {
    return rowNames_[idx];
  }

  /** Return name of column at idx; nullptr indicates no name given.
    *  An idx >= width is undefined.*/
  String* col_name(size_t idx) {
    return columnNames_[idx];
  }

  /** Return type of column at idx. An idx >= width is undefined. */
  char col_type(size_t idx) {
    return columnTypes_[idx];
  }

  /** Given a column name return its index, or -1. */
  int col_idx(const char* name) {
    for(size_t i = 0; i < width_; i++) {
      if(strcmp(columnNames_[i] -> cstr_, name) == 0) {
        return i;
      }
    }
    return -1;
  }

  /** Given a row name return its index, or -1. */
  int row_idx(const char* name) {
    for(size_t i = 0; i < length_; i++) {
      if(strcmp(rowNames_[i] -> cstr_, name) == 0) {
        return i;
      }
    }
    return -1;
  }

  /** The number of columns */
  size_t width() {
    return width_;
  }

  /** The number of rows */
  size_t length() {
    return length_;
  }
};
