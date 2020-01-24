import re
from missing import Missing
from dataframe import DataFrame


class DfBuilder:
    def __init__(self, raw_sor_txt):
        self.raw_sor_txt = raw_sor_txt
        self.column_size = None
        self.formatted_txt = None
        self.result_dataFrame = DataFrame()

    def set_formatted_txt(self, formatted_txt):
        self.formatted_txt = formatted_txt

    def set_column_size(self, column_size):
        self.column_size = column_size

    def get_result_dataFrame(self):
        return self.result_dataFrame

    def get_formatted_rows(self):
        formatted_text = []
        for row in self.raw_sor_txt:
            formatted_text.append(re.findall(r'\<([^>]*)\>', row))
        return formatted_text

    def get_longest_row_size(self):
        return max(len(row) for row in self.formatted_txt) if self.formatted_txt else 0

    @staticmethod
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

    def get_column_types(self):
        column_index_remaining = list(range(self.column_size))
        column_types = dict.fromkeys((list(range(self.column_size))), None)
        for row in self.formatted_txt:
            i = 0
            if not column_index_remaining:
                break
            while len(row) > column_index_remaining[i]:
                type_of_index = self.string_to_type(row[column_index_remaining[i]])
                if not Missing.get_instance().equals(type_of_index):
                    column_types[column_index_remaining.pop(i)] = type_of_index
                else:
                    i += 1
                if not column_index_remaining:
                    break
        return column_types

    def build_dataFrame_rows(self):
        for row in self.formatted_txt:
            for field in range(len(row)):
                if self.string_to_type(row[field]) != self.result_dataFrame.column_types[field]:
                    row[field] = Missing.get_instance()
            row.extend([Missing.get_instance()] * (len(self.result_dataFrame.column_types) - len(row)))
            self.result_dataFrame.add_row(row)

    def build(self):
        self.set_formatted_txt(self.get_formatted_rows())
        self.set_column_size(self.get_longest_row_size())
        self.result_dataFrame.set_column_types(self.get_column_types())
        self.build_dataFrame_rows()
        self.result_dataFrame.print_rows()

