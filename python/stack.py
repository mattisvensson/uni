class Node:
  def __init__(self, data):
    self.data = data
    self.next = None

class LinkedListStack:
  def __init__(self):
    self.top = None

  def push(self, data):
    node = Node(data)
    node.next = self.top
    self.top = node

  def pop(self):
    popped = self.top.data
    self.top = self.top.next
    return popped
  
  def getAll(self):
    items = []
    current = self.top
    while current is not None:
        items.append(current.data)
        current = current.next
    return items
  

class ArrayStack():
  def __init__(self):
    self.stack = []

  def push(self, data):
    self.stack.append(data)

  def pop(self):
    if len(self.stack) == 0:
      return
    return self.stack.pop()

  def getAll(self):
    return self.stack
  

linkedListStack = LinkedListStack()
arrayStack = ArrayStack()


# arrayStack.push("A")
# arrayStack.push("B")
# arrayStack.push("C")
arrayStack.pop()
# arrayStack.push("D")

print(arrayStack.getAll())

# linkedListStack.push("A")
# linkedListStack.push("B")
# linkedListStack.push("C")
# linkedListStack.pop()
# linkedListStack.push("D")

# print(linkedListStack.getAll())