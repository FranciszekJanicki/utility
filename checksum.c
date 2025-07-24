#include "checksum.h"
#include "bitwise.h"
#include <assert.h>

uint8_t uint8_calculate_crc(uint8_t const *data, size_t data_size,
                            uint8_t initial, uint8_t polynomial,
                            uint8_t xor_out, bool reflect_in,
                            bool reflect_out) {
  assert(data != NULL);

  uint8_t crc = initial;

  if (data_size == 0U) {
    if (reflect_out) {
      crc = uint8_reflect(crc);
    }

    return crc;
  }

  uint8_t msb_mask = 1U << 7U;

  for (size_t i = 0U; i < data_size; ++i) {
    uint8_t byte = data[i];

    if (reflect_in) {
      byte = uint8_reflect(byte);
    }

    crc ^= byte;

    for (uint8_t j = 0U; j < 8U; ++j) {
      if (crc & msb_mask) {
        crc = (crc << 1U) ^ polynomial;
      } else {
        crc <<= 1U;
      }
    }
  }

  if (reflect_out) {
    crc = uint8_reflect(crc);
  }

  crc ^= xor_out;

  return crc;
}

uint16_t uint16_calculate_crc(uint8_t const *data, size_t data_size,
                              uint16_t initial, uint16_t polynomial,
                              uint16_t xor_out, bool reflect_in,
                              bool reflect_out) {
  assert(data != NULL);

  uint16_t crc = initial;

  if (data_size == 0U) {
    if (reflect_out) {
      crc = uint16_reflect(crc);
    }

    return crc;
  }

  uint16_t msb_mask = 1U << 15U;

  for (size_t i = 0U; i < data_size; ++i) {
    uint8_t byte = data[i];

    if (reflect_in) {
      byte = uint8_reflect(byte);
    }

    crc ^= byte << 8U;

    for (uint8_t j = 0U; j < 16U; ++j) {
      if (crc & msb_mask) {
        crc = (crc << 1U) ^ polynomial;
      } else {
        crc <<= 1U;
      }
    }
  }

  if (reflect_out) {
    crc = uint16_reflect(crc);
  }

  crc ^= xor_out;

  return crc;
}

uint32_t uint32_calculate_crc(uint8_t const *data, size_t data_size,
                              uint32_t initial, uint32_t polynomial,
                              uint32_t xor_out, bool reflect_in,
                              bool reflect_out) {
  assert(data != NULL);

  uint32_t crc = initial;

  if (data_size == 0U) {
    if (reflect_out) {
      crc = uint32_reflect(crc);
    }

    return crc;
  }

  uint32_t msb_mask = 1U << 31U;

  for (size_t i = 0U; i < data_size; ++i) {
    uint8_t byte = data[i];

    if (reflect_in) {
      byte = uint8_reflect(byte);
    }

    crc ^= byte << 24U;

    for (uint8_t j = 0U; j < 32U; ++j) {
      if (crc & msb_mask) {
        crc = (crc << 1U) ^ polynomial;
      } else {
        crc <<= 1U;
      }
    }
  }

  if (reflect_out) {
    crc = uint32_reflect(crc);
  }

  crc ^= xor_out;

  return crc;
}

uint64_t uint64_calculate_crc(uint8_t const *data, size_t data_size,
                              uint64_t initial, uint64_t polynomial,
                              uint64_t xor_out, bool reflect_in,
                              bool reflect_out) {
  assert(data != NULL);

  uint64_t crc = initial;

  if (data_size == 0U) {
    if (reflect_out) {
      crc = uint64_reflect(crc);
    }

    return crc;
  }

  uint64_t msb_mask = 1UL << 63UL;

  for (size_t i = 0U; i < data_size; ++i) {
    uint8_t byte = data[i];

    if (reflect_in) {
      byte = uint8_reflect(byte);
    }

    crc ^= byte << 56U;

    for (uint8_t j = 0U; j < 64U; ++j) {
      if (crc & msb_mask) {
        crc = (crc << 1U) ^ polynomial;
      } else {
        crc <<= 1U;
      }
    }
  }

  if (reflect_out) {
    crc = uint64_reflect(crc);
  }

  crc ^= xor_out;

  return crc;
}
