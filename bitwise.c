#include "bitwise.h"
#include "string.h"

uint16_t uint8x2_le_to_uint16(uint8x2_t uint8x2)
{
    return (uint16_t)uint8x2.data[0] | ((uint16_t)uint8x2.data[1] << 8U);
}

uint16_t uint8x2_be_to_uint16(uint8x2_t uint8x2)
{
    return ((uint16_t)uint8x2.data[0] << 8U) | (uint16_t)uint8x2.data[1];
}

uint8x2_t uint16_to_uint8x2_le(uint16_t uint16)
{
    return (uint8x2_t){
        .data = {[0] = (uint8_t)uint16, [1] = (uint8_t)(uint16 >> 8U)}};
}

uint8x2_t uint16_to_uint8x2_be(uint16_t uint16)
{
    return (uint8x2_t){
        .data = {[0] = (uint8_t)(uint16 >> 8U), [1] = (uint8_t)uint16}};
}

uint32_t uint8x4_le_to_uint32(uint8x4_t uint8x4)
{
    return (uint32_t)uint8x4.data[0] | ((uint32_t)uint8x4.data[1] << 8U) |
           ((uint32_t)uint8x4.data[2] << 16U) |
           ((uint32_t)uint8x4.data[3] << 24U);
}

uint32_t uint8x4_be_to_uint32(uint8x4_t uint8x4)
{
    return ((uint32_t)uint8x4.data[0] << 24U) |
           ((uint32_t)uint8x4.data[1] << 16U) |
           ((uint32_t)uint8x4.data[2] << 8U) | (uint32_t)uint8x4.data[3];
}

uint8x4_t uint32_to_uint8x4_le(uint32_t uint32)
{
    return (uint8x4_t){.data = {[0] = (uint8_t)uint32,
                                [1] = (uint8_t)(uint32 >> 8U),
                                [2] = (uint8_t)(uint32 >> 16U),
                                [3] = (uint8_t)(uint32 >> 24U)}};
}

uint8x4_t uint32_to_uint8x4_be(uint32_t uint32)
{
    return (uint8x4_t){.data = {[0] = (uint8_t)(uint32 >> 24U),
                                [1] = (uint8_t)(uint32 >> 16U),
                                [2] = (uint8_t)(uint32 >> 8U),
                                [3] = (uint8_t)uint32}};
}

uint64_t uint8x8_le_to_uint64(uint8x8_t uint8x8)
{
    return (uint64_t)uint8x8.data[0] | ((uint64_t)uint8x8.data[1] << 8U) |
           ((uint64_t)uint8x8.data[2] << 16U) |
           ((uint64_t)uint8x8.data[3] << 24U) |
           ((uint64_t)uint8x8.data[4] << 32U) |
           ((uint64_t)uint8x8.data[5] << 40U) |
           ((uint64_t)uint8x8.data[6] << 48U) |
           ((uint64_t)uint8x8.data[7] << 56U);
}

uint64_t uint8x8_be_to_uint64(uint8x8_t uint8x8)
{
    return ((uint64_t)uint8x8.data[0] << 56U) |
           ((uint64_t)uint8x8.data[1] << 48U) |
           ((uint64_t)uint8x8.data[2] << 40U) |
           ((uint64_t)uint8x8.data[3] << 32U) |
           ((uint64_t)uint8x8.data[4] << 24U) |
           ((uint64_t)uint8x8.data[5] << 16U) |
           ((uint64_t)uint8x8.data[6] << 8U) | (uint64_t)uint8x8.data[7];
}

uint8x8_t uint64_to_uint8x8_le(uint64_t uint64)
{
    return (uint8x8_t){.data = {[0] = (uint8_t)uint64,
                                [1] = (uint8_t)(uint64 >> 8U),
                                [2] = (uint8_t)(uint64 >> 16U),
                                [3] = (uint8_t)(uint64 >> 24U),
                                [4] = (uint8_t)(uint64 >> 32U),
                                [5] = (uint8_t)(uint64 >> 40U),
                                [6] = (uint8_t)(uint64 >> 48U),
                                [7] = (uint8_t)(uint64 >> 56U)}};
}

uint8x8_t uint64_to_uint8x8_be(uint64_t uint64)
{
    return (uint8x8_t){.data = {[0] = (uint8_t)(uint64 >> 56U),
                                [1] = (uint8_t)(uint64 >> 48U),
                                [2] = (uint8_t)(uint64 >> 40U),
                                [3] = (uint8_t)(uint64 >> 32U),
                                [4] = (uint8_t)(uint64 >> 24U),
                                [5] = (uint8_t)(uint64 >> 16U),
                                [6] = (uint8_t)(uint64 >> 8U),
                                [7] = (uint8_t)uint64}};
}

