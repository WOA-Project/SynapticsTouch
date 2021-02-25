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
#include <rmi4\rmiinternal.h>
#include <rmi4\f12\controlregisters.h>

NTSTATUS
RmiGetObjectsFromControllerF12(
    IN VOID* ControllerContext,
    IN SPB_CONTEXT* SpbContext,
    IN RMI4_DETECTED_OBJECTS* Data
);

NTSTATUS
RmiConfigureF12(
    IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
    IN SPB_CONTEXT* SpbContext
);

NTSTATUS
RmiConfigureReportingF12(
    IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
    IN SPB_CONTEXT* SpbContext
);

NTSTATUS
RmiSetReportingFlagsF12(
    IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
    IN SPB_CONTEXT* SpbContext,
    IN UCHAR NewMode,
    OUT UCHAR* OldMode
);

NTSTATUS
RmiGetReportingConfigurationF12(
    IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
    IN SPB_CONTEXT* SpbContext,
    OUT PRMI4_F12_OBJECT_REPORT_ENABLE_REGISTER ControlRegisterData
);

NTSTATUS
RmiSetReportingConfigurationF12(
    IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
    IN SPB_CONTEXT* SpbContext,
    IN PRMI4_F12_OBJECT_REPORT_ENABLE_REGISTER ControlRegisterData
);

NTSTATUS
RmiGetSupportedControlRegistersF12(
    IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
    IN SPB_CONTEXT* SpbContext,
    OUT PRMI4_F12_QUERY_5_REGISTER ControlRegisterData
);

NTSTATUS
RmiGetSupportedDataRegistersF12(
    IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
    IN SPB_CONTEXT* SpbContext,
    OUT PRMI4_F12_QUERY_8_REGISTER ControlRegisterData
);