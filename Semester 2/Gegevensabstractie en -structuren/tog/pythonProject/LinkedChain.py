class node:
    def __init__(self):
        self.item = None
        self.prev = None
        self.next = None


class LinkedChain:
    def __init__(self):
        self.head = node()

    def getLength(self):
        if self.isEmpty(): return 0

        curr = self.head.next
        length = 1
        while curr is not None and curr is not self.head:
            curr = curr.next
            length += 1

        return length

    def isEmpty(self):
        return self.head.item is None and self.head.next is None and self.head.prev is None

    def retrieve(self, idx):
        curr = self.head
        index = idx - 1
        if index < self.getLength():
            for i in range(index):
                curr = curr.next
            return curr.item, True
        return None, False

    def insert(self, idx, item):
        # this is the index used by us because the linked chain starts from 0
        index = idx - 1

        # first added node will be the head
        if self.isEmpty() and 0 <= index <= self.getLength():
            new_node = node()
            new_node.item = item
            self.head = new_node
            self.head.next = self.head
            self.head.prev = self.head
            return True

        # if the index is smaller than the length
        if 0 <= index <= self.getLength():
            # create a new node and set its item to the given value
            new_node = node()
            new_node.item = item

            # if we have to add the node to the first of the linked chain
            if index == 0:
                self.head.prev.next = new_node
                new_node.next = self.head
                self.head.prev = new_node
                self.head = new_node
            # the end of the linked chain
            elif index == self.getLength():
                new_node.next = self.head
                self.head.prev.next = new_node
                new_node.prev = self.head.prev
                self.head.prev = new_node
            # in the middle of the linked chain
            else:
                curr = self.head
                # get the node is the position 'index'
                for i in range(index):
                    curr = curr.next
                new_node.next = curr
                new_node.prev = curr.prev
                curr.prev.next = new_node
                curr.prev = new_node
            return True
        return False

    def save(self):
        result = '['
        curr = self.head.next

        # add the head item to the string, if it's empty return
        if not self.isEmpty():
            result += str(self.head.item) + ', '
        else:
            return

        # add the other items
        while not self.isSame(curr):
            result += str(curr.item) + ', '
            curr = curr.next

        return result[:-2] + ']'

    def load(self, list):
        # remove the old head
        self.head = node()
        # insert the elements of the list to the linked chain
        for n in range(len(list)):
            self.insert(n + 1, list[n])

    def delete(self, idx):
        index = idx - 1

        if index == 0:
            # remove a node from the beginning
            self.head.prev.next = self.head.next
            self.head.next.prev = self.head.prev
            self.head = self.head.next
            return True
        elif index == self.getLength():
            # remove a node from the end
            self.head.prev.prev.next = self.head
            self.head.prev = self.head.prev.prev

        elif index > 0:
            # remove a node in the middle
            curr = self.head
            # get the node is the position 'index'
            for i in range(index):
                curr = curr.next
            curr.prev.next = curr.next
            curr.next.prev = curr.prev
            return True

        return False

    def isSame(self, lc):
        return self.head.item == lc.item and self.head.next == lc.next and self.head.prev == lc.prev
