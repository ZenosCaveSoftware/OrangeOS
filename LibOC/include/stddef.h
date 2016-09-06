/* ===========================================================================
 * OrangeOS 0.0.1
 *
 * Please refer to LICENSE for copyright information
 *
 *              OrangeOS: A hobby OS designed for development
 *
 *             	<module>: <module-description
 *
 *      File    :
 *      Purpose :
 * ===========================================================================
 */

#ifndef _OOS_STDDEF_H
#define _OOS_MOD_FILE_H 1

/* Boolean type and constants */
#define FALSE        0
#define TRUE         1

/* Universal return constants */
#define OK        1
#define NULL      0
#define SYSERR   (-1)
#define EOF      (-2)
#define TIMEOUT  (-3)
#define NOMSG    (-4)

/* Basic unsigned types */
typedef unsigned char       uchar;
typedef unsigned short      ushort;
typedef unsigned int        uint;
typedef unsigned long       ulong;
typedef unsigned long       size_t;

#endif /* _OOS_FILE_H */