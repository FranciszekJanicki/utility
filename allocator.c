#include "allocator.h"
#include <assert.h>
#include <stdlib.h>

typedef struct {
  uint8_t buffer[100];
} allocator_storage_stack_t;

typedef struct {
  void *buffer;
  size_t buffer_size;
} allocator_storage_heap_t;

typedef union {
  allocator_storage_stack_t stack;
  allocator_storage_heap_t heap;
} allocator_storage_t;

typedef enum {
  ALLOCATOR_TYPE_HEAP,
  ALLOCATOR_TYPE_STACK,
  ALLOCATOR_TYPE_NONE,
} allocator_type_t;

typedef struct allocator {
  allocator_type_t type;
  allocator_storage_t storage;
} allocator_t;

void *allocator_new(allocator_t *allocator, size_t size) {
  assert(allocator != NULL);

  void *buffer = NULL;

  if (size <= sizeof(allocator->storage.stack.buffer)) {
    allocator->type = ALLOCATOR_TYPE_STACK;
    buffer = allocator->storage.stack.buffer;
  } else {
    allocator->storage.heap.buffer = malloc(size);
    buffer = allocator->storage.heap.buffer;

    if (buffer != NULL) {
      allocator->type = ALLOCATOR_TYPE_HEAP;
      allocator->data.heap.buffer_size = size;
    } else {
      allocator->type = ALLOCATOR_TYPE_NONE;
      allocator->storage.heap.buffer_size = 0UL;
    }
  }

  return buffer;
}

void allocator_delete(allocator_t *allocator) {
  assert(allocator != NULL);

  if (allocator->type == ALLOCATOR_TYPE_HEAP &&
      allocator->storage.heap.buffer != NULL) {
    free(allocator->data.heap.buffer);

    allocator->storage.heap.buffer = NULL;
    allocator->storage.heap.buffer_size = 0UL;
  }

  allocator->type = ALLOCATOR_TYPE_NONE;
}
