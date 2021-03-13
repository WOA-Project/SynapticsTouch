// Copyright (c) Microsoft Corporation. All Rights Reserved. 
// Copyright (c) Bingxing Wang. All Rights Reserved. 

#pragma once

//
// Global Data Declarations
//
extern const PWSTR gpwstrManufacturerID;
extern const PWSTR gpwstrProductID;
extern const PWSTR gpwstrSerialNumber;
extern const USHORT gOEMVendorID;
extern const USHORT gOEMProductID;
extern const USHORT gOEMVersionID;

//
// Function prototypes
//

NTSTATUS
TchGetDeviceAttributes(
    IN WDFREQUEST Request
    );

NTSTATUS 
TchGetFeatureReport(
    IN WDFDEVICE Device,
    IN WDFREQUEST Request
    );

NTSTATUS
TchGetHidDescriptor(
    IN WDFDEVICE Device,
    IN WDFREQUEST Request
    );

NTSTATUS
TchGetReportDescriptor(
    IN WDFDEVICE Device,
    IN WDFREQUEST Request
    );

NTSTATUS 
TchGetString(
    IN WDFDEVICE Device,
    IN WDFREQUEST Request
    );

NTSTATUS
TchProcessIdleRequest(
    IN  WDFDEVICE Device,
    IN  WDFREQUEST Request,
    OUT BOOLEAN *Pending
    );

NTSTATUS 
TchSetFeatureReport(
    IN WDFDEVICE Device,
    IN WDFREQUEST Request
    );
    
NTSTATUS 
TchReadReport(
    IN  WDFDEVICE Device,
    IN  WDFREQUEST Request,
    OUT BOOLEAN *Pending
    );

//
// HID collections
// 
#include "HidCommon.h"

#define SYNAPTICS_PTP_FINGER_COLLECTION_1 \
	BEGIN_COLLECTION, 0x02, /* Begin Collection: Logical */ \
		/* Begin a byte */ \
		LOGICAL_MAXIMUM, 0x01, /* Logical Maximum: 1 */ \
		USAGE, 0x47, /* Usage: Confidence */ \
		USAGE, 0x42, /* Usage: Tip switch */ \
		REPORT_COUNT, 0x02, /* Report Count: 2 */ \
		REPORT_SIZE, 0x01, /* Report Size: 1 */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		REPORT_COUNT, 0x01, /* Report Count: 1 */ \
		REPORT_SIZE, 0x03, /* Report Size: 3 */ \
		LOGICAL_MAXIMUM, 0x03, /* Logical Maximum: 3 */ \
		USAGE, 0x51, /* Usage: Contract Identifier */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		REPORT_SIZE, 0x01, /* Report Size: 1 */ \
		REPORT_COUNT, 0x03, /* Report Count: 3 */ \
		INPUT, 0x03, /* Input: (Const, Var, Abs) */ \
		/* End of a byte */ \
		/* Begin of 4 bytes */ \
		/* Size is hard-coded at this moment */ \
		/* This hard-coded size is designed for Lumia 950 XL */ \
		USAGE_PAGE, 0x01, /* Usage Page: Generic Desktop */ \
		LOGICAL_MAXIMUM_2, 0xA0, 0x05, /* Logical Maximum: 1440 (See defintion) */ \
		REPORT_SIZE, 0x10, /* Report Size: 0x10 (2 bytes) */ \
		UNIT_EXPONENT, 0x0e, /* Unit exponent: -2 */ \
		UNIT, 0x11, /* Unit: SI Length (cm) */ \
		USAGE, 0x30, /* Usage: X */ \
		PHYSICAL_MAXIMUM_2, 0xce, 0x02, /* Physical Maximum: 7.18 */ \
		REPORT_COUNT, 0x01, /* Report count: 1 */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		PHYSICAL_MAXIMUM_2, 0xeb, 0x04, /* Physical Maximum: 12.59 */ \
		LOGICAL_MAXIMUM_2, 0x00, 0x0a, /* Logical Maximum: 2560 (See definition) */ \
		USAGE, 0x31, /* Usage: Y */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		PHYSICAL_MAXIMUM, 0x00, /* Physical Maximum: 0 */ \
		UNIT_EXPONENT, 0x00, /* Unit exponent: 0 */ \
		UNIT, 0x00, /* Unit: None */ \
		/* End of 4 bytes */ \
	END_COLLECTION /* End Collection */ \

#define SYNAPTICS_PTP_FINGER_COLLECTION_2 \
	BEGIN_COLLECTION, 0x02, /* Begin Collection: Logical */ \
		/* Begin a byte */ \
		LOGICAL_MAXIMUM, 0x01, /* Logical Maximum: 1 */ \
		USAGE, 0x47, /* Usage: Confidence */ \
		USAGE, 0x42, /* Usage: Tip switch */ \
		REPORT_COUNT, 0x02, /* Report Count: 2 */ \
		REPORT_SIZE, 0x01, /* Report Size: 1 */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		REPORT_COUNT, 0x01, /* Report Count: 1 */ \
		REPORT_SIZE, 0x03, /* Report Size: 3 */ \
		LOGICAL_MAXIMUM, 0x03, /* Logical Maximum: 3 */ \
		USAGE, 0x51, /* Usage: Contract Identifier */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		REPORT_SIZE, 0x01, /* Report Size: 1 */ \
		REPORT_COUNT, 0x03, /* Report Count: 3 */ \
		INPUT, 0x03, /* Input: (Const, Var, Abs) */ \
		/* End of a byte */ \
		/* Begin of 4 bytes */ \
		/* This hard-coded size is designed for Lumia 950 XL */ \
		USAGE_PAGE, 0x01, /* Usage Page: Generic Desktop */ \
		LOGICAL_MAXIMUM_2, 0xA0, 0x05, /* Logical Maximum: 1440 (See defintion) */ \
		REPORT_SIZE, 0x10, /* Report Size: 0x10 (2 bytes) */ \
		UNIT_EXPONENT, 0x0e, /* Unit exponent: -2 */ \
		UNIT, 0x11, /* Unit: SI Length (cm) */ \
		USAGE, 0x30, /* Usage: X */ \
		PHYSICAL_MAXIMUM_2, 0xce, 0x02, /* Physical Maximum: 7.18 */ \
		REPORT_COUNT, 0x01, /* Report count: 1 */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		PHYSICAL_MAXIMUM_2, 0xeb, 0x04, /* Physical Maximum: 12.59 */ \
		LOGICAL_MAXIMUM_2, 0x00, 0x0a, /* Logical Maximum: 2560 (See definition) */ \
		USAGE, 0x31, /* Usage: Y */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		/* End of 4 bytes */ \
	END_COLLECTION /* End Collection */ \