uint32_t float32_to_uint32(float32_t float32)
{
    uint32_t uint32;
    memcpy(&uint32, &float32, sizeof(uint32));
    return uint32;
}

uint8x4_t float32_to_uint8x4_be(float32_t float32)
{
    return uint32_to_uint8x4_be(float32_to_uint32(float32));
}

uint8x4_t float32_to_uint8x4_le(float32_t float32)
{
    return uint32_to_uint8x4_le(float32_to_uint32(float32));
}

float32_t uint32_to_float32(uint32_t uint32)
{
    float32_t float32;
    memcpy(&float32, &uint32, sizeof(float32));
    return float32;
}

float32_t uint8x4_le_to_float32(uint8x4_t uint8x4)
{
    return uint32_to_float32(uint8x4_le_to_uint32(uint8x4));
}

float32_t uint8x4_be_to_float32(uint8x4_t uint8x4)
{
    return uint32_to_float32(uint8x4_be_to_uint32(uint8x4));
}

uint64_t float64_to_uint64(float64_t float64)
{
    uint64_t uint64;
    memcpy(&uint64, &float64, sizeof(uint64));
    return uint64;
}

uint8x8_t float64_to_uint8x8_be(float64_t float64)
{
    return uint64_to_uint8x8_be(float64_to_uint64(float64));
}

uint8x8_t float64_to_uint8x8_le(float64_t float64)
{
    return uint64_to_uint8x8_le(float64_to_uint64(float64));
}

float64_t uint64_to_float64(uint64_t uint64)
{
    float64_t float64;
    memcpy(&float64, &uint64, sizeof(float64));
    return float64;
}

float64_t uint8x8_le_to_float64(uint8x8_t uint8x8)
{
    return uint64_to_float64(uint8x8_le_to_uint64(uint8x8));
}

float64_t uint8x8_be_to_float64(uint8x8_t uint8x8)
{
    return uint64_to_float64(uint8x8_be_to_uint64(uint8x8));
}

uint8_t uint8_reflect(uint8_t uint8)
{
    uint8_t uint8_reflect = 0U;

    for (uint_fast8_t i = 0U; i < 8U; ++i) {
        if (uint8 & (1 << i)) {
            uint8_reflect |= (1 << i);
        }
    }

    return uint8_reflect;
}

uint16_t uint16_reflect(uint16_t uint16)
{
    uint16_t uint16_reflect = 0U;

    for (uint_fast16_t i = 0U; i < 16U; ++i) {
        if (uint16 & (1 << i)) {
            uint16_reflect |= (1 << i);
        }
    }

    return uint16_reflect;
}

uint32_t uint32_reflect(uint32_t uint32)
{
    uint32_t uint32_reflect = 0U;

    for (uint_fast8_t i = 0U; i < 32U; ++i) {
        if (uint32 & (1 << i)) {
            uint32_reflect |= (1 << i);
        }
    }

    return uint32_reflect;
}

uint64_t uint64_reflect(uint64_t uint64)
{
    uint64_t uint64_reflect = 0U;

    for (uint_fast8_t i = 0U; i < 64U; ++i) {
        if (uint64 & (1 << i)) {
            uint64_reflect |= (1 << i);
        }
    }

    return uint64_reflect;
}

uint8_t uint8_bitwidth(uint8_t uint8)
{
    for (uint_fast8_t i = 7U; i >= 0U; --i) {
        if (uint8 & (1 << i)) {
            return i;
        }
    }

    return 0U;
}

uint8_t uint16_bitwidth(uint16_t uint16)
{
    for (uint_fast8_t i = 15U; i >= 0U; --i) {
        if (uint16 & (1 << i)) {
            return i;
        }
    }

    return 0U;
}

uint8_t uint32_bitwidth(uint32_t uint32)
{
    for (uint_fast8_t i = 31U; i >= 0U; --i) {
        if (uint32 & (1 << i)) {
            return i;
        }
    }

    return 0U;
}

uint8_t uint64_bitwidth(uint64_t uint64)
{
    for (uint_fast8_t i = 63U; i >= 0U; --i) {
        if (uint64 & (1 << i)) {
            return i;
        }
    }

    return 0U;
}
