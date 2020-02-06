#pragma once
#include <stdarg.h>
#include "object.h"
#include "string.h"

class Column : public Object 
{
public:
	Column();
	~Column();

	// determines if a column has a name
	// True if String* type exists, False if null
	bool columnNameExist();

	// gets column's String* type name
	// should check existence with 'columnNameExist()' first 
	String* getColumnName();

	// setter for a column's name
	void setColumnName(String* name);

};

class StringColumn : public Column
{
public:
	StringColumn(String* cell, ...);
	~StringColumn();

	// gets String* cell value at row number in column
	String* get(int row);

	// prints this column of Strings (default will not print name)
	// header will be included if 'true' is passed as arguement
	void printColumn(bool withName = false);

	// determines if the input object is also a StringColumn
	bool typeEqual(Object* column);

	// determines if an input object is equal to this StringColumn
	bool equal(Object* other);
};

class BoolColumn : public Column
{
public:
	BoolColumn(bool cell, ...);
	~BoolColumn();

	// gets bool cell value at row number in column
	bool get(int row);

	// prints this column of bools (default will not print name)
	// header will be included if 'true' is passed as arguement
	void printColumn(bool withName = false);
	
	// determines if the input object is also a BoolColumn
	bool typeEqual(Object* column);

	// determines if an input object is equal to this BoolColumn
	bool equal(Object* other);
};


class IntColumn : public Column
{
public:
	IntColumn(int cell, ...);
	~IntColumn();

	// gets int cell value at row number in column
	int get(int row);

	// prints this column of ints (default will not print name)
	// header will be included if 'true' is passed as arguement
	void printColumn(bool withName = false);
	
	// determines if the input object is also a IntColumn
	bool typeEqual(Object* column);

	// determines if an input object is equal to this IntColumn
	bool equal(Object* other);
};

class FloatColumn : public Column
{
public:
	FloatColumn(int cell, ...);
	~FloatColumn();

	// gets float cell value at row number in column
	float get(int row);

	// prints this column of floats (default will not print name)
	// header will be included if 'true' is passed as arguement 
	void printColumn(bool withName = false);
	
	// determines if the input object is also a FloatColumn
	bool typeEqual(Object* column);

	// determines if an input object is equal to this FloatColumn
	bool equal(Object* other);
};



