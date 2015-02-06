#ifndef QUEUE_H
#define QUEUE_H

struct _Queue {
  void **queue_base;
  void **queue_front;
  void **queue_back;
  int max_cells;
  int cells_used;
};

typedef struct _Queue Queue;

Queue *create_queue(int max_cells);
int enqueue(Queue *which_queue, void *ptr, int max);
void *dequeue(Queue *which_queue, int max);

#endif
