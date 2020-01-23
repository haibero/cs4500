import argparse

def parse_arguments():
    parser = argparse.ArgumentParser(description="Arg Parser");
    parser.add_argument('-f', help="File to parse")

    return parser

if __name__ == "__main__":
    args = parse_arguments().parse_args()
    print(args.f)