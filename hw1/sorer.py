import argparse


def parse_arguments():
    parser = argparse.ArgumentParser(description="Arg Parser");
    parser.add_argument('-f', type=str, help="File to parse")
    parser.add_argument('-from', dest='start', type=int, help="starting position in the file (in bytes)")
    parser.add_argument('-len', type=int, help="number of bytes to read")
    parser.add_argument('-print_col_type', type=int, help='print the type of a column: BOOL, INT, FLOAT, STRING')
    parser.add_argument('-print_col_idx', type=int, nargs = '*', help='the first argument is the column, the second is the offset')
    parser.add_argument('-is_missing_idx', type=int, nargs = '*', help='is there a missing in the specified column offset')
    return parser

if __name__ == "__main__":
    args = parse_arguments().parse_args()