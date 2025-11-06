class MyStack:
    # initialize the class with its variable items
    def __init__(self, items=[]):
        self.items = items

    # load a stack
    def load(self, stack):
        # set the items variable to stack and top variable to the last element in the given list -stack-
        self.items = stack
        self.top = stack[-1]

    # check if the length of the items list is 0
    def isEmpty(self):
        return len(self.items) == 0

    # convert the list to string
    def save(self):
        return str(self.items)

    # add an element to the list items and return True
    def push(self, element):
        self.items.append(element)
        return True

    def pop(self):
        if not self.isEmpty():
            # if the stack is not empty, save the top in a var t
            t = self.getTop()[0]
            # pop the top var
            self.items.pop()
            # return the popped var and True
            return t, True
        else:
            # if the stack is empty, return None and false
            return None, False

    def getTop(self):
        if self.isEmpty():
            return None, False
        else:
            # return the last element in the list item, that is the top
            return self.items[-1], True
