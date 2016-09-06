/* ===========================================================================
 * OrangeOS 0.0.1
 * LibOC 0.0.1
 *
 * Please refer to LICENSE for copyright information
 *
 *      File    : ctype.h
 *      Purpose : ASCII Character testing and conversion
 * ===========================================================================
 */

#ifndef _OC_CTYPE_H
#define _OC_CTYPE_H 1

#ifdef __cplusplus
extern "C" {
#endif

extern int isalnum(int);
extern int isalpha(int);
extern int iscntrl(int);
extern int isdigit(int);
extern int isgraph(int);
extern int islower(int);
extern int isprint(int);
extern int ispunct(int);
extern int isspace(int);
extern int isupper(int);
extern int isxdigit(int);
extern int tolower(int);
extern int toupper(int);

#ifdef __cplusplus
}
#endif

#endif /* _OC_ASSERT_H */
