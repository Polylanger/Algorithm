#include "QueueTest.h"

int runCircleArraysSimpleTest()
{
  int x;

  CircleQueue<int>* queue = new CircleQueue<int>();
  for (int i = 0; i < 10; i++) {
    queue->enQueue(i + 1);
  }
  queue->output();

  for (int i = 0; i < 3; i++)
  {
    queue->deQueue(x);
    cout << "de-Q: " << x << endl;
  }
  queue->output();

  return 0;
}

int runQueueTest()
{
  
  runCircleArraysSimpleTest();

  return 0;
}
