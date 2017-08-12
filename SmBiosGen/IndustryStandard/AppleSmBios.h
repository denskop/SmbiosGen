/** @file
 Apple-Specific Definitions of SMBIOS Table Specification v3.0.0.
 
 Copyright (c) 2006 - 2015, Intel Corporation. All rights reserved.<BR>
 (C) Copyright 2015 Hewlett Packard Enterprise Development LP<BR>
 This program and the accompanying materials are licensed and made available under
 the terms and conditions of the BSD License that accompanies this distribution.
 The full text of the license may be found at
 http://opensource.org/licenses/bsd-license.php.
 
 THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
 WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
 
 **/

#ifndef __APPLE_SMBIOS_H__
#define __APPLE_SMBIOS_H__

#include "SmBios.h"

///
/// Apple Firmware Volume.
///
enum {
    FW_REGION_RESERVED   = 0,
    FW_REGION_RECOVERY   = 1,
    FW_REGION_MAIN       = 2,
    FW_REGION_NVRAM      = 3,
    FW_REGION_CONFIG     = 4,
    FW_REGION_DIAGVAULT  = 5,
    
    NUM_FLASHMAP_ENTRIES = 8
};

#pragma pack(push, 1)             // enable 8-bit struct packing

///
/// Apple Firmware Volume - Region Info Type.
///
typedef struct {
    UINT32                StartAddress;
    UINT32                EndAddress;
} FW_REGION_INFO;

///
/// Apple Firmware Volume (Type 128).
///
typedef struct {
    SMBIOS_STRUCTURE      Hdr;
    UINT8                 RegionCount;
    UINT8                 Reserved[3];
    UINT32                FirmwareFeatures;
    UINT32                FirmwareFeaturesMask;
    UINT8                 RegionType[NUM_FLASHMAP_ENTRIES];
    FW_REGION_INFO        FlashMap[NUM_FLASHMAP_ENTRIES];
} SMBIOS_TABLE_TYPE128;

///
/// Apple Memory SPD Data (Type 130).
///
typedef struct {
    SMBIOS_STRUCTURE      Hdr;
    UINT16                Type17Handle;
    UINT16                Offset;
    UINT16                Size;
    UINT16                Data[];
} SMBIOS_TABLE_TYPE130;

///
/// Apple OEM Processor Type (Type 131).
///
typedef struct {
    SMBIOS_STRUCTURE      Hdr;
    UINT16                ProcessorType;
} SMBIOS_TABLE_TYPE131;

///
/// Apple OEM Processor Bus Speed (Type 132).
///
typedef struct {
    SMBIOS_STRUCTURE      Hdr;
    UINT16                ProcessorBusSpeed; // MT/s unit
} SMBIOS_TABLE_TYPE132;

///
/// Apple Platform Feature (Type 133).
///
typedef struct {
    SMBIOS_STRUCTURE      Hdr;
    UINT64                PlatformFeature;
} SMBIOS_TABLE_TYPE133;

///
/// Apple SMC Version (Type 134).
///
typedef struct {
    SMBIOS_STRUCTURE      Hdr;
    UINT64                SMCVersion;
} SMBIOS_TABLE_TYPE134;

#pragma pack(pop) // reset to default struct packing

#endif /* __APPLE_SMBIOS_H__ */