#define SYNAPTICS_PTP_TLC \
	USAGE_PAGE, 0x0d, /* Usage Page: Digitizer */ \
	USAGE, 0x05, /* Usage: Touch Pad */ \
	BEGIN_COLLECTION, 0x01, /* Begin Collection: Application */ \
		REPORT_ID, REPORTID_MULTITOUCH, /* Report ID: Multi-touch */ \
		USAGE, 0x22, /* Usage: Finger */ \
		SYNAPTICS_PTP_FINGER_COLLECTION_1, /* 1 */ \
		USAGE_PAGE, 0x0d, /* Usage Page: Digitizer */ \
		USAGE, 0x22, /* Usage: Finger */ \
		SYNAPTICS_PTP_FINGER_COLLECTION_1, /* 2 */ \
		USAGE_PAGE, 0x0d, /* Usage Page: Digitizer */ \
		USAGE, 0x22, /* Usage: Finger */ \
		SYNAPTICS_PTP_FINGER_COLLECTION_2, /* 3 */ \
		USAGE_PAGE, 0x0d, /* Usage Page: Digitizer */ \
		USAGE, 0x22, /* Usage: Finger */ \
		SYNAPTICS_PTP_FINGER_COLLECTION_1, /* 4 */ \
		USAGE_PAGE, 0x0d, /* Usage Page: Digitizer */ \
		USAGE, 0x22, /* Usage: Finger */ \
		SYNAPTICS_PTP_FINGER_COLLECTION_2, /* 5 */ \
		USAGE_PAGE, 0x0d, /* Usage Page: Digitizer */ \
		UNIT_EXPONENT, 0x0c, /* Unit exponent: -4 */ \
		UNIT_2, 0x01, 0x10, /* Time: Second */ \
		PHYSICAL_MAXIMUM_3, 0xff, 0xff, 0x00, 0x00, \
		LOGICAL_MAXIMUM_3, 0xff, 0xff, 0x00, 0x00, \
		USAGE, 0x56, /* Usage: Scan Time */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x54, /* Usage: Contact Count */ \
		LOGICAL_MAXIMUM, 0x7f, \
		REPORT_SIZE, 0x08, \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE_PAGE, 0x09, /* Usage Page: Button */ \
		USAGE, 0x01, /* Button 1 */ \
		LOGICAL_MAXIMUM, 0x01, \
		REPORT_SIZE, 0x01, \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		REPORT_COUNT, 0x07, \
		INPUT, 0x03, /* Input: (Const, Var, Abs) */ \
		USAGE_PAGE, 0x0d, /* Usage Page: Digitizer */ \
		REPORT_ID, REPORTID_DEVICE_CAPS, \
		USAGE, 0x55, /* Usage: Maximum Contacts */ \
		USAGE, 0x59, /* Usage: Touchpad Button Type*/ \
		LOGICAL_MINIMUM, 0x00, \
		LOGICAL_MAXIMUM_2, 0xff, 0x00, \
		REPORT_SIZE, 0x08, \
		REPORT_COUNT, 0x02, \
		FEATURE, 0x02, \
		USAGE_PAGE_1, 0x00, 0xff, \
		REPORT_ID, REPORTID_PTPHQA, \
		USAGE, 0xc5, \
		LOGICAL_MINIMUM, 0x00, \
		LOGICAL_MAXIMUM_2, 0xff, 0x00, \
		REPORT_SIZE, 0x08, \
		REPORT_COUNT_2, 0x00, 0x01, \
		FEATURE, 0x02, \
	END_COLLECTION /* End Collection */

#define SYNAPTICS_TOUCHSCREEN_TLC \
	USAGE_PAGE, 0x0d, /* Usage Page: Digitizer */ \
	USAGE, 0x04, /* Usage: Touch Screen */ \
	BEGIN_COLLECTION, 0x01, /* Begin Collection: Application */ \
		REPORT_ID, REPORTID_MULTITOUCH, /* Report ID: Multi-touch */ \
		USAGE, 0x22, /* Usage: Finger */ \
		SYNAPTICS_PTP_FINGER_COLLECTION_1, /* 1 */ \
		USAGE_PAGE, 0x0d, /* Usage Page: Digitizer */ \
		USAGE, 0x22, /* Usage: Finger */ \
		SYNAPTICS_PTP_FINGER_COLLECTION_1, /* 2 */ \
		USAGE_PAGE, 0x0d, /* Usage Page: Digitizer */ \
		USAGE, 0x22, /* Usage: Finger */ \
		SYNAPTICS_PTP_FINGER_COLLECTION_2, /* 3 */ \
		USAGE_PAGE, 0x0d, /* Usage Page: Digitizer */ \
		USAGE, 0x22, /* Usage: Finger */ \
		SYNAPTICS_PTP_FINGER_COLLECTION_1, /* 4 */ \
		USAGE_PAGE, 0x0d, /* Usage Page: Digitizer */ \
		USAGE, 0x22, /* Usage: Finger */ \
		SYNAPTICS_PTP_FINGER_COLLECTION_2, /* 5 */ \
		USAGE_PAGE, 0x0d, /* Usage Page: Digitizer */ \
		UNIT_EXPONENT, 0x0c, /* Unit exponent: -4 */ \
		UNIT_2, 0x01, 0x10, /* Time: Second */ \
		PHYSICAL_MAXIMUM_3, 0xff, 0xff, 0x00, 0x00, \
		LOGICAL_MAXIMUM_3, 0xff, 0xff, 0x00, 0x00, \
		USAGE, 0x56, /* Usage: Scan Time */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x54, /* Usage: Contact Count */ \
		LOGICAL_MAXIMUM, 0x7f, \
		REPORT_SIZE, 0x08, \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE_PAGE, 0x09, /* Usage Page: Button */ \
		USAGE, 0x01, /* Button 1 */ \
		LOGICAL_MAXIMUM, 0x01, \
		REPORT_SIZE, 0x01, \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		REPORT_COUNT, 0x07, \
		INPUT, 0x03, /* Input: (Const, Var, Abs) */ \
		USAGE_PAGE, 0x0d, /* Usage Page: Digitizer */ \
		REPORT_ID, REPORTID_DEVICE_CAPS, \
		USAGE, 0x55, /* Usage: Maximum Contacts */ \
		USAGE, 0x59, /* Usage: Touchpad Button Type*/ \
		LOGICAL_MINIMUM, 0x00, \
		LOGICAL_MAXIMUM_2, 0xff, 0x00, \
		REPORT_SIZE, 0x08, \
		REPORT_COUNT, 0x02, \
		FEATURE, 0x02, \
		USAGE_PAGE_1, 0x00, 0xff, \
		REPORT_ID, REPORTID_PTPHQA, \
		USAGE, 0xc5, \
		LOGICAL_MINIMUM, 0x00, \
		LOGICAL_MAXIMUM_2, 0xff, 0x00, \
		REPORT_SIZE, 0x08, \
		REPORT_COUNT_2, 0x00, 0x01, \
		FEATURE, 0x02, \
	END_COLLECTION /* End Collection */

