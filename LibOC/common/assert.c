/* ===========================================================================
 * OrangeOS 0.0.1
 * LibOC 0.0.1
 *
 * Please refer to LICENSE for copyright information
 *
 *      File    : assert.c
 *      Purpose : Debug Assertion implementation
 * ===========================================================================
 */

#include <assert.h>


/* ---------------------------------------------------------------------------
 *      Name   : __assert
 *      Purpose: internal assertion mechanism
 *      Args ---
 *          expr: const char *
 *          - Expression that failed to assert.
 *
 *          file: const char *
 *          - Name of file containing failed assertion
 *
 *          line: int
 *          - Line in file containing failed assertion
 *
 *          func: const char *
 *          - Function pretty name.
 *      Returns: void
 * ---------------------------------------------------------------------------
 */
void __assert(const char *expr, const char *file, const char *func,  int line)
{
    fprintf(stderr,
            "%s:%u: %s: Assertion `%s' failed.",
            file, line, func, expr);
}
