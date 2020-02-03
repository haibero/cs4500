#pragma once
#include "object.h"
#include "string.h"

class Column : public Object 
{
public:
	Column();
	~Column();

};

class StringColumn : public Column
{
public:
	StringColumn(arguments);
	~StringColumn();

	/* data */
};

class BoolColumn : public Column
{
public:
	BoolColumn(arguments);
	~BoolColumn();

	/* data */
};


class IntColumn : public Column
{
public:
	IntColumn(arguments);
	~IntColumn();

	/* data */
};