#define SYNAPTICS_PEN_COLLECTION_1 \
	BEGIN_COLLECTION, 0x02, /* Begin Collection: Logical */ \
		/* Begin a byte */ \
		LOGICAL_MAXIMUM, 0x01, /* Logical Maximum: 1 */ \
		USAGE, 0x32, /* Usage: In Range */ \
		USAGE, 0x42, /* Usage: Tip switch */ \
		REPORT_COUNT, 0x02, /* Report Count: 2 */ \
		REPORT_SIZE, 0x01, /* Report Size: 1 */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		REPORT_COUNT, 0x01, /* Report Count: 1 */ \
		REPORT_SIZE, 0x03, /* Report Size: 3 */ \
		LOGICAL_MAXIMUM, 0x03, /* Logical Maximum: 3 */ \
		USAGE, 0x45, /* Usage: Eraser */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		REPORT_SIZE, 0x01, /* Report Size: 1 */ \
		REPORT_COUNT, 0x03, /* Report Count: 3 */ \
		INPUT, 0x03, /* Input: (Const, Var, Abs) */ \
		/* End of a byte */ \
		/* Begin of 4 bytes */ \
		/* Size is hard-coded at this moment */ \
		/* This hard-coded size is designed for Lumia 950 XL */ \
		USAGE_PAGE, 0x01, /* Usage Page: Generic Desktop */ \
		LOGICAL_MAXIMUM_2, 0xA0, 0x05, /* Logical Maximum: 1440 (See defintion) */ \
		REPORT_SIZE, 0x10, /* Report Size: 0x10 (2 bytes) */ \
		UNIT_EXPONENT, 0x0e, /* Unit exponent: -2 */ \
		UNIT, 0x11, /* Unit: SI Length (cm) */ \
		USAGE, 0x30, /* Usage: X */ \
		PHYSICAL_MAXIMUM_2, 0xce, 0x02, /* Physical Maximum: 7.18 */ \
		REPORT_COUNT, 0x01, /* Report count: 1 */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		PHYSICAL_MAXIMUM_2, 0xeb, 0x04, /* Physical Maximum: 12.59 */ \
		LOGICAL_MAXIMUM_2, 0x00, 0x0a, /* Logical Maximum: 2560 (See definition) */ \
		USAGE, 0x31, /* Usage: Y */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		PHYSICAL_MAXIMUM, 0x00, /* Physical Maximum: 0 */ \
		UNIT_EXPONENT, 0x00, /* Unit exponent: 0 */ \
		UNIT, 0x00, /* Unit: None */ \
		/* End of 4 bytes */ \
	END_COLLECTION /* End Collection */ \

#define SYNAPTICS_PEN_TLC \
	USAGE_PAGE, 0x0d, /* Usage Page: Digitizer */ \
	USAGE, 0x02, /* Usage: Pen */ \
	BEGIN_COLLECTION, 0x01, /* Begin Collection: Application */ \
		REPORT_ID, REPORTID_PEN, /* Report ID: Pen */ \
		USAGE, 0x20, /* Usage: Stylus */ \
		SYNAPTICS_PEN_COLLECTION_1, /* 1 */  \
		USAGE_PAGE, 0x0d, /* Usage Page: Digitizer */ \
		UNIT_EXPONENT, 0x0c, /* Unit exponent: -4 */ \
		UNIT_2, 0x01, 0x10, /* Time: Second */ \
		PHYSICAL_MAXIMUM_3, 0xff, 0xff, 0x00, 0x00, \
		LOGICAL_MAXIMUM_3, 0xff, 0xff, 0x00, 0x00, \
		USAGE, 0x56, /* Usage: Scan Time */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE_PAGE_1, 0x00, 0xff, \
		REPORT_ID, REPORTID_PENHQA, \
		USAGE, 0xc5, \
		LOGICAL_MINIMUM, 0x00, \
		LOGICAL_MAXIMUM_2, 0xff, 0x00, \
		REPORT_SIZE, 0x08, \
		REPORT_COUNT_2, 0x00, 0x01, \
		FEATURE, 0x02, \
	END_COLLECTION /* End Collection */

#define SYNAPTICS_CONFIGURATION_TLC \
	USAGE_PAGE, 0x0d, /* Usage Page: Digitizer */ \
	USAGE, 0x0e, /* Usage: Configuration */ \
	BEGIN_COLLECTION, 0x01, /* Begin Collection: Application */ \
		REPORT_ID, REPORTID_REPORTMODE, /* Report ID: Mode Selection */ \
		USAGE, 0x22, /* Usage: Finger */ \
		BEGIN_COLLECTION, 0x02, /* Begin Collection: Logical */ \
			USAGE, 0x52, /* Usage: Input Mode */ \
			LOGICAL_MINIMUM, 0x00, /* Logical Minumum: 0 finger */ \
			LOGICAL_MAXIMUM, MAX_FINGERS, /* Logical Maximum: MAX_TOUCH_COUNT fingers */ \
			REPORT_SIZE, 0x08, /* Report Size: 0x08 */ \
			REPORT_COUNT, 0x01, /* Report Count: 0x01 */ \
			FEATURE, 0x02, /* Feature: (Data, Var, Abs) */ \
		END_COLLECTION, /* End Collection */ \
		BEGIN_COLLECTION, 0x00, /* Begin Collection: Physical */ \
			REPORT_ID, REPORTID_FUNCSWITCH, /* Report ID: Function Switch */ \
			USAGE, BUTTON_SWITCH, /* Usage: Button Switch */ \
			USAGE, SURFACE_SWITCH, /* Usage: Surface Switch */ \
			REPORT_SIZE, 0x01, /* Report Size: 0x01 */ \
			REPORT_COUNT, 0x02, /* Report Count: 0x02 */ \
			LOGICAL_MAXIMUM, 0x01, /* Logical Maximum: 0x01 */ \
			FEATURE, 0x02, /* Feature: (Data, Var, Abs) */ \
			REPORT_COUNT, 0x06, /* Report Count: 0x06 */ \
			FEATURE, 0x03, /* Feature: (Const, Var, Abs) */ \
		END_COLLECTION, /* End Collection */ \
	END_COLLECTION /* End Collection */

