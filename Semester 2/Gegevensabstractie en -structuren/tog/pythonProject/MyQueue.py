class MyQueue:
    def __init__(self, items=None):
        if items is None:
            items = []
        self.items = items

    def load(self, stack):
        self.items = stack
        self.top = stack[-1]

    def isEmpty(self):
        return len(self.items) == 0

    def save(self):
        return str(self.items)


    def enqueue(self, element):
        self.items.insert(0, element)
        return True

    def dequeue(self):
        if not self.isEmpty():
            t = self.items[-1]
            self.items.pop()
            return t, True
        else:
            return None, False

    def getFront(self):
        if self.isEmpty():
            return None, False
        else:
            return self.items[-1], True
