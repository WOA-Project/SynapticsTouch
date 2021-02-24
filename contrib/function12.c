// Copyright (c) Microsoft Corporation. All Rights Reserved. 
// Copyright (c) Bingxing Wang. All Rights Reserved. 

#include <compat.h>
#include <controller.h>
#include <rmiinternal.h>
#include <HidCommon.h>
#include <spb.h>
#include <rmi4\f12\controlregisters.h>
#include <function12.h>
#include <function12.tmh>

NTSTATUS
RmiConfigureReportingModes(
	IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
	IN SPB_CONTEXT* SpbContext
)
{
	NTSTATUS status;
	RMI4_F12_CONTROL_23_REGISTER ControlRegisterData = { 0 };
	RtlZeroMemory(&ControlRegisterData, sizeof(RMI4_F12_CONTROL_23_REGISTER));

	status = RmiGetReporting(
		ControllerContext,
		SpbContext,
		&ControlRegisterData
	);

	if (!NT_SUCCESS(status))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"RmiGetReporting - %!STATUS!",
			status);

		goto exit;
	}

	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Current Controller Reporting Configuration:"
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Reported Object Count: %d",
		ControlRegisterData.ReportedObjectCount
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"--== Reported Objects ==--"
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Finger: %d",
		ControlRegisterData.FingerReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		" "
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Active Stylus: %d",
		ControlRegisterData.ActiveStylusReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Cover: %d",
		ControlRegisterData.CoverReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Eraser: %d",
		ControlRegisterData.EraserReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Gloved Finger: %d",
		ControlRegisterData.GlovedFingerReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Hovering Finger: %d",
		ControlRegisterData.HoveringFingerReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Palm: %d",
		ControlRegisterData.PalmReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Small Object: %d",
		ControlRegisterData.SmallObjectReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Stylus: %d",
		ControlRegisterData.StylusReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Unclassified Object: %d",
		ControlRegisterData.UnclassifiedObjectReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Hand Edge: %d",
		ControlRegisterData.HandEdgeReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Narrow Object Swipe: %d",
		ControlRegisterData.NarrowObjectReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		" "
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"--== Reported As Finger ==--"
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Active Stylus: %d",
		ControlRegisterData.ReportActiveStylusAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Cover: %d",
		ControlRegisterData.ReportCoverAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Eraser: %d",
		ControlRegisterData.ReportEraserAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Gloved Finger: %d",
		ControlRegisterData.ReportGlovedFingerAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Hovering Finger: %d",
		ControlRegisterData.ReportHoveringFingerAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Palm: %d",
		ControlRegisterData.ReportPalmAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Small Object: %d",
		ControlRegisterData.ReportSmallObjectAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Stylus: %d",
		ControlRegisterData.ReportStylusAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Unclassified Object: %d",
		ControlRegisterData.ReportUnclassifiedObjectAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Hand Edge: %d",
		ControlRegisterData.ReportHandEdgeAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Narrow Object Swipe: %d",
		ControlRegisterData.ReportNarrowObjectSwipeAsFinger
	);

	/*
		Default config on Lumia 950s (Retail) is:
			- Reported Object Count: 10
			- Finger reporting: ON
			- Palm reporting: ON
			- Report Gloved Finger as Finger: ON
			- Everything else: OFF

		Turn on every object type and turn off reporting as finger,
		let that be handled by us instead.
	*/

	ControlRegisterData.ReportedObjectCount = 10;

	ControlRegisterData.FingerReportingEnabled = 1;
	ControlRegisterData.ActiveStylusReportingEnabled = 1;
	ControlRegisterData.CoverReportingEnabled = 1;
	ControlRegisterData.EraserReportingEnabled = 1;
	ControlRegisterData.GlovedFingerReportingEnabled = 1;
	ControlRegisterData.HoveringFingerReportingEnabled = 1;
	ControlRegisterData.PalmReportingEnabled = 1;
	ControlRegisterData.SmallObjectReportingEnabled = 1;
	ControlRegisterData.StylusReportingEnabled = 1;
	ControlRegisterData.UnclassifiedObjectReportingEnabled = 1;
	ControlRegisterData.NarrowObjectReportingEnabled = 1;
	ControlRegisterData.HandEdgeReportingEnabled = 1;

	ControlRegisterData.ReportActiveStylusAsFinger = 0;
	ControlRegisterData.ReportCoverAsFinger = 0;
	ControlRegisterData.ReportEraserAsFinger = 0;
	ControlRegisterData.ReportGlovedFingerAsFinger = 0;
	ControlRegisterData.ReportHoveringFingerAsFinger = 0;
	ControlRegisterData.ReportPalmAsFinger = 0;
	ControlRegisterData.ReportSmallObjectAsFinger = 0;
	ControlRegisterData.ReportStylusAsFinger = 0;
	ControlRegisterData.ReportUnclassifiedObjectAsFinger = 0;
	ControlRegisterData.ReportNarrowObjectSwipeAsFinger = 0;
	ControlRegisterData.ReportHandEdgeAsFinger = 0;

	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"New Controller Reporting Configuration:"
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Reported Object Count: %d",
		ControlRegisterData.ReportedObjectCount
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"--== Reported Objects ==--"
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Finger: %d",
		ControlRegisterData.FingerReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		" "
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Active Stylus: %d",
		ControlRegisterData.ActiveStylusReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Cover: %d",
		ControlRegisterData.CoverReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Eraser: %d",
		ControlRegisterData.EraserReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Gloved Finger: %d",
		ControlRegisterData.GlovedFingerReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Hovering Finger: %d",
		ControlRegisterData.HoveringFingerReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Palm: %d",
		ControlRegisterData.PalmReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Small Object: %d",
		ControlRegisterData.SmallObjectReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Stylus: %d",
		ControlRegisterData.StylusReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Unclassified Object: %d",
		ControlRegisterData.UnclassifiedObjectReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Hand Edge: %d",
		ControlRegisterData.HandEdgeReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Narrow Object Swipe: %d",
		ControlRegisterData.NarrowObjectReportingEnabled
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		" "
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"--== Reported As Finger ==--"
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Active Stylus: %d",
		ControlRegisterData.ReportActiveStylusAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Cover: %d",
		ControlRegisterData.ReportCoverAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Eraser: %d",
		ControlRegisterData.ReportEraserAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Gloved Finger: %d",
		ControlRegisterData.ReportGlovedFingerAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Hovering Finger: %d",
		ControlRegisterData.ReportHoveringFingerAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Palm: %d",
		ControlRegisterData.ReportPalmAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Small Object: %d",
		ControlRegisterData.ReportSmallObjectAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Stylus: %d",
		ControlRegisterData.ReportStylusAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Unclassified Object: %d",
		ControlRegisterData.ReportUnclassifiedObjectAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Hand Edge: %d",
		ControlRegisterData.ReportHandEdgeAsFinger
	);
	Trace(
		TRACE_LEVEL_INFORMATION,
		TRACE_INIT,
		"Narrow Object Swipe: %d",
		ControlRegisterData.ReportNarrowObjectSwipeAsFinger
	);

	status = RmiSetReporting(
		ControllerContext,
		SpbContext,
		&ControlRegisterData
	);

	if (!NT_SUCCESS(status))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"RmiSetReporting - %!STATUS!",
			status);

		goto exit;
	}

	ControllerContext->MaxFingers = ControlRegisterData.ReportedObjectCount;

