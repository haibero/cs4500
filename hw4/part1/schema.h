/**************************************************************************
 * Column ::
 * Represents one column of a data frame which holds values of a single type.
 * This abstract class defines methods overriden in subclasses. There is
 * one subclass per element type. Columns are mutable, equality is pointer
 * equality. */
class Column : public Object {
 public:

  /** Type converters: Return same column under its actual type, or
   *  nullptr if of the wrong type.  */
  virtual IntColumn* as_int()
  virtual BoolColumn*  as_bool()
  virtual FloatColumn* as_float()
  virtual StringColumn* as_string()

  /** Type appropriate push_back methods. Calling the wrong method is
    * undefined behavior. **/
  virtual void push_back(int val)
  virtual void push_back(bool val)
  virtual void push_back(float val)
  virtual void push_back(String* val)

 /** Returns the number of elements in the column. */
  virtual size_t size()

  /** Return the type of this column as a char: 'S', 'B', 'I' and 'F'.
  char get_type()
};

/*************************************************************************
 * IntColumn::
 * Holds int values.
 */
class IntColumn : public Column {
 public:
  IntColumn()
  IntColumn(int n, ...)
  int get(size_t idx)
  IntColumn* as_int()
  /** Set value at idx. An out of bound idx is undefined.  */
  void set(size_t idx, int val)
  size_t size()
};

// Other primitive column classes similar...

/*************************************************************************
 * StringColumn::
 * Holds string pointers. The strings are external.  Nullptr is a valid
 * value.
 */
class StringColumn : public Column {
 public:
  StringColumn()
  StringColumn(int n, ...)
  StringColumn* as_string()
  /** Returns the string at idx; undefined on invalid idx.*/
  String* get(size_t idx)
  /** Out of bound idx is undefined. */
  void set(size_t idx, String* val)
  size_t size()
};


/*************************************************************************
 * Schema::
 * A schema is a description of the contents of a data frame, the schema
 * knows the number of columns and number of rows, the type of each column,
 * optionally columns and rows can be named by strings.
 * The valid types are represented by the chars 'S', 'B', 'I' and 'F'.
 */
class Schema : public Object {
 public:

  /** Copying constructor */
  Schema(Schema& from)

  /** Create an empty schema **/
  Schema()

  /** Create a schema from a string of types. A string that contains
    * characters other than those identifying the four type results in
    * undefined behavior. The argument is external, a nullptr argument is
    * undefined. **/
  Schema(const char* types)

  /** Add a column of the given type and name (can be nullptr), name
    * is external. Names are expectd to be unique, duplicates result
    * in undefined behavior. */
  void add_column(char typ, String* name)

  /** Add a row with a name (possibly nullptr), name is external.  Names are
   *  expectd to be unique, duplicates result in undefined behavior. */
  void add_row(String* name)

  /** Return name of row at idx; nullptr indicates no name. An idx >= width
    * is undefined. */
  String* row_name(size_t idx)

  /** Return name of column at idx; nullptr indicates no name given.
    *  An idx >= width is undefined.*/
  String* col_name(size_t idx)

  /** Return type of column at idx. An idx >= width is undefined. */
  char col_type(size_t idx)

  /** Given a column name return its index, or -1. */
  int col_idx(const char* name)

  /** Given a row name return its index, or -1. */
  int row_idx(const char* name)

  /** The number of columns */
  size_t width()

  /** The number of rows */
  size_t length()
};
