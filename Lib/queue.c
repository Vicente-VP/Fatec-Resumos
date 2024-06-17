#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  Node *start;
  Node *end;
} Queue;

Node *node_init(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

Queue *q_init() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->start = NULL;
  queue->end = NULL;
  return queue;
}

void enqueue(Queue *queue, int data) {
  Node *node = node_init(data);
  if (queue->start == NULL)
    queue->start = node;

  if (queue->end != NULL)
    queue->end->next = node;
  
  queue->end = node;
}

int *dequeue(Queue *queue) {
  if (queue->start == NULL) {
    fprintf(stderr, "Can't dequeue from empty queue\n");
    queue->end = NULL;
    return NULL;
  }

  int data = queue->start->data;
  Node *node = queue->start;
  queue->start = queue->start->next;
  free(node);
  return pt;
}

void print_queue(Queue *queue) {
  if (queue->start == NULL) {
    printf("[]\n");
    return;
  }
  
  Node *node = queue->start;
  printf("[%d", node->data);
  node = node->next;
  
  while (node != NULL) {
    printf(" -> %d", node->data);
    node = node->next;
  }

  printf("]\n");
}

bool queue_empty(Queue *queue) {
  return queue->start == NULL;
}
