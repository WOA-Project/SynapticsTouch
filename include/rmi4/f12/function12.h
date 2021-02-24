/*++
    Copyright (c) Microsoft Corporation. All Rights Reserved. 
    Sample code. Dealpoint ID #843729.

    Module Name:

        function12.h

    Abstract:

        Contains function defintions used internally
        by the F12 digitizer function.

    Environment:

        Kernel mode

    Revision History:

--*/

#pragma once

#include <wdm.h>
#include <wdf.h>
#include <controller.h>
#include <resolutions.h>
#include <bitops.h>
#include <hweight.h>
#include <rmiinternal.h>
#include <rmi4\f12\controlregisters.h>

NTSTATUS
RmiGetTouchesFromController(
    IN VOID* ControllerContext,
    IN SPB_CONTEXT* SpbContext,
    IN RMI4_F11_DATA_REGISTERS* Data
);

NTSTATUS
RmiConfigureFunction12(
    IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
    IN SPB_CONTEXT* SpbContext
);

NTSTATUS
RmiConfigureReportingModes(
    IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
    IN SPB_CONTEXT* SpbContext
);

NTSTATUS
RmiSetReportingMode(
    IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
    IN SPB_CONTEXT* SpbContext,
    IN UCHAR NewMode,
    OUT UCHAR* OldMode
);

NTSTATUS
RmiGetReporting(
    IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
    IN SPB_CONTEXT* SpbContext,
    OUT PRMI4_F12_CONTROL_23_REGISTER ControlRegisterData
);

NTSTATUS
RmiSetReporting(
    IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
    IN SPB_CONTEXT* SpbContext,
    IN PRMI4_F12_CONTROL_23_REGISTER ControlRegisterData
);

NTSTATUS
RmiGetQuery5(
    IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
    IN SPB_CONTEXT* SpbContext,
    OUT PRMI4_F12_QUERY_5_REGISTER ControlRegisterData
);