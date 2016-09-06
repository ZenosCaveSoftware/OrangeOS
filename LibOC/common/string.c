/* ===========================================================================
 * orangeos: 0.0.1
 * LibOC: 0.0.1
 *
 * Please refer to LICENSE for copyright information
 *
 *      File    : string.c
 *      Purpose : 
 * ===========================================================================
 */

#include <string.h>

/* ---------------------------------------------------------------------------
 *      Name   : strlen
 *      Purpose: string length
 *      Args ---
 *      	s: const char*
 *          - String of which to find its length.
 *      Returns: size_t
 * ---------------------------------------------------------------------------
 */
size_t strlen(const char* s)
{
	const char* s2 = s;
	while ( *s2++ );
	return s2 - s;
}