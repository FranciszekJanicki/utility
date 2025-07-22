#ifndef UTILITY_ALLOCATOR_H
#define UTILITY_ALLOCATOR_H

#include <stddef.h>

typedef struct allocator allocator_t;

void *allocator_new(allocator_t *allocator, size_t size);
void allocator_delete(allocator_t *allocator);

#endif // UTILITY_ALLOCATOR_H