exit:
	return status;
}

NTSTATUS
RmiConfigureFunction12(
	IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
	IN SPB_CONTEXT* SpbContext
)
{
	NTSTATUS status;
	int index;

	BYTE queryF12Addr = 0;
	char buf;
	USHORT data_offset = 0;
	PRMI_REGISTER_DESC_ITEM item;

	RMI4_F12_QUERY_5_REGISTER Query5Reg = { 0 };
	RMI4_F12_QUERY_8_REGISTER Query8Reg = { 0 };

	RtlZeroMemory(&Query5Reg, sizeof(RMI4_F12_QUERY_5_REGISTER));
	RtlZeroMemory(&Query8Reg, sizeof(RMI4_F12_QUERY_8_REGISTER));

	//
	// Find 2D touch sensor function and configure it
	//
	index = RmiGetFunctionIndex(
		ControllerContext->Descriptors,
		ControllerContext->FunctionCount,
		RMI4_F12_2D_TOUCHPAD_SENSOR);

	if (index == ControllerContext->FunctionCount)
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Unexpected - RMI Function 12 missing");

		status = STATUS_INVALID_DEVICE_STATE;
		goto exit;
	}

	status = RmiChangePage(
		ControllerContext,
		SpbContext,
		ControllerContext->FunctionOnPage[index]);

	if (!NT_SUCCESS(status))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Could not change register page");

		goto exit;
	}

	// Retrieve base address for queries
	queryF12Addr = ControllerContext->Descriptors[index].QueryBase;
	status = SpbReadDataSynchronously(
		SpbContext,
		queryF12Addr,
		&buf,
		sizeof(char)
	);

	if (!NT_SUCCESS(status))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Failed to read general info register - %!STATUS!",
			status);
		goto exit;
	}

	++queryF12Addr;

	if (!(buf & BIT(0)))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Behavior of F12 without register descriptors is undefined."
		);

		status = STATUS_INVALID_PARAMETER;
		goto exit;
	}

	ControllerContext->HasDribble = !!(buf & BIT(3));

	status = RmiReadRegisterDescriptor(
		SpbContext,
		queryF12Addr,
		&ControllerContext->QueryRegDesc
	);

	if (!NT_SUCCESS(status)) {

		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Failed to read the Query Register Descriptor - %!STATUS!",
			status);
		goto exit;
	}

	queryF12Addr += 3;

	status = RmiReadRegisterDescriptor(
		SpbContext,
		queryF12Addr,
		&ControllerContext->ControlRegDesc
	);

	if (!NT_SUCCESS(status)) {

		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Failed to read the Control Register Descriptor - %!STATUS!",
			status);
		goto exit;
	}
	queryF12Addr += 3;

	status = RmiReadRegisterDescriptor(
		SpbContext,
		queryF12Addr,
		&ControllerContext->DataRegDesc
	);

	if (!NT_SUCCESS(status)) {

		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Failed to read the Data Register Descriptor - %!STATUS!",
			status);
		goto exit;
	}
	queryF12Addr += 3;
	ControllerContext->PacketSize = RmiRegisterDescriptorCalcSize(
		&ControllerContext->DataRegDesc
	);

	status = RmiGetQuery5(
		ControllerContext,
		SpbContext,
		&Query5Reg);

	if (!NT_SUCCESS(status)) {

		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Failed to read the Query 5 Data Register - %!STATUS!",
			status);
		goto exit;
	}

	// Skip rmi_f12_read_sensor_tuning for the prototype.

	//
	// Try to set continuous reporting mode during touch
	//
	RmiSetReportingMode(
		ControllerContext,
		SpbContext,
		RMI_F12_REPORTING_MODE_CONTINUOUS,
		NULL);

	//
	// Try to set new configuration for reporting
	//
	RmiConfigureReportingModes(
		ControllerContext,
		SpbContext);

	/*
	* Figure out what data is contained in the data registers. HID devices
	* may have registers defined, but their data is not reported in the
	* HID attention report. Registers which are not reported in the HID
	* attention report check to see if the device is receiving data from
	* HID attention reports.
	*/
	item = RmiGetRegisterDescItem(&ControllerContext->DataRegDesc, 0);
	if (item) data_offset += (USHORT)item->RegisterSize;

	item = RmiGetRegisterDescItem(&ControllerContext->DataRegDesc, 1);
	if (item != NULL)
	{
		ControllerContext->HasData1 = TRUE;
		ControllerContext->Data1Offset = data_offset;

		data_offset += (USHORT)item->RegisterSize;
	}

	item = RmiGetRegisterDescItem(&ControllerContext->DataRegDesc, 2);
	if (item) data_offset += (USHORT)item->RegisterSize;

	item = RmiGetRegisterDescItem(&ControllerContext->DataRegDesc, 3);
	if (item) data_offset += (USHORT)item->RegisterSize;

	item = RmiGetRegisterDescItem(&ControllerContext->DataRegDesc, 4);
	if (item) data_offset += (USHORT)item->RegisterSize;

	item = RmiGetRegisterDescItem(&ControllerContext->DataRegDesc, 5);
	if (item != NULL)
	{
		ControllerContext->HasData5 = TRUE;
		ControllerContext->Data5Offset = data_offset;

		data_offset += (USHORT)item->RegisterSize;
	}

	item = RmiGetRegisterDescItem(&ControllerContext->DataRegDesc, 6);
	if (item != NULL)
	{
		ControllerContext->HasData6 = TRUE;
		ControllerContext->Data6Offset = data_offset;

		data_offset += (USHORT)item->RegisterSize;
	}

	item = RmiGetRegisterDescItem(&ControllerContext->DataRegDesc, 7);
	if (item) data_offset += (USHORT)item->RegisterSize;

	item = RmiGetRegisterDescItem(&ControllerContext->DataRegDesc, 8);
	if (item) data_offset += (USHORT)item->RegisterSize;

	item = RmiGetRegisterDescItem(&ControllerContext->DataRegDesc, 9);
	if (item != NULL)
	{
		ControllerContext->HasData9 = TRUE;
		ControllerContext->Data9Offset = data_offset;

		data_offset += (USHORT)item->RegisterSize;
	}

	item = RmiGetRegisterDescItem(&ControllerContext->DataRegDesc, 10);
	if (item) data_offset += (USHORT)item->RegisterSize;

	item = RmiGetRegisterDescItem(&ControllerContext->DataRegDesc, 11);
	if (item) data_offset += (USHORT)item->RegisterSize;

	item = RmiGetRegisterDescItem(&ControllerContext->DataRegDesc, 12);
	if (item) data_offset += (USHORT)item->RegisterSize;

	item = RmiGetRegisterDescItem(&ControllerContext->DataRegDesc, 13);
	if (item) data_offset += (USHORT)item->RegisterSize;

	item = RmiGetRegisterDescItem(&ControllerContext->DataRegDesc, 14);
	if (item) data_offset += (USHORT)item->RegisterSize;

	item = RmiGetRegisterDescItem(&ControllerContext->DataRegDesc, 15);
	if (item != NULL)
	{
		ControllerContext->HasData15 = TRUE;
		ControllerContext->Data15Offset = data_offset;

		data_offset += (USHORT)item->RegisterSize;
	}

