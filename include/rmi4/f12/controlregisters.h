#pragma once

#include <wdm.h>
#include <wdf.h>
#include "controller.h"
#include "resolutions.h"
#include "bitops.h"
#include "hweight.h"

// Ignore warning C4152: nonstandard extension, function/data pointer conversion in expression
#pragma warning (disable : 4152)

// Ignore warning C4201: nonstandard extension used : nameless struct/union
#pragma warning (disable : 4201)

// Ignore warning C4201: nonstandard extension used : bit field types other than in
#pragma warning (disable : 4214)

// Ignore warning C4324: 'xxx' : structure was padded due to __declspec(align())
#pragma warning (disable : 4324)

typedef enum _RMI4_F12_REPORTING_FLAGS
{
	RMI4_F12_REPORTING_CONTINUOUS_MODE     = 0,
	RMI4_F12_REPORTING_REDUCED_MODE        = 1,
	RMI4_F12_REPORTING_WAKEUP_GESTURE_MODE = 2,
} RMI4_F12_REPORTING_FLAGS;

typedef struct _RMI4_F12_QUERY_5_REGISTER {
	union {
		BYTE Data[7];
		struct {
			BYTE Size;
#pragma pack(push)
#pragma pack(1)
			struct {
				BYTE ctrl0_is_present : 1;
				BYTE ctrl1_is_present : 1;
				BYTE ctrl2_is_present : 1;
				BYTE ctrl3_is_present : 1;
				BYTE ctrl4_is_present : 1;
				BYTE ctrl5_is_present : 1;
				BYTE ctrl6_is_present : 1;
				BYTE ctrl7_is_present : 1;
			};
#pragma pack(pop)

#pragma pack(push)
#pragma pack(1)
			struct {
				BYTE ctrl8_is_present : 1;
				BYTE ctrl9_is_present : 1;
				BYTE ctrl10_is_present : 1;
				BYTE ctrl11_is_present : 1;
				BYTE ctrl12_is_present : 1;
				BYTE ctrl13_is_present : 1;
				BYTE ctrl14_is_present : 1;
				BYTE ctrl15_is_present : 1;
			};
#pragma pack(pop)

#pragma pack(push)
#pragma pack(1)
			struct {
				BYTE ctrl16_is_present : 1;
				BYTE ctrl17_is_present : 1;
				BYTE ctrl18_is_present : 1;
				BYTE ctrl19_is_present : 1;
				BYTE ctrl20_is_present : 1;
				BYTE ctrl21_is_present : 1;
				BYTE ctrl22_is_present : 1;
				BYTE ctrl23_is_present : 1;
			};
#pragma pack(pop)

#pragma pack(push)
#pragma pack(1)
			struct {
				BYTE ctrl24_is_present : 1;
				BYTE ctrl25_is_present : 1;
				BYTE ctrl26_is_present : 1;
				BYTE ctrl27_is_present : 1;
				BYTE ctrl28_is_present : 1;
				BYTE ctrl29_is_present : 1;
				BYTE ctrl30_is_present : 1;
				BYTE ctrl31_is_present : 1;
			};
#pragma pack(pop)

#pragma pack(push)
#pragma pack(1)
			struct {
				BYTE ctrl32_is_present : 1;
				BYTE ctrl33_is_present : 1;
				BYTE ctrl34_is_present : 1;
				BYTE ctrl35_is_present : 1;
				BYTE ctrl36_is_present : 1;
				BYTE ctrl37_is_present : 1;
				BYTE ctrl38_is_present : 1;
				BYTE ctrl39_is_present : 1;
			};
#pragma pack(pop)

#pragma pack(push)
#pragma pack(1)
			struct {
				BYTE ctrl40_is_present : 1;
				BYTE ctrl41_is_present : 1;
				BYTE ctrl42_is_present : 1;
				BYTE ctrl43_is_present : 1;
				BYTE ctrl44_is_present : 1;
				BYTE ctrl45_is_present : 1;
				BYTE ctrl46_is_present : 1;
				BYTE ctrl47_is_present : 1;
			};
#pragma pack(pop)
		};
	};
} RMI4_F12_QUERY_5_REGISTER, * PRMI4_F12_QUERY_5_REGISTER;

typedef struct _RMI4_F12_QUERY_8_REGISTER {
	union {
		BYTE Data[3];
		struct {
			BYTE Size;
#pragma pack(push)
#pragma pack(1)
			struct {
				BYTE data0_is_present : 1;
				BYTE data1_is_present : 1;
				BYTE data2_is_present : 1;
				BYTE data3_is_present : 1;
				BYTE data4_is_present : 1;
				BYTE data5_is_present : 1;
				BYTE data6_is_present : 1;
				BYTE data7_is_present : 1;
			};
#pragma pack(pop)

#pragma pack(push)
#pragma pack(1)
			struct {
				BYTE data8_is_present : 1;
				BYTE data9_is_present : 1;
				BYTE data10_is_present : 1;
				BYTE data11_is_present : 1;
				BYTE data12_is_present : 1;
				BYTE data13_is_present : 1;
				BYTE data14_is_present : 1;
				BYTE data15_is_present : 1;
			};
#pragma pack(pop)
		};
	};
} RMI4_F12_QUERY_8_REGISTER, * PRMI4_F12_QUERY_8_REGISTER;

typedef struct _RMI4_F12_CONTROL_20_REGISTER
{
	union {
		BYTE Data[3];
		struct
		{
			BYTE SupressXCoordinate;
			BYTE SuppressYCoordinate;
			RMI4_F12_REPORTING_FLAGS ReportingFlags;
		};
	};
} RMI4_F12_CONTROL_20_REGISTER, * PRMI4_F12_CONTROL_20_REGISTER;

typedef struct _RMI4_F12_CONTROL_23_REGISTER
{
	union {
		BYTE Data[5];
		struct
		{
			struct
			{
				BYTE FingerReportingEnabled : 1;
				BYTE ActiveStylusReportingEnabled : 1;
				BYTE PalmReportingEnabled : 1;
				BYTE UnclassifiedObjectReportingEnabled : 1;
				BYTE HoveringFingerReportingEnabled : 1;
				BYTE GlovedFingerReportingEnabled : 1;
				BYTE NarrowObjectReportingEnabled : 1;
				BYTE HandEdgeReportingEnabled : 1;
			};

			BYTE ReportedObjectCount;

			struct
			{
				BYTE Padding1 : 1;
				BYTE ReportActiveStylusAsFinger : 1;
				BYTE ReportPalmAsFinger : 1;
				BYTE ReportUnclassifiedObjectAsFinger : 1;
				BYTE ReportHoveringFingerAsFinger : 1;
				BYTE ReportGlovedFingerAsFinger : 1;
				BYTE ReportNarrowObjectSwipeAsFinger : 1;
				BYTE ReportHandEdgeAsFinger : 1;
			};

			struct
			{
				BYTE CoverReportingEnabled : 1;
				BYTE StylusReportingEnabled : 1;
				BYTE EraserReportingEnabled : 1;
				BYTE SmallObjectReportingEnabled : 1;
				BYTE Padding2 : 4;
			};

			struct
			{
				BYTE ReportCoverAsFinger : 1;
				BYTE ReportStylusAsFinger : 1;
				BYTE ReportEraserAsFinger : 1;
				BYTE ReportSmallObjectAsFinger : 1;
				BYTE Padding3 : 4;
			};
		};
	};
} RMI4_F12_CONTROL_23_REGISTER, * PRMI4_F12_CONTROL_23_REGISTER;