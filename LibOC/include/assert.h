/* ===========================================================================
 * OrangeOS 0.0.1
 * LibOC 0.0.1
 *
 * Please refer to LICENSE for copyright information
 *
 *      File    : assert.h
 *      Purpose : Debug Assertion implementation
 * ===========================================================================
 */

#ifndef _OC_ASSERT_H
#define _OC_ASSERT_H 1


#include "stdio.h"
#include "stdlib.h"

#ifdef NDEBUG
#define assert(e)
#else
#define assert(e) (void)((e) || \
    (__assert(#e, __FILE__, __LINE__, __PRETTy_FUNCTION__),0))
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern void __assert(const char *, const char *, const char *, int);

#ifdef __cplusplus
}
#endif

#endif /* _OC_ASSERT_H */