exit:
	return status;
}

NTSTATUS
RmiGetTouchesFromController(
	IN VOID* ControllerContext,
	IN SPB_CONTEXT* SpbContext,
	IN RMI4_F11_DATA_REGISTERS* Data
)
/*++

Routine Description:

	This routine reads raw touch messages from hardware. If there is
	no touch data available (if a non-touch interrupt fired), the
	function will not return success and no touch data was transferred.

Arguments:

	ControllerContext - Touch controller context
	SpbContext - A pointer to the current i2c context
	Data - A pointer to any returned F11 touch data

Return Value:

	NTSTATUS, where only success indicates data was returned

--*/
{
	NTSTATUS status;
	RMI4_CONTROLLER_CONTEXT* controller;

	int index, i, x, y, fingers, pens;

	BYTE fingerStatus[RMI4_MAX_TOUCHES] = { 0 };
	BYTE penStatus[RMI4_MAX_TOUCHES] = { 0 };
	PRMI4_F12_DATA_1_REGISTER controllerData = NULL;

	controller = (RMI4_CONTROLLER_CONTEXT*)ControllerContext;

	//
	// Locate RMI data base address of 2D touch function
	//
	index = RmiGetFunctionIndex(
		controller->Descriptors,
		controller->FunctionCount,
		RMI4_F12_2D_TOUCHPAD_SENSOR);

	if (index == controller->FunctionCount)
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Unexpected - RMI Function 12 missing");

		status = STATUS_INVALID_DEVICE_STATE;
		goto exit;
	}

	status = RmiChangePage(
		ControllerContext,
		SpbContext,
		controller->FunctionOnPage[index]);

	if (!NT_SUCCESS(status))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Could not change register page");

		goto exit;
	}

	controllerData = ExAllocatePoolWithTag(
		NonPagedPoolNx,
		(ULONG)(controller->MaxFingers * sizeof(RMI4_F12_DATA_1_REGISTER)),
		TOUCH_POOL_TAG_F12
	);

	if (controllerData == NULL)
	{
		status = STATUS_INSUFFICIENT_RESOURCES;
		goto exit;
	}

	// 
	// Packets we need is determined by context
	//
	status = SpbReadDataSynchronously(
		SpbContext,
		controller->Descriptors[index].DataBase + (BYTE)controller->Data1Offset,
		controllerData,
		(ULONG)(controller->MaxFingers * sizeof(RMI4_F12_DATA_1_REGISTER))
	);

	if (!NT_SUCCESS(status))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INTERRUPT,
			"Error reading finger status data - %!STATUS!",
			status);

		goto free_buffer;
	}

	fingers = 0;
	pens = 0;

	for (i = 0; i < controller->MaxFingers; i++)
	{
		switch (controllerData[i].ObjectTypeAndStatus)
		{
		case RMI4_F12_OBJECT_FINGER:
			fingerStatus[i] = RMI4_FINGER_STATE_PRESENT_WITH_ACCURATE_POS;
			penStatus[i] = RMI4_PEN_STATE_NOT_PRESENT;
			fingers++;

			Trace(
				TRACE_LEVEL_INFORMATION,
				TRACE_INTERRUPT,
				"Finger[%d] status is finger",
				i);

			break;
		case RMI4_F12_OBJECT_HOVERING_FINGER:
			fingerStatus[i] = RMI4_FINGER_STATE_PRESENT_WITH_ACCURATE_POS;
			penStatus[i] = RMI4_PEN_STATE_NOT_PRESENT;
			fingers++;

			Trace(
				TRACE_LEVEL_INFORMATION,
				TRACE_INTERRUPT,
				"Finger[%d] status is hovering finger",
				i);

			break;
		case RMI4_F12_OBJECT_GLOVED_FINGER:
			fingerStatus[i] = RMI4_FINGER_STATE_PRESENT_WITH_ACCURATE_POS;
			penStatus[i] = RMI4_PEN_STATE_NOT_PRESENT;
			fingers++;

			Trace(
				TRACE_LEVEL_INFORMATION,
				TRACE_INTERRUPT,
				"Finger[%d] status is gloved finger",
				i);

			break;
		case RMI4_F12_OBJECT_ACTIVE_STYLUS:
			fingerStatus[i] = RMI4_FINGER_STATE_NOT_PRESENT;
			penStatus[i] = RMI4_PEN_STATE_PRESENT_WITH_TIP;
			pens++;

			Trace(
				TRACE_LEVEL_INFORMATION,
				TRACE_INTERRUPT,
				"Finger[%d] status is active stylus",
				i);

			break;
		case RMI4_F12_OBJECT_STYLUS:
			fingerStatus[i] = RMI4_FINGER_STATE_NOT_PRESENT;
			penStatus[i] = RMI4_PEN_STATE_PRESENT_WITH_TIP;
			pens++;

			Trace(
				TRACE_LEVEL_INFORMATION,
				TRACE_INTERRUPT,
				"Finger[%d] status is stylus",
				i);

			break;
		case RMI4_F12_OBJECT_ERASER:
			fingerStatus[i] = RMI4_FINGER_STATE_NOT_PRESENT;
			penStatus[i] = RMI4_PEN_STATE_PRESENT_WITH_ERASER;
			pens++;

			Trace(
				TRACE_LEVEL_INFORMATION,
				TRACE_INTERRUPT,
				"Finger[%d] status is eraser",
				i);

			break;
		case RMI4_F12_OBJECT_NONE:
			fingerStatus[i] = RMI4_FINGER_STATE_NOT_PRESENT;
			penStatus[i] = RMI4_PEN_STATE_NOT_PRESENT;

			/*Trace(
				TRACE_LEVEL_INFORMATION,
				TRACE_INTERRUPT,
				"Finger[%d] status is none",
				i);*/

			break;
		default:
			fingerStatus[i] = RMI4_FINGER_STATE_NOT_PRESENT;
			penStatus[i] = RMI4_PEN_STATE_NOT_PRESENT;

			Trace(
				TRACE_LEVEL_INFORMATION,
				TRACE_INTERRUPT,
				"Finger[%d] status is unknown: %d",
				i,
				controllerData[i].ObjectTypeAndStatus);

			break;
		}

		x = (controllerData[i].X_MSB << 8) | controllerData[i].X_LSB;
		y = (controllerData[i].Y_MSB << 8) | controllerData[i].Y_LSB;

		Data->Finger[i].X = x;
		Data->Finger[i].Y = y;

		if (controllerData[i].ObjectTypeAndStatus != RMI4_F12_OBJECT_NONE)
		{
			Trace(
				TRACE_LEVEL_INFORMATION,
				TRACE_INTERRUPT,
				"Finger[%d] X: %d, Y: %d, Z: %d, wX: %d, wY: %d",
				i,
				x,
				y,
				controllerData[i].Z,
				controllerData[i].wX,
				controllerData[i].wY);
		}
	}

	// Synchronize status back
	Data->Status.FingerState0 = fingerStatus[0];
	Data->Status.FingerState1 = fingerStatus[1];
	Data->Status.FingerState2 = fingerStatus[2];
	Data->Status.FingerState3 = fingerStatus[3];
	Data->Status.FingerState4 = fingerStatus[4];
	Data->Status.FingerState5 = fingerStatus[5];
	Data->Status.FingerState6 = fingerStatus[6];
	Data->Status.FingerState7 = fingerStatus[7];
	Data->Status.FingerState8 = fingerStatus[8];
	Data->Status.FingerState9 = fingerStatus[9];

	Data->Status.PenState0 = penStatus[0];
	Data->Status.PenState1 = penStatus[1];
	Data->Status.PenState2 = penStatus[2];
	Data->Status.PenState3 = penStatus[3];
	Data->Status.PenState4 = penStatus[4];
	Data->Status.PenState5 = penStatus[5];
	Data->Status.PenState6 = penStatus[6];
	Data->Status.PenState7 = penStatus[7];
	Data->Status.PenState8 = penStatus[8];
	Data->Status.PenState9 = penStatus[9];