//
// [New] HID collections
// 
#define SYNAPTICS_RMI4_DIGITIZER_FINGER_CONTACT_1 \
	BEGIN_COLLECTION, 0x02, /* Collection (Logical) */ \
		USAGE, 0x42, /* Usage (Tip Switch) */ \
		LOGICAL_MINIMUM, 0x00, /* Logical Minimum (0) */ \
		LOGICAL_MAXIMUM, 0x01, /* Logical Maximum (1) */ \
		PHYSICAL_MINIMUM, 0x00, /* Physical Minimum (0) */ \
		PHYSICAL_MAXIMUM, 0x01, /* Physical Maximum (1) */ \
		UNIT, 0x00, /* Unit (None) */ \
		UNIT_EXPONENT, 0x00, /* Unit Exponent (0) */ \
		REPORT_SIZE, 0x01, /* Report Size (1) */ \
		REPORT_COUNT, 0x01, /* Report Count (1) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x32, /* Usage (In Range) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x47, /* Usage (Confidence) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		REPORT_COUNT, 0x05, /* Report Count (5) */ \
		INPUT, 0x03, /* Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */ \
		USAGE, 0x51, /* Usage (Contract Identifier) */ \
		PHYSICAL_MAXIMUM, 0x00, /* Physical Maximum (0) */ \
		REPORT_SIZE, 0x08, /* Report Size (8) */ \
		REPORT_COUNT, 0x01, /* Report Count (1) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE_PAGE, 0x01, /* Usage Page (Generic Desktop Ctrls) */ \
		USAGE, 0x30, /* Usage (X) */ \
		LOGICAL_MAXIMUM_2, 0xA0, 0x05, /* Logical Maximum (1440) */ \
		PHYSICAL_MAXIMUM_2, 0xCE, 0x02, /* Physical Maximum (7.18) */ \
		UNIT, 0x11, /* Unit (System: SI Linear, Length: Centimeter) */ \
		UNIT_EXPONENT, 0x0E, /* Unit Exponent (-2) */ \
		REPORT_SIZE, 0x10, /* Report Size (16) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x31, /* Usage (Y) */ \
		LOGICAL_MAXIMUM_2, 0x00, 0x0A, /* Logical Maximum (2560) */ \
		PHYSICAL_MAXIMUM_2, 0xEB, 0x04, /* Physical Maximum (12.59) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		PHYSICAL_MAXIMUM, 0x00, /* Physical Maximum: 0 */ \
		UNIT_EXPONENT, 0x00, /* Unit exponent: 0 */ \
		UNIT, 0x00, /* Unit: None */ \
	END_COLLECTION /* End Collection */

#define SYNAPTICS_RMI4_DIGITIZER_FINGER_CONTACT_2 \
	BEGIN_COLLECTION, 0x02, /* Collection (Logical) */ \
		USAGE_PAGE, 0x0D, /* Usage Page (Digitizer) */ \
		USAGE, 0x42, /* Usage (Tip Switch) */ \
		LOGICAL_MAXIMUM, 0x01, /* Logical Maximum (1) */ \
		PHYSICAL_MAXIMUM, 0x01, /* Physical Maximum (1) */ \
		UNIT, 0x00, /* Unit (None) */ \
		UNIT_EXPONENT, 0x00, /* Unit Exponent (0) */ \
		REPORT_SIZE, 0x01, /* Report Size (1) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x32, /* Usage (In Range) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x47, /* Usage (Confidence) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		REPORT_COUNT, 0x05, /* Report Count (5) */ \
		INPUT, 0x03, /* Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */ \
		USAGE, 0x51, /* Usage (Contract Identifier) */ \
		PHYSICAL_MAXIMUM_2, 0xEB, 0x04, /* Physical Maximum (12.59) */ \
		UNIT, 0x11, /* Unit (System: SI Linear, Length: Centimeter) */ \
		UNIT_EXPONENT, 0x0E, /* Unit Exponent (-2) */ \
		REPORT_SIZE, 0x08, /* Report Size (8) */ \
		REPORT_COUNT, 0x01, /* Report Count (1) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE_PAGE, 0x01, /* Usage Page (Generic Desktop Ctrls) */ \
		USAGE, 0x30, /* Usage (X) */ \
		LOGICAL_MAXIMUM_2, 0xA0, 0x05, /* Logical Maximum (1440) */ \
		PHYSICAL_MAXIMUM_2, 0xCE, 0x02, /* Physical Maximum (7.18) */ \
		REPORT_SIZE, 0x10, /* Report Size (16) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x31, /* Usage (Y) */ \
		LOGICAL_MAXIMUM_2, 0x00, 0x0A, /* Logical Maximum (2560) */ \
		PHYSICAL_MAXIMUM_2, 0xEB, 0x04, /* Physical Maximum (12.59) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		PHYSICAL_MAXIMUM, 0x00, /* Physical Maximum: 0 */ \
		UNIT_EXPONENT, 0x00, /* Unit exponent: 0 */ \
		UNIT, 0x00, /* Unit: None */ \
	END_COLLECTION /* End Collection */

#define SYNAPTICS_RMI4_DIGITIZER_STYLUS_CONTACT_1 \
	BEGIN_COLLECTION, 0x00, /* Collection (Physical) */ \
		USAGE, 0x42, /* Usage (Tip Switch) */ \
		LOGICAL_MINIMUM, 0x00, /* Logical Minimum (0) */ \
		LOGICAL_MAXIMUM, 0x01, /* Logical Maximum (1) */ \
		PHYSICAL_MINIMUM, 0x00, /* Physical Minimum (0) */ \
		PHYSICAL_MAXIMUM, 0x01, /* Physical Maximum (1) */ \
		UNIT, 0x00, /* Unit (None) */ \
		UNIT_EXPONENT, 0x00, /* Unit Exponent (0) */ \
		REPORT_SIZE, 0x01, /* Report Size (1) */ \
		REPORT_COUNT, 0x01, /* Report Count (1) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x44, /* Usage (Barrel Switch) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x3C, /* Usage (Invert) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x45, /* Usage (Eraser) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		INPUT, 0x03, /* Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */ \
		USAGE, 0x32, /* Usage (In Range) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		REPORT_COUNT, 0x02, /* Report Count (2) */ \
		INPUT, 0x03, /* Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */ \
		USAGE_PAGE, 0x01, /* Usage Page (Generic Desktop Ctrls) */ \
		USAGE, 0x30, /* Usage (X) */ \
		LOGICAL_MAXIMUM_2, 0xA0, 0x05, /* Logical Maximum (1440) */ \
		PHYSICAL_MAXIMUM_2, 0xCE, 0x02, /* Physical Maximum (7.18) */ \
		UNIT, 0x11, /* Unit (System: SI Linear, Length: Centimeter) */ \
		UNIT_EXPONENT, 0x0E, /* Unit Exponent (-2) */ \
		REPORT_SIZE, 0x10, /* Report Size (16) */ \
		REPORT_COUNT, 0x01, /* Report Count (1) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x31, /* Usage (Y) */ \
		LOGICAL_MAXIMUM_2, 0x00, 0x0A, /* Logical Maximum (2560) */ \
		PHYSICAL_MAXIMUM_2, 0xEB, 0x04, /* Physical Maximum (12.59) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE_PAGE, 0x0D, /* Usage Page (Digitizer) */ \
		USAGE, 0x30, /* Usage (Tip Pressure) */ \
		LOGICAL_MAXIMUM, 0xFF, /* Logical Maximum (-1) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x3D, /* Usage (X Tilt) */ \
		LOGICAL_MAXIMUM, 0x7F, /* Logical Maximum (127) */ \
		REPORT_SIZE, 0x08, /* Report Size (8) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x3E, /* Usage (Y Tilt) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		PHYSICAL_MAXIMUM, 0x00, /* Physical Maximum: 0 */ \
		UNIT_EXPONENT, 0x00, /* Unit exponent: 0 */ \
		UNIT, 0x00, /* Unit: None */ \
	END_COLLECTION /* End Collection */

