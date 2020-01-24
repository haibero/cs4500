from dfBuilder import DfBuilder
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


# File int int -> List of Strings
def read_file(file_path, bytes_to_read, start_byte):
    with open(file_path, 'rb') as sor_file:
        skipped_rows = sor_file.read(start_byte).decode('utf-8')
        rad = sor_file.read(bytes_to_read)

        file_txt = rad.decode('utf-8').split('\n')

        # Keeps \n with the value after the split
        skipped_rows = re.split('\n.', skipped_rows)

        # Drops the first row if it is incomplete
        if '\n' not in skipped_rows[-1] and start_byte != 0:
            file_txt = file_txt[1:]

        # Drops the last row if it is incomplete
        if file_txt[-1] != "" or not file_txt[-1]:
            file_txt = file_txt[:-1]

    return file_txt


if __name__ == "__main__":
    args = parse_arguments().parse_args()
    file_txt = read_file(file_path=args.f, bytes_to_read=args.len, start_byte=args.start)
    df_builder = DfBuilder(file_txt)
    df_builder.build()


