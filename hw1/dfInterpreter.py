
class DfInterpreter:
    def __init__(self, dataFrame, args):
        self.dataFrame = dataFrame
        self.args = args

    def print_col_type(self):
        print(self.dataFrame.get_col_type(self.args.print_col_type))

    def print_col_idx(self):
        print(self.dataFrame.get_col_idx(self.args.print_col_idx[0],
                                         self.args.print_col_idx[1]))

    def print_is_missing_idx(self):
        print(int(self.dataFrame.is_missing_idx(self.args.is_missing_idx[0],
                                                self.args.is_missing_idx[1])))

    def interpret(self):
        if self.args.print_col_type is not None:
            print('printing column type')
            self.print_col_type()
        elif self.args.print_col_idx:
            print('printing column index')
            self.print_col_idx()
        elif self.args.is_missing_idx:
            print('checking if index is missing')
            self.print_is_missing_idx()
        else:
            print('no interpreter args, nothing to see here')