#define SYNAPTICS_RMI4_DIGITIZER_PUCK_CONTACT_1 \
	BEGIN_COLLECTION, 0x00, /* COLLECTION (Physical) */ \
		USAGE_PAGE, 0x09, /* USAGE_PAGE (Buttons) */ \
		USAGE, 0x01, /* USAGE (Button 1) */ \
		REPORT_COUNT, 0x01, /* REPORT_COUNT (1) */ \
		REPORT_SIZE, 0x01, /* REPORT_SIZE (1) */ \
		LOGICAL_MINIMUM, 0x00, /* LOGICAL_MINIMUM (0) */ \
		LOGICAL_MAXIMUM, 0x01, /* LOGICAL_MAXIMUM (1) */ \
		INPUT, 0x02, /* INPUT (Data,Var,Abs) */ \
		USAGE_PAGE, 0x01, /* USAGE_PAGE (Generic Desktop) */ \
		USAGE, 0x37, /* USAGE (Dial) */ \
		REPORT_COUNT, 0x01, /* REPORT_COUNT (1) */ \
		REPORT_SIZE, 0x0f, /* REPORT_SIZE (15) */ \
		UNIT_EXPONENT, 0x0f, /* UNIT_EXPONENT (-1) */ \
		UNIT, 0x14, /* UNIT (Degrees, English Rotation) */ \
		PHYSICAL_MINIMUM_2, 0xf0, 0xf1, /* PHYSICAL_MINIMUM (-3600) */ \
		PHYSICAL_MAXIMUM_2, 0x10, 0x0e, /* PHYSICAL_MAXIMUM (3600) */ \
		LOGICAL_MINIMUM_2, 0xf0, 0xf1, /* LOGICAL_MINIMUM (-3600) */ \
		LOGICAL_MAXIMUM_2, 0x10, 0x0e, /* LOGICAL_MAXIMUM (3600) */ \
		INPUT, 0x06, /* INPUT (Data,Var,Rel) */ \
		USAGE, 0x30, /* Usage (X) */ \
		LOGICAL_MAXIMUM_2, 0xA0, 0x05, /* Logical Maximum (1440) */ \
		PHYSICAL_MAXIMUM_2, 0xCE, 0x02, /* Physical Maximum (7.18) */ \
		UNIT, 0x11, /* Unit (System: SI Linear, Length: Centimeter) */ \
		UNIT_EXPONENT, 0x0E, /* Unit Exponent (-2) */ \
		REPORT_SIZE, 0x10, /* Report Size (16) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x31, /* Usage (Y) */ \
		LOGICAL_MAXIMUM_2, 0x00, 0x0A, /* Logical Maximum (2560) */ \
		PHYSICAL_MAXIMUM_2, 0xEB, 0x04, /* Physical Maximum (12.59) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE_PAGE, 0x0d, /* USAGE_PAGE (Digitizers) */ \
		USAGE, 0x48, /* USAGE (Width) */ \
		LOGICAL_MINIMUM_2, 0xD0, 0x02, /* Logical Minimum (720) */ \
		PHYSICAL_MINIMUM_2, 0x67, 0x01, /* Physical Minimum (3.59) */ \
		LOGICAL_MAXIMUM_2, 0xD0, 0x02, /* Logical Maximum (720) */ \
		PHYSICAL_MAXIMUM_2, 0x67, 0x01, /* Physical Maximum (3.59) */ \
		INPUT, 0x03, /* INPUT (Cnst,Var,Abs) */ \
		PHYSICAL_MAXIMUM, 0x00, /* Physical Maximum: 0 */ \
		UNIT_EXPONENT, 0x00, /* Unit exponent: 0 */ \
		UNIT, 0x00, /* Unit: None */ \
	END_COLLECTION /* END_COLLECTION */ 

#define SYNAPTICS_RMI4_DIGITIZER_DIAGNOSTIC1 \
	USAGE_PAGE_1, 0x05, 0xFF, /* Usage Page (Vendor Defined 0xFF05) */ \
	USAGE, 0x01, /* Usage (0x01) */ \
	BEGIN_COLLECTION, 0x01, /* Collection (Application) */ \
		REPORT_ID, REPORTID_DIAGNOSTIC_1, /* Report ID (-13) */ \
		USAGE, 0x20, /* Usage (0x20) */ \
		LOGICAL_MINIMUM, 0x00, /* Logical Minimum (0) */ \
		PHYSICAL_MINIMUM, 0x00, /* Physical Minimum (0) */ \
		PHYSICAL_MAXIMUM, 0x00, /* Physical Maximum (0) */ \
		UNIT, 0x00, /* Unit (None) */ \
		UNIT_EXPONENT, 0x00, /* Unit Exponent (0) */ \
		REPORT_SIZE, 0x08, /* Report Size (8) */ \
		REPORT_COUNT, 0xC7, /* Report Count (-57) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		REPORT_ID, 0xF1, /* Report ID (-15) */ \
		USAGE, 0x31, /* Usage (0x31) */ \
		REPORT_COUNT, 0x3E, /* Report Count (62) */ \
		FEATURE, 0x02, /* Feature: (Data, Var, Abs) */ \
	END_COLLECTION /* End Collection */

