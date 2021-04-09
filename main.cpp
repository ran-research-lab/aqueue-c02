// Su nombre aqui

#include "Queue.h"
#include "AQueue.h"
#include <iostream>
#include <stdio.h>

using namespace std;

// Variables and macros for assertions, DO NOT CHANGE ****
int totalAssertions = 0;
int passedAssertions  = 0;
#define expect( chk )  \
    totalAssertions++; \
    if (!(chk)) \
        printf("\x1B[31mAssertion (%s) failed %s at line %d\033[0m\t\t\n", #chk, __FILE__,__LINE__); \
    else { \
        printf("\x1B[32mPassed line %d: %s\033[0m\t\t\n", __LINE__, #chk); \
        passedAssertions++; \
    }
#define assertionReport() { \
     printf("==========================================\n"); \
     printf("Passed %d of %d assertions\n",passedAssertions,totalAssertions); \
     printf("\n"); \
    }
//*******************************************************


int main() {
  AQueue Q(6);

  for (int i = 0; i < 5; i++) Q.enqueue(i);
  cout << Q.to_string() << endl;
  for (int i = 0; i < 5; i++) { 
    expect(Q.dequeue() == i);
  }

  expect(Q.isEmpty());

  Q.enqueue(10); Q.enqueue(20);
  expect(Q.dequeue() == 10);
  Q.enqueue(30); Q.enqueue(40);
  expect(Q.dequeue() == 20);
  expect(Q.dequeue() == 30);

  assertionReport();
}
