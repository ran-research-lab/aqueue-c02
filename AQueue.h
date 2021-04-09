//
// Implementation of a stack using array
//

#ifndef AQUEUE_H
#define AQUEUE_H
#include "Queue.h"
#include <stdexcept>
#include <string>

using namespace std;
typedef int queueElementType;

class AQueue: public Queue {
private:
  queueElementType* queueArray; // Array holding queue elements
  static const int DEFAULT_SIZE = 10;
  int maxSize;         // Maximum size of queue
  int front;           // Index of front element
  int rear;            // Index of rear element

public:
  // Constructors
  AQueue(int size = DEFAULT_SIZE) {
    maxSize = size + 1;          // One extra space is allocated
    rear = 0; front = 1;
    queueArray = new queueElementType[maxSize];  // Create queueArray
  }

  // Reinitialize
  void clear() { rear = 0; front = 1; }

  // Put "it" in queue
  bool enqueue(const queueElementType& it) {
    if (((rear+2) % maxSize) == front) 
        throw std::out_of_range("trying to enqueue to a full AQueue");

    rear = (rear+1) % maxSize; // Circular increment
    queueArray[rear] = it;
    return true;
  }


  // Remove and return front value
  queueElementType dequeue() {
    if(length() == 0) 
        throw std::out_of_range("trying to dequeue from an empty AQueue");
    queueElementType it = queueArray[front];
    front = (front+1) % maxSize; // Circular increment
    return it;
  }

  // Return front value
  queueElementType frontValue() const {
    if (length() == 0) 
        throw std::out_of_range(
	"trying to get front value from an empty AQueue");
    return queueArray[front];
  }

  // Return queue size
  int length() const { return ((rear+maxSize) - front + 1) % maxSize; }

  // Return a string representation of the queue, from front
  // to rear....
  string to_string() const {
    string st;
    int len = length();
    int idx = front;
    for (int i = 0; i < len; i++)  {
      st = st + std::to_string(queueArray[idx]);
      idx = (idx + 1) % maxSize;
      if (i < len - 1) st += ",";
    }
    return st;
  }

  // Check if the queue is empty
  bool isEmpty() const { return (rear + 1) % maxSize  == front; }
};

#endif //AQUEUE_H
