/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

////////////////////////////////////////////////////////////////
// COURSE 1 FINAL
////////////////////////////////////////////////////////////////

#define FAKE_HEAP_SIZE 1024
uint8_t FAKE_HEAP[FAKE_HEAP_SIZE];

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
  // if dst higher than src, start from the end and work down to avoid corruption from overlap
  if (dst > src) {
    // Avoid letting i (unsigned) roll past 0
    for (size_t i = length-1; i > 0; i--) {
      *(dst + i) = *(src + i);
    }
    *dst = *src;
  }
  
  // if src higher than dst, start from the beginneing and owrk up to avoid corruption from overlap
  else if (src > dst) {
    for (int i = 0; i < length; i++) {
      *(dst + i) = *(src + i);
    }
  }

  return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
  for (size_t i = 0; i < length; i++) {
    *(dst + i) = *(src + i);
  }

  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
  for (size_t i = 0; i < length; i++) {
    *(src + i) = value;
  }

  return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {
  return my_memset(src, length, 0);
}

uint8_t * my_reverse(uint8_t * src, size_t length) {
  for (size_t i = 0, j = length - 1; i <= j; i++, j--) {
    uint8_t tmp = *(src + i);
    *(src + i) = *(src + j);
    *(src + j) = tmp;
  }
  return src;
}

int32_t * reserve_words(size_t length) {
  if (length > (size_t) FAKE_HEAP_SIZE) {
    return (int32_t *) 0;
  }

  my_memzero(FAKE_HEAP, length);
  return (int32_t *) FAKE_HEAP;
}

void free_words(uint32_t * src) {
  my_memzero(FAKE_HEAP, FAKE_HEAP_SIZE);
}
