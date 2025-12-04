package task4_1;

import task4_1.classes.Queue;

public class Main {
  public static void main(String[] args) {
    Queue queue = new Queue();
    queue.add(5);
    queue.add(4);
    queue.add(7);
    queue.add(8);
    queue.remove();
    System.out.println(queue.isEmpty());
    System.out.println(queue.getSize());
    queue.print();

  }


}
