class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.left = None
        self.right = None

class KeyValueBST:
    def __init__(self):
        self.root = None

    def insert(self, key, value):
        if self.root is None:
            self.root = Node(key, value)
        else:
            self._insert_recursively(self.root, key, value)

    def _insert_recursively(self, current, key, value):
        if key < current.key:
            if current.left is None:
                current.left = Node(key, value)
            else:
                self._insert_recursively(current.left, key, value)
        elif key > current.key:
            if current.right is None:
                current.right = Node(key, value)
            else:
                self._insert_recursively(current.right, key, value)
        else:  # key already exists, update the value
            current.value = value

    def search(self, key):
        return self._search_recursively(self.root, key)

    def _search_recursively(self, current, key):
        if current is None:
            return None  # Key not found
        if key == current.key:
            return current.value  # Return the value associated with the key
        if key < current.key:
            return self._search_recursively(current.left, key)
        return self._search_recursively(current.right, key)

    def inorder(self):
        result = []
        self._inorder_recursively(self.root, result)
        return result

    def _inorder_recursively(self, current, result):
        if current:
            self._inorder_recursively(current.left, result)
            result.append((current.key, current.value))
            self._inorder_recursively(current.right, result)
    
    def find_smallest(self):
      return self._find_smallest_recursively(self.root)
      
    def _find_smallest_recursively(self, current):
      if current.left:
        return self._find_smallest_recursively(current.left)
      else:
        return current.key
        
      

# Beispielverwendung:
bst = KeyValueBST()
bst1 = KeyValueBST()
bst.insert("banana", 200)
bst.insert("cherry", 150)
bst.insert("apple", 100)
bst.insert("d", 150)
bst.insert("e", 150)
bst.insert("f", 150)

bst1.insert("banana", 200)
bst1.insert("cherry", 150)
bst1.insert("apple", 100)
bst1.insert("d", 150)
bst1.insert("e", 150)
bst1.insert("f", 150)

# print(bst.search("apple"))  # 100
# print(bst.search("banana"))  # 200
# print(bst.search("grape"))  # None

# print(bst.inorder())  # [('apple', 100), ('banana', 200), ('cherry', 150)]
# print(bst.find_smallest())


def is_same(a, b):
  return a.inorder() == b.inorder()

print(is_same(bst, bst1))