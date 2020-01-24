
- Welcome to our README

- Files (excludes: data.sor, Dockerfile, makefile):
   - missing.py:
        - class: Missing
        - This file holds the definition for our Missing class. The Missing class has been implemented to mimic a
          singleton class structure. The idea behind making the singleton style Missing class was to construct a
          single object instance for our code to assign all missing values in rows to. This implementation gives us
          one unique value for all missing row elements to be identified as, making it very simple to check for
          things like equality.

    - dataframe.py:
        - class: DataFrame
        - This file holds the definition of our DataFrame class. The DataFrame object has been implemented to hold a
          list-of lists to store all rows of the sor and a column type dictionary with the key being the
          column index and the value being the column type (represented in String format). The Dataframe object holds
          methods that take care of individual cell values based on their column and index value, checking if an
          individual cell is missing based on a column and index value, and returning things such a column index's
          type. By adding this functionality to the DataFrame object, we will be easily able to call upon such
          methods to return the results required by the command line args for this assignment.

    - dfBuilder.py:
        - class: DfBuilder
        - This file holds the definition of our DfBuilder class. The DfBuilder object has been implemented to take in
          raw sor text and parse it into a DataFrame of a defined schema. The object starts by taking the rows of raw
          sor string text and formatting it into a list-of list-of-Strings. The builder then proceeds to determining
          the largest column count and sets this as the column length for the 'to-be-built' DataFrame object. From here,
          the DataFrame object construction begins. First, the type of each column is determined. This happens in the
          'get_column_types' method. Starting from the first row, each first non-missing row-index value will be used
          to determine the type of its column. This action will take place until each column index has been assigned a
          type. Upon the DataFrame object's column_type dictionary being set, the row construction will take place in
          the method 'build_dataFrame_rows'. Each row will be iterated through and within that, each index value will
          checked against the type of its column in order to determine if it is a valid type. If a row index cell value
          is the same as its column type, then it will keep its value, type and state, if the value is NOT of the column
          type however then the row index cell value will be replaced with the Missing singleton instance object.

    - dfInterpreter.py:
        - class: DfInterpreter
        - This file holds the definition of our DfInterpreter class. The DfInterpreter object is initialized with a
          DataFrame object and an ArgumentParser of parsed args from the argparse library. This object's role is to
          interpret the command arguments and apply those to the cleaned and formatted sor DataFrame object. All
          interpretation results will be printed to the command line.

    - sorer (main):
        - class: *no class*
        - The sorer file is in charge of three main tasks; Reading the arguments and file, setting off the DfBuilder
          object and setting off the DfInterpreter object. Since the building behavior of the DfBuilder and the
          DfInterpreter are abstracted within their classes, the sorer's only directly implemented functions involve
          parsing the command line arguments and reading the input .sor file. After reading and storing both, the sorer
          will create a DfBuilder object instance with the raw sor string and call the build method. The sorer will then
          create a DfInterpreter object with the DfBuilder's cleaned and parsed dataFrame and the command line
          arguments. The sorer's final purpose is to call the interpret method on the DfInterpreter object and the
          results will be printed to the command line.



