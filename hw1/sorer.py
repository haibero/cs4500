from dataframe import DataFrame
from missing import Missing
import argparse
import re


def parse_arguments():
    parser = argparse.ArgumentParser(description="SoRer arg parser");
    parser.add_argument('-f', type=str, help="File Path of file to parse")
    parser.add_argument('-from', dest='start', type=int, default=0, help="starting position in the file (in bytes)")
    parser.add_argument('-len', type=int, default=500, help="number of bytes to read")
    parser.add_argument('-print_col_type', type=int, help='print the type of a column: BOOL, INT, FLOAT, STRING')
    parser.add_argument('-print_col_idx', type=int, nargs = 2, help='the first argument is the column, the second is the offset')
    parser.add_argument('-is_missing_idx', type=int, nargs = 2, help='is there a missing in the specified column offset')
    return parser

#File int int -> List of Strings
def read_file(file_path, bytes_to_read, start_byte):
    with open(file_path, 'rb') as sor_file:
        skipped_rows = sor_file.read(start_byte).decode('utf-8')
        rad = sor_file.read(bytes_to_read)

        file_txt = rad.decode('utf-8').split('\n')

        #Keeps \n with the value after the split
        skipped_rows = re.split('\n.',skipped_rows)

        #Drops the first row if it is incomplete
        if '\n' not in skipped_rows[-1] and start_byte != 0:
            file_txt = file_txt[1:]

        #Drops the last row if it is incomplete
        if file_txt[-1] != "" or not file_txt[-1]:
            file_txt = file_txt[:-1]

    return file_txt


def format_all_rows(lo_file_text):
    formatted_text = []
    for x in lo_file_text:
        formatted_text.append(re.findall(r'\<([^>]*)\>', x))
    return formatted_text


def get_longest_row(lo_file_text):
    return max(len(x) for x in lo_file_text) if lo_file_text else 0


def string_to_type(raw_string):
    if re.search('[a-zA-Z]', raw_string):
        return 'STRING'
    elif re.search('[+|-]?[0-9]*\.[0-9]*', raw_string):
        return 'FLOAT'
    elif re.search('[0|1]', raw_string):
        return 'BOOL'
    elif re.search('[0-9]*', raw_string):
        return 'INT'
    else:
        return Missing.get_instance()


def determine_column_types(unparsed_list, size):
    column_indx_remaining = list(range(size))
    column_types = dict.fromkeys((list(range(size))), None)
    for row in unparsed_list:
        i = 0
        if not column_indx_remaining:
            break
        while len(row) > column_indx_remaining[i]:
            type_of_index = string_to_type(row[column_indx_remaining[i]])
            if not Missing.get_instance().equals(type_of_index):
                column_types[column_indx_remaining.pop(i)] = type_of_index
            else:
                i += 1
            if not column_indx_remaining:
                break
    return column_types




def build_valid_dataframe(column_types, unparsed_list):
    sor_df = DataFrame()
    sor_df.set_column_types(column_types)
    for row in unparsed_list:
        for x in range(len(row)):
            if string_to_type(row[x]) != sor_df.column_types[x]:
                row[x] = Missing.get_instance()
        row.extend([Missing.get_instance()] * (len(column_types) - len(row)))
        df_row = row
        sor_df.add_row(row)

    return sor_df


if __name__ == "__main__":
    args = parse_arguments().parse_args()
    file_txt = read_file(file_path=args.f, bytes_to_read=args.len, start_byte=args.start)
    test = format_all_rows(file_txt)
    column_types = determine_column_types(test, get_longest_row(test))
    sor_df = build_valid_dataframe(column_types, test)
    for x in sor_df.rows:
        print(x, "\n")
    # print(get_longest_row(test))
    # for x in test:
    #     for y in x:
    #         print(type(y))