free_buffer:
	ExFreePoolWithTag(
		controllerData,
		TOUCH_POOL_TAG_F12
	);

exit:
	return status;
}

NTSTATUS
RmiGetQuery5(
	IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
	IN SPB_CONTEXT* SpbContext,
	OUT PRMI4_F12_QUERY_5_REGISTER ControlRegisterData
)
{
	int index;
	NTSTATUS status;
	UINT8 indexQuery4;
	UINT8 indexQuery5;

	NT_ASSERT(ControlRegisterData != NULL);

	//
	// Find RMI F12 function
	//
	index = RmiGetFunctionIndex(
		ControllerContext->Descriptors,
		ControllerContext->FunctionCount,
		RMI4_F12_2D_TOUCHPAD_SENSOR);

	if (index == ControllerContext->FunctionCount)
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Set ReportingMode failure - RMI Function 12 missing");

		status = STATUS_INVALID_DEVICE_STATE;
		goto exit;
	}

	status = RmiChangePage(
		ControllerContext,
		SpbContext,
		ControllerContext->FunctionOnPage[index]);

	if (!NT_SUCCESS(status))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Could not change register page");

		goto exit;
	}

	indexQuery4 = RmiGetRegisterIndex(&ControllerContext->QueryRegDesc, 4);

	if (indexQuery4 == ControllerContext->QueryRegDesc.NumRegisters)
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Cannot find F12_2D_Query4 offset");

		status = STATUS_INVALID_DEVICE_STATE;
		goto exit;
	}

	if (ControllerContext->QueryRegDesc.Registers[indexQuery4].RegisterSize != sizeof(ControlRegisterData->Size))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Unexpected F12_2D_Query4 register size: %d", ControllerContext->QueryRegDesc.Registers[indexQuery4].RegisterSize);

		status = STATUS_INVALID_DEVICE_STATE;
		goto exit;
	}

	//
	// Read Device Control register
	//
	status = SpbReadDataSynchronously(
		SpbContext,
		ControllerContext->Descriptors[index].QueryBase + indexQuery4,
		&(ControlRegisterData->Size),
		sizeof(ControlRegisterData->Size)
	);

	if (!NT_SUCCESS(status))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Could not read F12_2D_Query4 register - %!STATUS!",
			status);

		goto exit;
	}

	if (ControlRegisterData->Size > sizeof(ControlRegisterData->Data))
		ControlRegisterData->Size = sizeof(ControlRegisterData->Data);

	indexQuery5 = RmiGetRegisterIndex(&ControllerContext->QueryRegDesc, 5);

	if (indexQuery5 == ControllerContext->QueryRegDesc.NumRegisters)
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Cannot find F12_2D_Query5 offset");

		status = STATUS_INVALID_DEVICE_STATE;
		goto exit;
	}

	if (ControllerContext->QueryRegDesc.Registers[indexQuery5].RegisterSize < ControlRegisterData->Size)
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Unexpected F12_2D_Query5 register size: %d", ControllerContext->QueryRegDesc.Registers[indexQuery5].RegisterSize);

		status = STATUS_INVALID_DEVICE_STATE;
		goto exit;
	}
	else if (ControllerContext->QueryRegDesc.Registers[indexQuery5].RegisterSize > ControlRegisterData->Size)
	{
		Trace(
			TRACE_LEVEL_WARNING,
			TRACE_INIT,
			"Higher F12_2D_Query5 register size: %d. Must expand driver!", ControllerContext->QueryRegDesc.Registers[indexQuery5].RegisterSize);
	}

	//
	// Read Device Control register
	//
	status = SpbReadDataSynchronously(
		SpbContext,
		ControllerContext->Descriptors[index].QueryBase + indexQuery5,
		&(ControlRegisterData->Data),
		ControlRegisterData->Size
	);

	if (!NT_SUCCESS(status))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Could not read F12_2D_Query5 register - %!STATUS!",
			status);

		goto exit;
	}

