#include <stdlib.h>
#include "queue.h"
#include <stdio.h>

/** creates a new Queue and allocates enough memory for max_cells
 * @param max_cells Number of nodes to be in the queue
 * @return The new queue
 */
Queue *create_queue(int max_cells) {
  Queue *new_queue; //Holds pointer to the newly-allocated queue structure
  new_queue = (Queue *) malloc(sizeof(Queue));

  if(new_queue == NULL) {
    return NULL; //Error--unable to allocate.
  }
  //fill the queue
  new_queue->max_cells = max_cells;
  new_queue->cells_used = 0; //start empty

  //Make space for all of the queue nodes
  new_queue->queue_base = (void **) calloc(sizeof(void *), max_cells);
  if(new_queue->queue_base == NULL) {
    free(new_queue); //Error, so unallocate struct
    return NULL;
  }
  new_queue->queue_front = new_queue->queue_base; //front starts at the queue base
  new_queue->queue_back = new_queue->queue_base; //back starts at the queue base

  return new_queue;
}

/** Pushes a pointer onto a Queue.
 * @param which_queue Pointer to a queue  you want to queue to.
 * @param ptr Pointer to be queued.
 * @param max Max number of nodes for the queue.
 * @return 0 if successful, -1 if not.
 */
int enqueue(Queue *which_queue, void *ptr, int max) {
  // Check if stack is already full 
  if ((which_queue->cells_used) >= (which_queue->max_cells)) {
    fprintf(stderr,"The Queue is already full!\n");
    which_queue->cells_used = which_queue->max_cells;
    return -1;  // Stack overflow.
  }

  *(which_queue->queue_back)=ptr; //store that pointer on the queue
  (which_queue->queue_back)++; //next node is pointed to
  (which_queue->cells_used)++;

  if (which_queue->queue_back >= which_queue->queue_base + max) {
    which_queue->queue_back = which_queue->queue_base;
  }

  return 0;
}

/** Dequeues a pointer from the queue
 * @param which_queue Pointer to the queue to dequeue from
 * @param max Max number of nodes in the queue
 */
void* dequeue(Queue *which_queue, int max) {
  void*dequeueElement;

  if((which_queue->cells_used) <= 0) { //check if empty
    fprintf(stderr,"The queue is empty!\n");
    which_queue->cells_used = 0;
    return NULL; //empty queue
  }
  dequeueElement = *(which_queue->queue_front); //dequeue from queue
  (which_queue->queue_front)++;
  (which_queue->cells_used)--;

  if(which_queue->queue_front >= which_queue->queue_base + max) {
    which_queue->queue_front = which_queue->queue_base;
  }
  return dequeueElement;
}


