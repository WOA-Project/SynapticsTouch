// Copyright (c) Microsoft Corporation. All Rights Reserved. 
// Copyright (c) Bingxing Wang. All Rights Reserved. 

#pragma once

#include <wdm.h>
#include <wdf.h>
#include <hidport.h>
#define RESHUB_USE_HELPER_ROUTINES
#include <reshub.h>
#include "trace.h"
#include "hid.h"
#include "spb.h"

//
// Memory tags
//
#define TOUCH_POOL_TAG                  (ULONG)'cuoT'
#define TOUCH_POOL_TAG_F12              (ULONG)'21oT'

//
// Constants
//
#define MODE_MULTI_TOUCH                0x02
#define MAX_TOUCH_COORD                 0x0FFF
#define FINGER_STATUS                   0x01 // finger down

NTSTATUS 
TchAllocateContext(
    OUT VOID **ControllerContext,
    IN WDFDEVICE FxDevice
    );

NTSTATUS 
TchFreeContext(
    IN VOID *ControllerContext
    );

NTSTATUS 
TchStartDevice(
    IN VOID *ControllerContext,
    IN SPB_CONTEXT *SpbContext
    );

NTSTATUS 
TchStopDevice(
    IN VOID *ControllerContext,
    IN SPB_CONTEXT *SpbContext
    );

NTSTATUS 
TchStandbyDevice(
    IN VOID *ControllerContext,
    IN SPB_CONTEXT *SpbContext
    );

NTSTATUS 
TchWakeDevice(
    IN VOID *ControllerContext,
    IN SPB_CONTEXT *SpbContext
    );

NTSTATUS
TchRegistryGetControllerSettings(
    IN VOID *ControllerContext,
    IN WDFDEVICE FxDevice
    );
   
NTSTATUS
TchServiceInterrupts(
    IN VOID *ControllerContext,
    IN SPB_CONTEXT *SpbContext,
    IN PDEV_REPORT HidReport,
    IN UCHAR InputMode,
    OUT BOOLEAN *ServicingComplete
);

NTSTATUS
TchPowerSettingCallback(
    _In_ LPCGUID SettingGuid,
    _In_ PVOID Value,
    _In_ ULONG ValueLength,
    _Inout_opt_ PVOID Context
);