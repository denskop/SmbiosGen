//
//  StrList.h
//  SmBiosGen
//
//  Created by Mr.Dee on 13.08.17.
//  Copyright © 2017 denskop. All rights reserved.
//

#ifndef __STRING_LIST__
#define __STRING_LIST__

#include "Types.h"

struct StrList
{
    CHAR8 *str;
    struct StrList *next;
};

// Typedef
typedef struct StrList StrList;

// Operations
StrList *AddStr(StrList *list, const CHAR8 *str);
StrList *PopStr(StrList *list, const CHAR8 **str);
void FreeList(StrList *list);
void PrintList(StrList *list);
#endif /* __STRING_LIST__ */
