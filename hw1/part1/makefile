build:
	echo "Nothing to build, using Python. All good."
test:
	chmod a+x sorer
	./sorer -f "data.sor" -from 0 -len 200 -print_col_type 0        #expected return: BOOL
	./sorer -f "data.sor" -from 0 -len 200 -print_col_type 1        #expected return: INTEGER
	./sorer -f "data.sor" -from 0 -len 200 -print_col_type 2        #expected return: STRING
	./sorer -f "data.sor" -from 0 -len 200 -print_col_type 3        #expected return: FLOAT
	./sorer -f "data.sor" -from 0 -len 200 -print_col_type 4        #expected return: INTEGER
	./sorer -f "data.sor" -from 0 -len 200 -print_col_type 5        #expected return: STRING
	./sorer -f "data.sor" -from 0 -len 200 -is_missing_idx 0 0      #expected return: 0
	./sorer -f "data.sor" -from 0 -len 200 -is_missing_idx 0 1      #expected return: 0
	./sorer -f "data.sor" -from 0 -len 200 -is_missing_idx 0 2      #expected return: 0
	./sorer -f "data.sor" -from 0 -len 200 -is_missing_idx 0 3      #expected return: 1
	./sorer -f "data.sor" -from 0 -len 200 -is_missing_idx 1 1      #expected return: 0
	./sorer -f "data.sor" -from 0 -len 200 -is_missing_idx 1 2      #expected return: 0
	./sorer -f "data.sor" -from 0 -len 200 -is_missing_idx 1 4      #expected return: 1
	./sorer -f "data.sor" -from 0 -len 200 -is_missing_idx 2 2      #expected return: 1
	./sorer -f "data.sor" -from 0 -len 200 -is_missing_idx 3 0      #expected return: 1
	./sorer -f "data.sor" -from 0 -len 200 -is_missing_idx 3 5      #expected return: 0
	./sorer -f "data.sor" -from 0 -len 200 -is_missing_idx 4 1      #expected return: 1
	./sorer -f "data.sor" -from 0 -len 200 -is_missing_idx 4 2      #expected return: 1
	./sorer -f "data.sor" -from 0 -len 200 -is_missing_idx 4 3      #expected return: 1
	./sorer -f "data.sor" -from 0 -len 200 -is_missing_idx 4 5      #expected return: 1
	./sorer -f "data.sor" -from 0 -len 200 -is_missing_idx 5 0      #expected return: 0
	./sorer -f "data.sor" -from 0 -len 200 -is_missing_idx 5 1      #expected return: 1
	./sorer -f "data.sor" -from 0 -len 200 -is_missing_idx 6 0      #expected return: 1
	./sorer -f "data.sor" -from 0 -len 200 -print_col_idx 0 0       #expected return: 0
	./sorer -f "data.sor" -from 0 -len 200 -print_col_idx 0 1       #expected return: 23
	./sorer -f "data.sor" -from 0 -len 200 -print_col_idx 0 2       #expected return: hi
	./sorer -f "data.sor" -from 0 -len 200 -print_col_idx 1 2       #expected return: " hello "
	./sorer -f "data.sor" -from 0 -len 200 -print_col_idx 2 0       #expected return: 1
	./sorer -f "data.sor" -from 0 -len 200 -print_col_idx 2 1       #expected return: 1
	./sorer -f "data.sor" -from 0 -len 200 -print_col_idx 3 3       #expected return: +2.77
	./sorer -f "data.sor" -from 0 -len 200 -print_col_idx 3 5       #expected return: hey
	./sorer -f "data.sor" -from 0 -len 200 -print_col_idx 4 0       #expected return: 0
	./sorer -f "data.sor" -from 0 -len 200 -print_col_idx 5 0       #expected return: 1