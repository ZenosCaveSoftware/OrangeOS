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

#include <ctype.h>

/* ---------------------------------------------------------------------------
 *      Name   : isalnum
 *      Purpose: Checks for alpha-numeric characters
 *      Args ---
 *          character: int
 *          - Character to check
 *      Returns: int
 * ---------------------------------------------------------------------------
 */
int isalnum(int character)
{
    return ((character > 47 && character < 58) ||
            (character > 64 && character < 91) ||
            (character > 96 && character < 123));
}

/* ---------------------------------------------------------------------------
 *      Name   : isalpha
 *      Purpose: Checks for alphabetic characters
 *      Args ---
 *          character: int
 *          - Character to check
 *      Returns: int
 * ---------------------------------------------------------------------------
 */
int isalpha(int character)
{
    return ((character > 64 && character < 91) ||
            (character > 96 && character < 123));
}

/* ---------------------------------------------------------------------------
 *      Name   : iscntrl
 *      Purpose: Checks for control characters
 *      Args ---
 *          character: int
 *          - Character to check
 *      Returns: int
 * ---------------------------------------------------------------------------
 */
int iscntrl(int character)
{
    return (character < 32 || character == 127);
}

/* ---------------------------------------------------------------------------
 *      Name   : isdigit
 *      Purpose: Checks for numeric characters
 *      Args ---
 *          character: int
 *          - Character to check
 *      Returns: int
 * ---------------------------------------------------------------------------
 */
int isdigit(int character)
{
    return (character > 47 && character < 58);
}

/* ---------------------------------------------------------------------------
 *      Name   : isgraph
 *      Purpose: Checks for printable characters other than space (0x20)
 *      Args ---
 *          character: int
 *          - Character to check
 *      Returns: int
 * ---------------------------------------------------------------------------
 */
int isgraph(int character) {
    return (character > 32 && character < 127);
}

/* ---------------------------------------------------------------------------
 *      Name   : islower
 *      Purpose: Checks for lower-case alphabetic characters
 *      Args ---
 *          character: int
 *          - Character to check
 *      Returns: int
 * ---------------------------------------------------------------------------
 */
int islower(int character)
{
    return (character > 96 && character < 123);
}

/* ---------------------------------------------------------------------------
 *      Name   : isprint
 *      Purpose: Checks for printable characters
 *      Args ---
 *          character: int
 *          - Character to check
 *      Returns: int
 * ---------------------------------------------------------------------------
 */
int isprint(int character)
{
    return (character > 31 && character < 127);
}

/* ---------------------------------------------------------------------------
 *      Name   : ispunct
 *      Purpose: Checks for punctuation characters
 *      Args ---
 *          character: int
 *          - Character to check
 *      Returns: int
 * ---------------------------------------------------------------------------
 */
int ispunct(int character)
{
    return ((character > 32 && character < 48) ||
            (character > 57 && character < 65) ||
            (character > 90 && character < 97) ||
            (character > 123 && character < 127));
}

/* ---------------------------------------------------------------------------
 *      Name   : isspace
 *      Purpose: Checks for space characters
 *      Args ---
 *          character: int
 *          - Character to check
 *      Returns: int
 * ---------------------------------------------------------------------------
 */
int isspace(int character)
{
    return ((character > 8 && character < 14) || character == 32);
}

/* ---------------------------------------------------------------------------
 *      Name   : isupper
 *      Purpose: Checks for upper-case alphabetic characters
 *      Args ---
 *          character: int
 *          - Character to check
 *      Returns: int
 * ---------------------------------------------------------------------------
 */
int isupper(int character)
{
    return (character > 64 && character < 91);
}

/* ---------------------------------------------------------------------------
 *      Name   : isxdigit
 *      Purpose: Checks for hexadecimal base characters
 *      Args ---
 *          character: int
 *          - Character to check
 *      Returns: int
 * ---------------------------------------------------------------------------
 */
int isxdigit(int character)
{
    return ((character > 47 && character < 58) ||
            (character > 64 && character < 71) ||
            (character > 96 && character < 103));
}

/* ---------------------------------------------------------------------------
 *      Name   : tolower
 *      Purpose: Converts all upper-case alphabetic characters to lower-case
 *      Args ---
 *          character: int
 *          - Character to check
 *      Returns: int
 * ---------------------------------------------------------------------------
 */
int tolower(int character)
{
    return (character > 64 && character < 91) ? character + 32 : character;
}

/* ---------------------------------------------------------------------------
 *      Name   : toupper
 *      Purpose: Converts all lower-case alphabetic characters to upper-case
 *      Args ---
 *          character: int
 *          - Character to check
 *      Returns: int
 * ---------------------------------------------------------------------------
 */
int toupper(int character)
{
    return (character > 96 && character < 123) ? character - 32 : character;
}
