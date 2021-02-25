/*++
    Copyright (c) Microsoft Corporation. All Rights Reserved. 
    Sample code. Dealpoint ID #843729.

    Module Name:

        power.c

    Abstract:

        Contains Synaptics power-on and power-off functionality

    Environment:

        Kernel mode

    Revision History:

--*/

#include <compat.h>
#include <controller.h>
#include <spb.h>
#include <rmi4\rmiinternal.h>
#include <rmi4\f01\function01.h>
#include <power.tmh>

NTSTATUS 
TchWakeDevice(
   IN VOID *ControllerContext,
   IN SPB_CONTEXT *SpbContext
   )
/*++

Routine Description:

   Enables multi-touch scanning

Arguments:

   ControllerContext - Touch controller context
   
   SpbContext - A pointer to the current i2c context

Return Value:

   NTSTATUS indicating success or failure

--*/
{    
    RMI4_CONTROLLER_CONTEXT* controller;
    NTSTATUS status;

    controller = (RMI4_CONTROLLER_CONTEXT*) ControllerContext;

    //
    // Check if we were already on
    //
    if (controller->DevicePowerState == PowerDeviceD0)
    {
        goto exit;
    }

    controller->DevicePowerState = PowerDeviceD0;

    //
    // Attempt to put the controller into operating mode 
    //
    status = RmiChangeSleepState(
        controller,
        SpbContext,
        RMI4_F01_DEVICE_CONTROL_SLEEP_MODE_OPERATING);

    if (!NT_SUCCESS(status))
    {
        STDebugPrint(
            TRACE_LEVEL_ERROR,
            TRACE_POWER,
            "Error waking touch controller - %!STATUS!",
            status);
    }

exit:

    return STATUS_SUCCESS;
}

NTSTATUS
TchStandbyDevice(
   IN VOID *ControllerContext,
   IN SPB_CONTEXT *SpbContext
   )
/*++

Routine Description:

   Disables multi-touch scanning to conserve power

Arguments:

   ControllerContext - Touch controller context
   
   SpbContext - A pointer to the current i2c context

Return Value:

   NTSTATUS indicating success or failure

--*/
{
    RMI4_CONTROLLER_CONTEXT* controller;
    NTSTATUS status;

    controller = (RMI4_CONTROLLER_CONTEXT*) ControllerContext;

    //
    // Interrupts are now disabled but the ISR may still be
    // executing, so grab the controller lock to ensure ISR
    // is finished touching HW and controller state.
    //
    WdfWaitLockAcquire(controller->ControllerLock, NULL);

    //
    // Put the chip in sleep mode
    //
    status = RmiChangeSleepState(
        ControllerContext,
        SpbContext,
        RMI4_F01_DEVICE_CONTROL_SLEEP_MODE_SLEEPING);

    if (!NT_SUCCESS(status))
    {
        STDebugPrint(
            TRACE_LEVEL_ERROR,
            TRACE_POWER,
            "Error sleeping touch controller - %!STATUS!",
            status);
    }

    controller->DevicePowerState = PowerDeviceD3;

    //
    // Invalidate state
    //
    controller->TouchesReported = 0;
    controller->TouchesTotal = 0;
    controller->Cache.FingerSlotValid = 0;
    controller->Cache.FingerSlotDirty = 0;
    controller->Cache.FingerDownCount = 0;

    controller->PensReported = 0;
    controller->PensTotal = 0;
    controller->PenCache.PenSlotValid = 0;
    controller->PenCache.PenSlotDirty = 0;
    controller->PenCache.PenDownCount = 0;

    WdfWaitLockRelease(controller->ControllerLock);

    return STATUS_SUCCESS;
}