#define SYNAPTICS_RMI4_DIGITIZER_DIAGNOSTIC2 \
	USAGE_PAGE_1, 0x05, 0xFF, /* Usage Page (Vendor Defined 0xFF05) */ \
	USAGE, 0x02, /* Usage (0x02) */ \
	BEGIN_COLLECTION, 0x01, /* Collection (Application) */ \
		REPORT_ID, REPORTID_DIAGNOSTIC_2, /* Report ID (-14) */ \
		USAGE, 0x21, /* Usage (0x21) */ \
		LOGICAL_MINIMUM, 0x00, /* Logical Minimum (0) */ \
		PHYSICAL_MINIMUM, 0x00, /* Physical Minimum (0) */ \
		PHYSICAL_MAXIMUM, 0x00, /* Physical Maximum (0) */ \
		UNIT, 0x00, /* Unit (None) */ \
		UNIT_EXPONENT, 0x00, /* Unit Exponent (0) */ \
		REPORT_SIZE, 0x08, /* Report Size (8) */ \
		REPORT_COUNT, 0x10, /* Report Count (16) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
	END_COLLECTION /* End Collection */

#define SYNAPTICS_RMI4_DIGITIZER_DIAGNOSTIC3 \
	USAGE_PAGE_1, 0x05, 0xFF, /* Usage Page (Vendor Defined 0xFF05) */ \
	USAGE, 0x03, /* Usage (0x03) */ \
	BEGIN_COLLECTION, 0x01, /* Collection (Application) */ \
		REPORT_ID, REPORTID_DIAGNOSTIC_3, /* Report ID (-12) */ \
		USAGE, 0x22, /* Usage (0x22) */ \
		LOGICAL_MINIMUM, 0x00, /* Logical Minimum (0) */ \
		PHYSICAL_MINIMUM, 0x00, /* Physical Minimum (0) */ \
		PHYSICAL_MAXIMUM, 0x00, /* Physical Maximum (0) */ \
		UNIT, 0x00, /* Unit (None) */ \
		UNIT_EXPONENT, 0x00, /* Unit Exponent (0) */ \
		REPORT_SIZE, 0x08, /* Report Size (8) */ \
		REPORT_COUNT, 0x06, /* Report Count (6) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
	END_COLLECTION /* End Collection */

#define SYNAPTICS_RMI4_DIGITIZER_DIAGNOSTIC4 \
	USAGE_PAGE_1, 0x05, 0xFF, /* Usage Page (Vendor Defined 0xFF05) */ \
	USAGE, 0x04, /* Usage (0x04) */ \
	BEGIN_COLLECTION, 0x01, /* Collection (Application) */ \
		REPORT_ID, REPORTID_DIAGNOSTIC_4, /* Report ID (-11) */ \
		USAGE, 0x41, /* Usage (0x41) */ \
		LOGICAL_MINIMUM, 0x00, /* Logical Minimum (0) */ \
		PHYSICAL_MINIMUM, 0x00, /* Physical Minimum (0) */ \
		PHYSICAL_MAXIMUM, 0x00, /* Physical Maximum (0) */ \
		UNIT, 0x00, /* Unit (None) */ \
		UNIT_EXPONENT, 0x00, /* Unit Exponent (0) */ \
		REPORT_SIZE, 0x08, /* Report Size (8) */ \
		REPORT_COUNT_2, 0xD4, 0x07, /* Report Count (2004) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		REPORT_ID, 0xF6, /* Report ID (-10) */ \
		USAGE, 0x32, /* Usage (0x32) */ \
		REPORT_COUNT, 0x03, /* Report Count (3) */ \
		FEATURE, 0x02, /* Feature: (Data, Var, Abs) */ \
	END_COLLECTION /* End Collection */

#define SYNAPTICS_RMI4_DIGITIZER_FINGER \
	USAGE_PAGE, 0x0D, /* Usage Page (Digitizer) */ \
	USAGE, 0x04, /* Usage (Touch Screen) */ \
	BEGIN_COLLECTION, 0x01, /* Collection (Application) */ \
		REPORT_ID, REPORTID_FINGER, /* Report ID (1) */ \
		USAGE, 0x22, /* Usage (Finger) */ \
		SYNAPTICS_RMI4_DIGITIZER_FINGER_CONTACT_1, /* Finger Contact (1) */ \
		USAGE, 0x00, /* Usage (Undefined) */ \
		SYNAPTICS_RMI4_DIGITIZER_FINGER_CONTACT_2, /* Finger Contact (2) */ \
		USAGE_PAGE, 0x0D, /* Usage Page (Digitizer) */ \
		USAGE, 0x54, /* Usage (Contact Count) */ \
		REPORT_SIZE, 0x08, /* Report Size (8) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		REPORT_ID, REPORTID_DEVICE_CAPS, /* Report ID (8) */ \
		USAGE, 0x55, /* Usage (Maximum Contacts) */ \
		LOGICAL_MAXIMUM, 0x02, /* Logical Maximum (2) */ \
		FEATURE, 0x02, /* Feature: (Data, Var, Abs) */ \
		USAGE_PAGE_1, 0x00, 0xff, \
		REPORT_ID, REPORTID_PTPHQA, \
		USAGE, 0xc5, \
		LOGICAL_MINIMUM, 0x00, \
		LOGICAL_MAXIMUM_2, 0xff, 0x00, \
		REPORT_SIZE, 0x08, \
		REPORT_COUNT_2, 0x00, 0x01, \
		FEATURE, 0x02, \
	END_COLLECTION /* End Collection */

#define SYNAPTICS_RMI4_DIGITIZER_REPORTMODE \
	USAGE_PAGE, 0x0D, /* Usage Page (Digitizer) */ \
	USAGE, 0x0E, /* Usage (Configuration) */ \
	BEGIN_COLLECTION, 0x01, /* Collection (Application) */ \
		REPORT_ID, REPORTID_REPORTMODE, /* Report ID (7) */ \
		USAGE, 0x22, /* Usage (Finger) */ \
		BEGIN_COLLECTION, 0x00, /* Collection (Physical) */ \
			USAGE, 0x52, /* Usage (Input Mode) */ \
			LOGICAL_MINIMUM, 0x00, /* Logical Minimum (0) */ \
			LOGICAL_MAXIMUM, 0x0A, /* Logical Maximum (10) */ \
			PHYSICAL_MINIMUM, 0x00, /* Physical Minimum (0) */ \
			PHYSICAL_MAXIMUM_2, 0xEB, 0x04, /* Physical Maximum (12.59) */ \
			UNIT, 0x11, /* Unit (System: SI Linear, Length: Centimeter) */ \
			UNIT_EXPONENT, 0x0E, /* Unit Exponent (-2) */ \
			REPORT_SIZE, 0x08, /* Report Size (8) */ \
			REPORT_COUNT, 0x01, /* Report Count (1) */ \
			FEATURE, 0x02, /* Feature: (Data, Var, Abs) */ \
			USAGE, 0x53, /* Usage (Device Identifier) */ \
			FEATURE, 0x02, /* Feature: (Data, Var, Abs) */ \
		END_COLLECTION, /* End Collection */ \
	END_COLLECTION /* End Collection */

