## DataFrame API

# Description
Our DataFrame implementation allows for four types - bool, int, String, and floats.


This DataFrame class will allow us to store data into columns and rows. Each column and row has a label that the user can define. If there is no supplied label, the label will be the index of the row/column. The user can also get a value by entering the index or the column name. We also allow methods to print the whole dataframe.


The DataFrame class will allow for the user to query for data. It will also allow the user to filter the dataframe by a boolean function. The user can also alter the dataframe through an apply function.


# Examples
Column* c1 = new Column(1, 2, 3, 4);


Column* c2 = new Column(true, false, true, false);


Column* c3 = new Column("a", "b", "c", "d");


Column* c4 = new Column("1.2", "2.3", "3.4", "4.5");


c1.setColumnName("c1");


c2.setColumnName("c2");


c3.setColumnName("c3");


c4.setColumnName("c4");

DataFrame* d1 = new DataFrame(c1, c2, c3, c4);


DataFrame* d2 = new DataFrame(c3, c4);

----------------------------------------------------------------------


//Allows the user to get a value at a given index


d1.indxGet(0,0);


1

----------------------------------------------------------------------


//Allows the user to get the names of all the columns


d1.getColumnNames();


"c1, c2, c3, c4"

----------------------------------------------------------------------

//Allows the user to check the number of rows


d1.nrows();


4

----------------------------------------------------------------------

//Allows the user to check all the columns have names


columnNamesExist();


true

----------------------------------------------------------------------


//Allows the user to merge dataframes row wise


d1.rbind(d2);


c1    1    2     3     4


c2    true false true false


c3    "a"   "b"   "c"   "d"


c4    "1.2" "2.3" "3.4" "4.5"


c3    "a"   "b"   "c"   "d"


c4    "1.2" "2.3" "3.4" "4.5"

----------------------------------------------------------------------


//Allows the user to modify a dataframe with a function such as addOne


d1.getColByName(c1).applyToColumn(addOne)


c1    2    3     4     5


c2    true false true false


c3    "a"   "b"   "c"   "d"


c4    "1.2" "2.3" "3.4" "4.5"


c3    "a"   "b"   "c"   "d"


c4    "1.2" "2.3" "3.4" "4.5"

----------------------------------------------------------------------
