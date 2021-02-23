// Copyright (c) Microsoft Corporation. All Rights Reserved. 
// Copyright (c) Bingxing Wang. All Rights Reserved. 

#pragma once

#include <wdm.h>
#include <wdf.h>
#include <hidport.h>
#define RESHUB_USE_HELPER_ROUTINES
#include <reshub.h>
#include "trace.h"
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

//
// Types for PTP
//
#pragma pack(push)
#pragma pack(1)
typedef struct _PTP_CONTACT {
    UCHAR		Confidence : 1;
    UCHAR		TipSwitch : 1;
    UCHAR		ContactID : 3;
    UCHAR		Padding : 3;
    USHORT		X;
    USHORT		Y;
} PTP_CONTACT, *PPTP_CONTACT;
#pragma pack(pop)

enum CONTACT_STATE {
    CONTACT_NEW = 0,
    CONTACT_CONTINUED = 1,
    CONTACT_CONFIDENCE_CANCELLED = 2,
    CONTACT_INVALID = 3
};

typedef struct _PTP_REPORT {
    UCHAR       ReportID;
    PTP_CONTACT Contacts[5];
    USHORT      ScanTime;
    UCHAR       ContactCount;
    UCHAR       IsButtonClicked;
} PTP_REPORT, *PPTP_REPORT;

//
// Types for Pen
//
#pragma pack(push)
#pragma pack(1)
typedef struct _PEN_CONTACT {
    UCHAR		InRange   : 1;
    UCHAR		TipSwitch : 1;
    UCHAR		Eraser    : 3;
    UCHAR		Padding   : 3;
    USHORT		X;
    USHORT		Y;
} PEN_CONTACT, * PPEN_CONTACT;
#pragma pack(pop)

typedef struct _PEN_REPORT {
    UCHAR       ReportID;
    PEN_CONTACT Contacts[1];
    USHORT      ScanTime;
} PEN_REPORT, * PPEN_REPORT;

//
// General types
//
typedef union _DEV_REPORT
{
    PEN_REPORT PenReport;
    PTP_REPORT PtpReport;
} DEV_REPORT, * PDEV_REPORT;

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