#define SYNAPTICS_RMI4_DIGITIZER_KEYPAD \
	USAGE_PAGE, 0x01, /* Usage Page (Generic Desktop Ctrls) */ \
	USAGE, 0xEE, /* Usage (0xEE) */ \
	BEGIN_COLLECTION, 0x01, /* Collection (Application) */ \
		REPORT_ID, REPORTID_KEYPAD, /* Report ID (9) */ \
		USAGE_PAGE, 0x07, /* Usage Page (Kbrd/Keypad) */ \
		USAGE, 0x3B, /* Usage (Keyboard F2) */ \
		LOGICAL_MINIMUM, 0x00, /* Logical Minimum (0) */ \
		LOGICAL_MAXIMUM, 0x01, /* Logical Maximum (1) */ \
		PHYSICAL_MINIMUM, 0x00, /* Physical Minimum (0) */ \
		PHYSICAL_MAXIMUM, 0x01, /* Physical Maximum (1) */ \
		UNIT, 0x00, /* Unit (None) */ \
		UNIT_EXPONENT, 0x00, /* Unit Exponent (0) */ \
		REPORT_SIZE, 0x01, /* Report Size (1) */ \
		REPORT_COUNT, 0x01, /* Report Count (1) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x3C, /* Usage (Keyboard F3) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x29, /* Usage (Keyboard ESCAPE) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		USAGE, 0x68, /* Usage (Keyboard F13) */ \
		INPUT, 0x02, /* Input: (Data, Var, Abs) */ \
		REPORT_COUNT, 0x1C, /* Report Count (28) */ \
		INPUT, 0x03, /* Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */ \
	END_COLLECTION /* End Collection */

#define SYNAPTICS_RMI4_DIGITIZER_STYLUS \
	USAGE_PAGE, 0x0D, /* Usage Page (Digitizer) */ \
	USAGE, 0x02, /* Usage (Pen) */ \
	BEGIN_COLLECTION, 0x01, /* Collection (Application) */ \
		REPORT_ID, REPORTID_STYLUS, /* Report ID (11) */ \
		USAGE, 0x20, /* Usage (Stylus) */ \
		SYNAPTICS_RMI4_DIGITIZER_STYLUS_CONTACT_1, /* Stylus (1) */ \
		USAGE_PAGE_1, 0x00, 0xff, \
		REPORT_ID, REPORTID_PENHQA, \
		USAGE, 0xc5, \
		LOGICAL_MINIMUM, 0x00, \
		LOGICAL_MAXIMUM_2, 0xff, 0x00, \
		REPORT_SIZE, 0x08, \
		REPORT_COUNT_2, 0x00, 0x01, \
		FEATURE, 0x02, \
	END_COLLECTION /* End Collection */

#define SYNAPTICS_RMI4_DIGITIZER_RADIAL_CONTROLLER \
	USAGE_PAGE, 0x01, /* USAGE_PAGE (Generic Desktop) */ \
	USAGE, 0x0e, /* USAGE (System Multi-Axis Controller) */ \
	BEGIN_COLLECTION, 0x01, /* COLLECTION (Application) */ \
		REPORT_ID, REPORTID_RADIALCONTROLLER, /* REPORT_ID (Radial Controller) */ \
		USAGE_PAGE, 0x0d, /* USAGE_PAGE (Digitizers) */ \
		USAGE, 0x21, /* USAGE (Puck) */ \
		SYNAPTICS_RMI4_DIGITIZER_PUCK_CONTACT_1, /* Puck (1) */ \
	END_COLLECTION /* END_COLLECTION */

#define SYNAPTICS_RMI4_DIGITIZER_WAKE_BUTTON \
	USAGE_PAGE, 0x01, /* Generic Desktop */ \
	USAGE, 0x80, /* System Control */ \
	BEGIN_COLLECTION, 0x01, /* Application */ \
		REPORT_ID, REPORTID_WAKEBUTTON, \
		USAGE, 0x81, /* System power down */\
		USAGE, 0x83, /* System wake up */\
		USAGE, 0x84, /* System power */ \
		LOGICAL_MINIMUM, 0x00, \
		LOGICAL_MAXIMUM, 0x01, \
		REPORT_SIZE, 0x01, \
		REPORT_COUNT, 0x03, \
		INPUT, 0x02, /* (Data,Var,Abs) */ \
		REPORT_COUNT, 0x01, \
		REPORT_SIZE, 0x05, \
		INPUT, 0x03, /* (Cnst,Var,Abs) */ \
	END_COLLECTION

#define DEFAULT_PTP_HQA_BLOB \
	0xfc, 0x28, 0xfe, 0x84, 0x40, 0xcb, 0x9a, 0x87, \
	0x0d, 0xbe, 0x57, 0x3c, 0xb6, 0x70, 0x09, 0x88, \
	0x07, 0x97, 0x2d, 0x2b, 0xe3, 0x38, 0x34, 0xb6, \
	0x6c, 0xed, 0xb0, 0xf7, 0xe5, 0x9c, 0xf6, 0xc2, \
	0x2e, 0x84, 0x1b, 0xe8, 0xb4, 0x51, 0x78, 0x43, \
	0x1f, 0x28, 0x4b, 0x7c, 0x2d, 0x53, 0xaf, 0xfc, \
	0x47, 0x70, 0x1b, 0x59, 0x6f, 0x74, 0x43, 0xc4, \
	0xf3, 0x47, 0x18, 0x53, 0x1a, 0xa2, 0xa1, 0x71, \
	0xc7, 0x95, 0x0e, 0x31, 0x55, 0x21, 0xd3, 0xb5, \
	0x1e, 0xe9, 0x0c, 0xba, 0xec, 0xb8, 0x89, 0x19, \
	0x3e, 0xb3, 0xaf, 0x75, 0x81, 0x9d, 0x53, 0xb9, \
	0x41, 0x57, 0xf4, 0x6d, 0x39, 0x25, 0x29, 0x7c, \
	0x87, 0xd9, 0xb4, 0x98, 0x45, 0x7d, 0xa7, 0x26, \
	0x9c, 0x65, 0x3b, 0x85, 0x68, 0x89, 0xd7, 0x3b, \
	0xbd, 0xff, 0x14, 0x67, 0xf2, 0x2b, 0xf0, 0x2a, \
	0x41, 0x54, 0xf0, 0xfd, 0x2c, 0x66, 0x7c, 0xf8, \
	0xc0, 0x8f, 0x33, 0x13, 0x03, 0xf1, 0xd3, 0xc1, \
	0x0b, 0x89, 0xd9, 0x1b, 0x62, 0xcd, 0x51, 0xb7, \
	0x80, 0xb8, 0xaf, 0x3a, 0x10, 0xc1, 0x8a, 0x5b, \
	0xe8, 0x8a, 0x56, 0xf0, 0x8c, 0xaa, 0xfa, 0x35, \
	0xe9, 0x42, 0xc4, 0xd8, 0x55, 0xc3, 0x38, 0xcc, \
	0x2b, 0x53, 0x5c, 0x69, 0x52, 0xd5, 0xc8, 0x73, \
	0x02, 0x38, 0x7c, 0x73, 0xb6, 0x41, 0xe7, 0xff, \
	0x05, 0xd8, 0x2b, 0x79, 0x9a, 0xe2, 0x34, 0x60, \
	0x8f, 0xa3, 0x32, 0x1f, 0x09, 0x78, 0x62, 0xbc, \
	0x80, 0xe3, 0x0f, 0xbd, 0x65, 0x20, 0x08, 0x13, \
	0xc1, 0xe2, 0xee, 0x53, 0x2d, 0x86, 0x7e, 0xa7, \
	0x5a, 0xc5, 0xd3, 0x7d, 0x98, 0xbe, 0x31, 0x48, \
	0x1f, 0xfb, 0xda, 0xaf, 0xa2, 0xa8, 0x6a, 0x89, \
	0xd6, 0xbf, 0xf2, 0xd3, 0x32, 0x2a, 0x9a, 0xe4, \
	0xcf, 0x17, 0xb7, 0xb8, 0xf4, 0xe1, 0x33, 0x08, \
	0x24, 0x8b, 0xc4, 0x43, 0xa5, 0xe5, 0x24, 0xc2

