#pragma once
#include <stdbool.h>

typedef struct {
  int top;
  int capacity;
  float array[];
} Stack;

Stack *st_innit(int cap);
bool st_empty(Stack *st);
bool st_full(Stack *st);
bool st_push(Stack *st, float val);
float st_pop(Stack *st);
float st_top(Stack *st);