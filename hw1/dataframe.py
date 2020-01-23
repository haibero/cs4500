from missing import Missing


class DataFrame:
    def __init__(self):
        self.column_types = {}
        self.rows = []

    def set_column_types(self, new_column_types):
        self.column_types = new_column_types

    def add_row(self, new_row):
        self.rows.append(new_row)

    def get_cell(self, col_idx, offset):
        return self.rows[col_idx][offset]

    def get_col_type(self, col_idx):
        return self.column_types[col_idx]

    def is_missing_idx(self, col_idx, offset):
        return Missing.get_instance().equals(self.get_cell(col_idx, offset))

    def get_col_idx(self, col_idx, offset):
        if self.is_missing_idx(col_idx, offset):
            raise Exception("Can not get col_idx of Missing field")
        else:
            return self.get_cell(col_idx, offset)