exit:
	return status;
}

NTSTATUS
RmiSetReportingMode(
	IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
	IN SPB_CONTEXT* SpbContext,
	IN UCHAR NewMode,
	OUT UCHAR* OldMode
)
/*++

	Routine Description:

		Changes the F12 Reporting Mode on the controller as specified

	Arguments:

		ControllerContext - Touch controller context

		SpbContext - A pointer to the current i2c context

		NewMode - Either RMI_F12_REPORTING_MODE_CONTINUOUS
				  or RMI_F12_REPORTING_MODE_REDUCED

		OldMode - Old value of reporting mode

	Return Value:

		NTSTATUS indicating success or failure

--*/
{
	UCHAR reportingControl[3];
	int index;
	NTSTATUS status;
	UINT8 indexCtrl20;

	//
	// Find RMI F12 function
	//
	index = RmiGetFunctionIndex(
		ControllerContext->Descriptors,
		ControllerContext->FunctionCount,
		RMI4_F12_2D_TOUCHPAD_SENSOR);

	if (index == ControllerContext->FunctionCount)
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Set ReportingMode failure - RMI Function 12 missing");

		status = STATUS_INVALID_DEVICE_STATE;
		goto exit;
	}

	status = RmiChangePage(
		ControllerContext,
		SpbContext,
		ControllerContext->FunctionOnPage[index]);

	if (!NT_SUCCESS(status))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Could not change register page");

		goto exit;
	}

	indexCtrl20 = RmiGetRegisterIndex(&ControllerContext->ControlRegDesc, F12_2D_CTRL20);

	if (indexCtrl20 == ControllerContext->ControlRegDesc.NumRegisters)
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Cannot find F12_2D_Ctrl20 offset");

		status = STATUS_INVALID_DEVICE_STATE;
		goto exit;
	}

	if (ControllerContext->ControlRegDesc.Registers[indexCtrl20].RegisterSize != sizeof(reportingControl))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Unexpected F12_2D_Ctrl20 register size");

		status = STATUS_INVALID_DEVICE_STATE;
		goto exit;
	}

	//
	// Read Device Control register
	//
	status = SpbReadDataSynchronously(
		SpbContext,
		ControllerContext->Descriptors[index].ControlBase + indexCtrl20,
		&reportingControl,
		sizeof(reportingControl)
	);

	if (!NT_SUCCESS(status))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Could not read F12_2D_Ctrl20 register - %!STATUS!",
			status);

		goto exit;
	}

	if (OldMode)
	{
		*OldMode = reportingControl[0] & RMI_F12_REPORTING_MODE_MASK;
	}

	//
	// Assign new value
	//
	reportingControl[0] &= ~RMI_F12_REPORTING_MODE_MASK;
	reportingControl[0] |= NewMode & RMI_F12_REPORTING_MODE_MASK;

	//
	// Write setting back to the controller
	//
	status = SpbWriteDataSynchronously(
		SpbContext,
		ControllerContext->Descriptors[index].ControlBase + indexCtrl20,
		&reportingControl,
		sizeof(reportingControl)
	);

	if (!NT_SUCCESS(status))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Could not write F12_2D_Ctrl20 register - %X",
			status);

		goto exit;
	}

