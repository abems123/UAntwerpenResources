# This is the node I will be using to determine the structure of the nodes of my tree
class node:
    def __init__(self, key, item, leftChild, rightChild):
        self.key = key
        self.item = item
        self.leftChild = leftChild
        self.rightChild = rightChild


# this function just creates a new node
def createTreeItem(key, val):
    return node(key, val, None, None)


class BST:
    def __init__(self):
        self.root = None

    def isEmpty(self):
        return self.root is None

    def searchTreeInsert(self, n):
        # if the BST is empty, set the n as the root
        if self.isEmpty():
            self.root = n
            return True

        curr = self.root
        # look for the right node where n belongs and put it there if it is None
        while curr is not None:
            if n.key > curr.key:
                if curr.rightChild is None:
                    curr.rightChild = n
                    return True
                else:
                    curr = curr.rightChild
            elif n.key < curr.key:
                if curr.leftChild is None:
                    curr.leftChild = n
                    return True
                else:
                    curr = curr.leftChild

        return False

    def searchTreeRetrieve(self, key):
        curr = self.root
        # get the node with the key
        while curr is not None and curr.key != key:
            if key > curr.key:
                curr = curr.rightChild
            else:
                curr = curr.leftChild
        # if the node is found and is not None return it, otherwise return None and false
        if curr is not None and curr.key == key:
            return curr.item, True
        return None, False

    def inorderTraverse(self, function):
        result = ""

        # get the items left children of the node
        if self.root.leftChild is not None:
            result += self.inorderHelper(self.root.leftChild) + "\n"
        # get the item of the node
        result += str(self.root.item) + "\n"
        # get the items of the right children of the node
        if self.root.rightChild is not None:
            result += self.inorderHelper(self.root.rightChild) + "\n"

        function(result.strip())

    def inorderHelper(self, root):
        r = ""
        if root is None:
            return ""

        if root.leftChild is not None:
            r += self.inorderHelper(root.leftChild) + "\n"
        r += str(root.item) + '\n'
        if root.rightChild is not None:
            r += self.inorderHelper(root.rightChild) + "\n"

        return r.strip()

    def save(self):
        if self is None:
            return None

        original = self.root
        result = '{\'root\': ' + str(self.root.item)

        if self.root.leftChild is not None or self.root.rightChild is not None:
            result += ', \'children\': ['
            if self.root.leftChild is not None:
                self.root = self.root.leftChild
                result += self.save() + ', '
            else:
                result += "None, "

            self.root = original
            if self.root.rightChild is not None:
                self.root = self.root.rightChild
                result += self.save()
            else:
                result += "None"
            result += ']'

        self.root = original
        return result + '}'

    def load(self, tree):
        # if there is a root in the tree, make a new with the key and value tree['root']
        if 'root' in tree and tree['root']:
            new_node = createTreeItem(tree['root'], tree['root'])
        else:
            return

        # add the children of the tree if they exist to the new node
        if 'children' in tree and tree['children']:
            if tree['children'][0] is not None:
                new_node.leftChild = self.load(tree['children'][0])
            if tree['children'][1] is not None:
                new_node.rightChild = self.load(tree['children'][1])

        # set the new node as the root of our tree
        self.root = new_node
        return new_node

    def searchTreeDelete(self, key):
        curr = self.root

        # get the node with the key equals key
        while curr is not None and curr.key != key:
            if key > curr.key:
                curr = curr.rightChild
            else:
                curr = curr.leftChild

        # if the current node is None (that means it doesn't exist in the tree) then return false
        if curr is None: return False

        # if it is a leaf node, just make it None
        if curr.leftChild is None and curr.rightChild is None:
            temp_curr = self.root
            while temp_curr.key != curr.key:
                if curr.key > temp_curr.key:
                    if temp_curr.rightChild.key == curr.key:
                        temp_curr.rightChild = None
                        return True
                    else:
                        temp_curr = temp_curr.rightChild
                else:
                    if temp_curr.leftChild.key == curr.key:
                        temp_curr.leftChild = None
                        return True
                    else:
                        temp_curr = temp_curr.leftChild

        # if it has only one child, move it to the place of the parent
        if curr.leftChild is None or curr.rightChild is None:
            if curr.rightChild is not None:
                curr.key = curr.rightChild.key
                curr.item = curr.rightChild.item
                curr.rightChild = None
            else:
                curr.key = curr.leftChild.key
                curr.item = curr.leftChild.item
                curr.leftChild = None

        # if it is a root with 2 children, replace it with the m node
        if curr.leftChild is not None and curr.rightChild is not None:
            node_before_m = curr.rightChild
            m_node = curr.rightChild

            # getting the M node
            while m_node.leftChild is not None:
                node_before_m = m_node
                m_node = m_node.leftChild

            if node_before_m.key == m_node.key:
                curr.rightChild = None

            curr.key = m_node.key
            curr.item = m_node.item
            node_before_m.leftChild = None
            return True