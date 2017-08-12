//
//  StrList.c
//  SmBiosGen
//
//  Created by Mr.Dee on 13.08.17.
//  Copyright © 2017 denskop. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

StrList *AddStr(StrList *list, const CHAR8 *str)
{
    if (str == NULL) {
        printf("Error: Trying to add null string!\n");
        return list;
    }
    
    StrList *tmp = NULL;
    UINT64 str_len = strlen(str);
    
    if (list == NULL) {
        list = (StrList*)malloc(sizeof(StrList));
        list->str = (CHAR8*)malloc(str_len + 1);
        memcpy(list->str, str, str_len + 1);
        list->next = NULL;
    } else {
        tmp = list;
        for (; tmp->next; tmp = tmp->next) {}
        tmp->next = (StrList*)malloc(sizeof(StrList));
        
        tmp = tmp->next;
        tmp->str = (CHAR8*)malloc(str_len + 1);
        memcpy(tmp->str, str, str_len + 1);
        tmp->next = NULL;
    }
    
    return list;
}

StrList *PopStr(StrList *list, const CHAR8 **str)
{
    if (list == NULL) {
        return NULL;
    }
    
    if (str == NULL) {
        printf("Error: Null pointer for output string!\n");
        return list;
    }
    
    *str = list->str;
    return list->next;
}

void FreeList(StrList *list)
{
    if (list == NULL) {
        return;
    }
    
    StrList *tmp = NULL;
    for (; list; list = list->next) {
        if (tmp) {
            free(tmp->str);
            free(tmp);
        }
        
        tmp = list;
    }
    free(tmp->str);
    free(tmp);
}

void PrintList(StrList *list)
{
    for (; list; list = list->next) {
        printf("%s\n", list->str);
    }
}