// REPORTID_DEVICE_CAPS
typedef struct _PTP_DEVICE_CAPS_FEATURE_REPORT {
	UCHAR ReportID;
	UCHAR MaximumContactPoints;
} PTP_DEVICE_CAPS_FEATURE_REPORT, *PPTP_DEVICE_CAPS_FEATURE_REPORT;

// REPORTID_REPORTMODE
typedef struct _PTP_DEVICE_INPUT_MODE_REPORT {
	UCHAR ReportID;
	UCHAR Mode;
	UCHAR DeviceID;
} PTP_DEVICE_INPUT_MODE_REPORT, *PPTP_DEVICE_INPUT_MODE_REPORT;

// REPORTID_PTPHQA REPORTID_PENHQA
typedef struct _PTP_DEVICE_HQA_CERTIFICATION_REPORT {
	UCHAR ReportID;
	UCHAR CertificationBlob[256];
} PTP_DEVICE_HQA_CERTIFICATION_REPORT, * PPTP_DEVICE_HQA_CERTIFICATION_REPORT;

// REPORTID_FINGER
#pragma pack(push)
#pragma pack(1)
typedef struct _PTP_DEVICE_FINGER {
	UCHAR		TipSwitch  : 1;
	UCHAR		InRange    : 1;
	UCHAR		Confidence : 1;
	UCHAR		Padding    : 5;
	UCHAR		ContactID;
	USHORT		X;
	USHORT		Y;
} PTP_DEVICE_FINGER, * PPTP_DEVICE_FINGER;
#pragma pack(pop)
typedef struct _PTP_DEVICE_FINGER_REPORT {
	UCHAR             ReportID;
	PTP_DEVICE_FINGER Contacts[2];
	//USHORT            ScanTime;
	UCHAR             ContactCount;
} PTP_DEVICE_FINGER_REPORT, * PPTP_DEVICE_FINGER_REPORT;

// REPORTID_KEYPAD
typedef struct _PTP_DEVICE_KEYPAD_REPORT {
	UCHAR ReportID;
	UCHAR F2        : 1;
	UCHAR F3        : 1;
	UCHAR ESCAPE    : 1;
	UCHAR F13       : 1;
	UCHAR Padding0  : 4;
	UCHAR Padding1;
	UCHAR Padding2;
	UCHAR Padding3;
} PTP_DEVICE_KEYPAD_REPORT, * PPTP_DEVICE_KEYPAD_REPORT;

// REPORTID_STYLUS
#pragma pack(push)
#pragma pack(1)
typedef struct _PTP_DEVICE_STYLUS {
	UCHAR  TipSwitch    : 1;
	UCHAR  BarrelSwitch : 1;
	UCHAR  Invert       : 1;
	UCHAR  Eraser       : 1;
	UCHAR  InRange      : 1;
	UCHAR  Padding      : 3;
	USHORT X;
	USHORT Y;
	UCHAR  TipPressure;
	UCHAR  XTilt;
	UCHAR  YTilt;
} PTP_DEVICE_STYLUS, * PPTP_DEVICE_STYLUS;
#pragma pack(pop)
typedef struct _PTP_DEVICE_STYLUS_REPORT {
	UCHAR             ReportID;
	PTP_DEVICE_STYLUS Contacts[1];
	//USHORT            ScanTime;
} PTP_DEVICE_STYLUS_REPORT, * PPTP_DEVICE_STYLUS_REPORT;

// REPORTID_RADIALCONTROLLER
#pragma pack(push)
#pragma pack(1)
typedef struct _PTP_DEVICE_PUCK {
	UCHAR  Button : 1;
	USHORT Dial   : 15;
	USHORT X;
	USHORT Y;
	USHORT wX;
	USHORT wY;
} PTP_DEVICE_PUCK, * PPTP_DEVICE_PUCK;
#pragma pack(pop)
typedef struct _PTP_DEVICE_PUCK_REPORT {
	UCHAR            ReportID;
	PTP_DEVICE_PUCK  Contacts[1];
	//USHORT           ScanTime;
} PTP_DEVICE_PUCK_REPORT, * PPTP_DEVICE_PUCK_REPORT;

// Wake Button
typedef struct _PTP_DEVICE_WAKE_BUTTON_REPORT {
	UCHAR ReportID;
	BYTE  SystemPowerDown : 1;
	BYTE  SystemWakeUp    : 1;
	BYTE  SystemPower     : 1;
	BYTE  Padding         : 5;
} PTP_DEVICE_WAKE_BUTTON_REPORT, * PPTP_DEVICE_WAKE_BUTTON_REPORT;

// General Type
typedef union _DEV_REPORT
{
	PTP_DEVICE_STYLUS_REPORT PenReport;
	PTP_DEVICE_FINGER_REPORT PtpReport;
	PTP_DEVICE_KEYPAD_REPORT KeyReport;
	PTP_DEVICE_PUCK_REPORT  PuckReport;
	PTP_DEVICE_WAKE_BUTTON_REPORT WakeReport;
} DEV_REPORT, * PDEV_REPORT;