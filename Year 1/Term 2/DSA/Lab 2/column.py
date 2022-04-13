class Column:
    def __init__(self, index):
        self.id = index
        self.column = []

    def app_array(self, elem):
        self.column.append(elem)

    def get_elem(self):
        return self.column[self.id]
