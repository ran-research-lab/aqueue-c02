//
// Created by Rafael Arce Nazario on 9/30/20.
//

#ifndef QUEUE_H
#define QUEUE_H

typedef int queueElementType;
class Queue { // Queue class ADT
  // Reinitialize queue
  void clear();

  // Put element on rear
  bool enqueue(const queueElementType &it);

  // Remove and return element from front
   queueElementType dequeue();

  // Return front element
  queueElementType frontValue() const;

  // Return queue size
  int length() const;

  // Return true if the queue is empty
  bool isEmpty() const;
};

#endif //QUEUE_H
