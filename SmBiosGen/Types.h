//
//  Types.h
//  SmBiosGen
//
//  Created by Mr.Dee on 12.08.17.
//  Copyright © 2017 denskop. All rights reserved.
//

#ifndef __TYPES_H__
#define __TYPES_H__

// Basic types
typedef char            CHAR8;
typedef unsigned char   UCHAR8;
typedef unsigned char   UINT8;
typedef unsigned short  UINT16;
typedef unsigned int    UINT32;
typedef unsigned long   UINT64;

// UEFI types

///
/// 128 bit buffer containing a unique identifier value.
/// Unless otherwise specified, aligned on a 64 bit boundary.
///
typedef struct {
    UINT32  Data1;
    UINT16  Data2;
    UINT16  Data3;
    UINT8   Data4[8];
} GUID;
#endif /* __TYPES_H__ */
