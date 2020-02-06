#pragma once
#include <stdarg.h>
#include "object.h"
#include "column.h"



class Dataframe : public Object
{
public:
	Dataframe(Column* column, ...);
	~Dataframe();

	// prints this dataframe
	// this includes column names (or numbers), row names (if present)
	// and all column values
	void print();

	// returns the number of rows in this dataframe
	int nrow();

	// returns the number of columns in this dataframe
	int ncol();

	// determines if each column has a name
	// true if every column has a name, otherwise false
	bool columnNamesExist();

	// returns array of all column names
	// * all columns must have names, should check with 'columnNamesExist()' first
	String** getColumnNames();

	// determines if each row has a name
	// true if every row has a name, otherwise false
	bool rowNamesExist();

	// returns array of all row names
	// * all rows must have names, should check with 'rowNamesExist()' first
	String** getRowNames();

	// column-wise combines df2 to left horizontal end of this dataframe 
	// * both dataframes must have the same number of rows
	void cbind(Dataframe* df2);

	// row-wise combinds df2 to the bottom of this dataframe 
	// * both dataframes must have the same number of columns
	// * each corresponding column number must be of the same type
	void rbind(Dataframe* df2);

	// gets column in dataframe by name
	Column* getColByName(String* columnName);

	// gets column in dataframe by column number 
	// * possible indices: 0 -> (ncol() - 1)
	Column* getColByNum(int columnIndx);

	// gets row (array of 1 element column objects) in dataframe by row name
	Column** getRowByName(String* rowName);

	// gets row (array of 1 element column objects) in dataframe by row number 
	// * possible indices: 0 -> (rcol() - 1)
	Column** getRowByNum(int rowIndx);

};