exit:

	return status;
}

NTSTATUS
RmiGetReporting(
	IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
	IN SPB_CONTEXT* SpbContext,
	OUT PRMI4_F12_CONTROL_23_REGISTER ControlRegisterData
)
{
	int index;
	NTSTATUS status;
	UINT8 indexCtrl23;

	NT_ASSERT(ControlRegisterData != NULL);

	//
	// Find RMI F12 function
	//
	index = RmiGetFunctionIndex(
		ControllerContext->Descriptors,
		ControllerContext->FunctionCount,
		RMI4_F12_2D_TOUCHPAD_SENSOR);

	if (index == ControllerContext->FunctionCount)
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Set ReportingMode failure - RMI Function 12 missing");

		status = STATUS_INVALID_DEVICE_STATE;
		goto exit;
	}

	status = RmiChangePage(
		ControllerContext,
		SpbContext,
		ControllerContext->FunctionOnPage[index]);

	if (!NT_SUCCESS(status))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Could not change register page");

		goto exit;
	}

	indexCtrl23 = RmiGetRegisterIndex(&ControllerContext->ControlRegDesc, F12_2D_CTRL23);

	if (indexCtrl23 == ControllerContext->ControlRegDesc.NumRegisters)
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Cannot find F12_2D_Ctrl23 offset");

		status = STATUS_INVALID_DEVICE_STATE;
		goto exit;
	}

	if (ControllerContext->ControlRegDesc.Registers[indexCtrl23].RegisterSize != sizeof(RMI4_F12_CONTROL_23_REGISTER))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Unexpected F12_2D_Ctrl23 register size: %d", ControllerContext->ControlRegDesc.Registers[indexCtrl23].RegisterSize);

		status = STATUS_INVALID_DEVICE_STATE;
		goto exit;
	}

	//
	// Read Device Control register
	//
	status = SpbReadDataSynchronously(
		SpbContext,
		ControllerContext->Descriptors[index].ControlBase + indexCtrl23,
		ControlRegisterData,
		sizeof(RMI4_F12_CONTROL_23_REGISTER)
	);

	if (!NT_SUCCESS(status))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Could not read F12_2D_Ctrl23 register - %!STATUS!",
			status);

		goto exit;
	}

