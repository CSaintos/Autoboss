#include "DatabaseCtr.h"
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <conio.h>
#include <tchar.h>
#include <stdlib.h>
#include <sal.h>

typedef struct STR_BINDING {
    SQLSMALLINT         cDisplaySize;           /* size to display  */
    WCHAR* wszBuffer;             /* display buffer   */
    SQLLEN              indPtr;                 /* size or null     */
    BOOL                fChar;                  /* character col?   */
    struct STR_BINDING* sNext;                 /* linked list      */
} BINDING;
