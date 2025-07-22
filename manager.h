#ifndef MANAGER_MANAGER_H
#define MANAGER_MANAGER_H

#include <assert.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DECLARE_MANAGER(NAME, KEY, VALUE, NUM_VALUES) \
                                                      \
    void NAME##_manager_set(KEY key, VALUE value);    \
                                                      \
    VALUE NAME##_manager_get(KEY key);

#define DEFINE_MANAGER(NAME, KEY, VALUE, NUM_VALUES)      \
    static VALUE NAME##_manager_values[NUM_VALUES] = {0}; \
                                                          \
    void NAME##_manager_set(KEY key, VALUE value)         \
    {                                                     \
        assert(key < (NUM_VALUES));                       \
        assert(!NAME##_manager_values[key]);              \
        assert(value);                                    \
        NAME##_manager_values[key] = value;               \
    }                                                     \
                                                          \
    VALUE NAME##_manager_get(KEY key)                     \
    {                                                     \
        assert(key < (NUM_VALUES));                       \
        assert(NAME##_manager_values[key]);               \
        return NAME##_manager_values[key];                \
    }

#ifdef __cplusplus
}
#endif

#endif // #ifndef MANAGER_MANAGER_H