exit:

	return status;
}

NTSTATUS
RmiSetReporting(
	IN RMI4_CONTROLLER_CONTEXT* ControllerContext,
	IN SPB_CONTEXT* SpbContext,
	IN PRMI4_F12_CONTROL_23_REGISTER ControlRegisterData
)
{
	int index;
	NTSTATUS status;
	UINT8 indexCtrl23;

	//
	// Find RMI F12 function
	//
	index = RmiGetFunctionIndex(
		ControllerContext->Descriptors,
		ControllerContext->FunctionCount,
		RMI4_F12_2D_TOUCHPAD_SENSOR);

	if (index == ControllerContext->FunctionCount)
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Set ReportingMode failure - RMI Function 12 missing");

		status = STATUS_INVALID_DEVICE_STATE;
		goto exit;
	}

	status = RmiChangePage(
		ControllerContext,
		SpbContext,
		ControllerContext->FunctionOnPage[index]);

	if (!NT_SUCCESS(status))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Could not change register page");

		goto exit;
	}

	indexCtrl23 = RmiGetRegisterIndex(&ControllerContext->ControlRegDesc, F12_2D_CTRL23);

	if (indexCtrl23 == ControllerContext->ControlRegDesc.NumRegisters)
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Cannot find F12_2D_Ctrl23 offset");

		status = STATUS_INVALID_DEVICE_STATE;
		goto exit;
	}

	if (ControllerContext->ControlRegDesc.Registers[indexCtrl23].RegisterSize != sizeof(RMI4_F12_CONTROL_23_REGISTER))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Unexpected F12_2D_Ctrl23 register size: %d", ControllerContext->ControlRegDesc.Registers[indexCtrl23].RegisterSize);

		status = STATUS_INVALID_DEVICE_STATE;
		goto exit;
	}

	//
	// Write setting back to the controller
	//
	status = SpbWriteDataSynchronously(
		SpbContext,
		ControllerContext->Descriptors[index].ControlBase + indexCtrl23,
		ControlRegisterData,
		sizeof(RMI4_F12_CONTROL_23_REGISTER)
	);

	if (!NT_SUCCESS(status))
	{
		Trace(
			TRACE_LEVEL_ERROR,
			TRACE_INIT,
			"Could not write F12_2D_Ctrl23 register - %X",
			status);

		goto exit;
	}

exit:

	return status;
}