#ifndef UTILITY_UTILITY_H
#define UTILITY_UTILITY_H

#include "stdint.h"

typedef struct {
  uint8_t data[2];
} uint8x2_t;

typedef struct {
  uint8_t data[4];
} uint8x4_t;

typedef struct {
  uint8_t data[8];
} uint8x8_t;

typedef float float32_t;
typedef float float64_t;

uint16_t uint8x2_le_to_uint16(uint8x2_t uint8x2);
uint16_t uint8x2_be_to_uint16(uint8x2_t uint8x2);

uint8x2_t uint16_to_uint8x2_le(uint16_t uint16);
uint8x2_t uint16_to_uint8x2_be(uint16_t uint16);

uint32_t uint8x4_le_to_uint32(uint8x4_t uint8x4);
uint32_t uint8x4_be_to_uint32(uint8x4_t uint8x4);

uint8x4_t uint32_to_uint8x4_le(uint32_t uint32);
uint8x4_t uint32_to_uint8x4_be(uint32_t uint32);

uint64_t uint8x8_le_to_uint64(uint8x8_t uint8x8);
uint64_t uint8x8_be_to_uint64(uint8x8_t uint8x8);

uint8x8_t uint64_to_uint8x8_le(uint64_t uint64);
uint8x8_t uint64_to_uint8x8_be(uint64_t uint64);

uint32_t float32_to_uint32(float32_t float32);
uint8x4_t float32_to_uint8x4_be(float32_t float32);
uint8x4_t float32_to_uint8x4_le(float32_t float32);

float32_t uint32_to_float32(uint32_t uint32);
float32_t uint8x4_le_to_float32(uint8x4_t uint8x4);
float32_t uint8x4_be_to_float32(uint8x4_t uint8x4);

uint64_t float64_to_uint64(float64_t float64);
uint8x8_t float64_to_uint8x8_be(float64_t float64);
uint8x8_t float64_to_uint8x8_le(float64_t float64);

float64_t uint64_to_float64(uint64_t uint64);
float64_t uint8x8_le_to_float64(uint8x8_t uint8x8);
float64_t uint8x8_be_to_float64(uint8x8_t uint8x8);

#endif // UTILITY_UTILITY_H