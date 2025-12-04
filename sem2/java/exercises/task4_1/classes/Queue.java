package task4_1.classes;

import task4_1.interfaces.iQueue;

public class Queue implements iQueue {
  public int arr[];
  public int size = 0;

  public Queue() {
    arr = new int[10]; // or any desired size
  }

  public void add(int x) {
    arr[size++] = x;
  }

  public void remove() {
    if (size > 0) {
      arr[--size] = 0;
    }
  }

  public boolean isEmpty() {
    return size == 0;
  }

  public void print() {
    System.out.print("Queue: ");
    for (int i = 0; i < size; i++) {
        System.out.print(arr[i] + " ");
    }
    System.out.println();
  }

  public int getSize() {
    return size;
  }
}
