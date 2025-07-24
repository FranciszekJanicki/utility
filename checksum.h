#ifndef UTILITY_CHECKSUM_H
#define UTILITY_CHECKSUM_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint8_t uint8_calculate_crc(uint8_t const *data, size_t data_size,
                            uint8_t initial, uint8_t polynomial,
                            uint8_t xor_out, bool reflect_in, bool reflect_out);

uint16_t uint16_calculate_crc(uint8_t const *data, size_t data_size,
                              uint16_t initial, uint16_t polynomial,
                              uint16_t xor_out, bool reflect_in,
                              bool reflect_out);

uint32_t uint32_calculate_crc(uint8_t const *data, size_t data_size,
                              uint32_t initial, uint32_t polynomial,
                              uint32_t xor_out, bool reflect_in,
                              bool reflect_out);

uint64_t uint64_calculate_crc(uint8_t const *data, size_t data_size,
                              uint64_t initial, uint64_t polynomial,
                              uint64_t xor_out, bool reflect_in,
                              bool reflect_out);

#ifdef __cplusplus
}
#endif

#endif // UTILITY_CHECKSUM_H