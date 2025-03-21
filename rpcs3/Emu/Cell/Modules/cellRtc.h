#pragma once

#include "Emu/Memory/vm_ptr.h"
#include "Emu/Cell/ErrorCodes.h"

// Return Codes
enum CellRtcError
{
	CELL_RTC_ERROR_NOT_INITIALIZED     = 0x80010601,
	CELL_RTC_ERROR_INVALID_POINTER     = 0x80010602,
	CELL_RTC_ERROR_INVALID_VALUE       = 0x80010603,
	CELL_RTC_ERROR_INVALID_ARG         = 0x80010604,
	CELL_RTC_ERROR_NOT_SUPPORTED       = 0x80010605,
	CELL_RTC_ERROR_NO_CLOCK            = 0x80010606,
	CELL_RTC_ERROR_BAD_PARSE           = 0x80010607,
	CELL_RTC_ERROR_INVALID_YEAR        = 0x80010621,
	CELL_RTC_ERROR_INVALID_MONTH       = 0x80010622,
	CELL_RTC_ERROR_INVALID_DAY         = 0x80010623,
	CELL_RTC_ERROR_INVALID_HOUR        = 0x80010624,
	CELL_RTC_ERROR_INVALID_MINUTE      = 0x80010625,
	CELL_RTC_ERROR_INVALID_SECOND      = 0x80010626,
	CELL_RTC_ERROR_INVALID_MICROSECOND = 0x80010627,
};

struct CellRtcTick
{
	be_t<u64> tick;
};

struct CellRtcDateTime
{
	be_t<u16> year;        // 1 to 9999
	be_t<u16> month;       // 1 to 12
	be_t<u16> day;         // 1 to 31
	be_t<u16> hour;        // 0 to 23
	be_t<u16> minute;      // 0 to 59
	be_t<u16> second;      // 0 to 59
	be_t<u32> microsecond; // 0 to 999999
};

error_code cellRtcTickAddYears(vm::ptr<CellRtcTick> pTick0, vm::cptr<CellRtcTick> pTick1, s32 iAdd);
error_code cellRtcTickAddMonths(vm::ptr<CellRtcTick> pTick0, vm::cptr<CellRtcTick> pTick1, s32 lAdd);
error_code cellRtcTickAddDays(vm::ptr<CellRtcTick> pTick0, vm::cptr<CellRtcTick> pTick1, s32 lAdd);
error_code cellRtcTickAddHours(vm::ptr<CellRtcTick> pTick0, vm::cptr<CellRtcTick> pTick1, s32 lAdd);
error_code cellRtcTickAddMinutes(vm::ptr<CellRtcTick> pTick0, vm::cptr<CellRtcTick> pTick1, s64 lAdd);
error_code cellRtcTickAddSeconds(vm::ptr<CellRtcTick> pTick0, vm::cptr<CellRtcTick> pTick1, s64 lAdd);

error_code cellRtcSetTick(vm::ptr<CellRtcDateTime> pTime, vm::cptr<CellRtcTick> pTick);
u32 cellRtcGetTickResolution();
error_code cellRtcCheckValid(vm::cptr<CellRtcDateTime> pTime);
error_code cellRtcGetDayOfWeek(s32 year, s32 month, s32 day);
error_code cellRtcGetTick(vm::cptr<CellRtcDateTime> pTime, vm::ptr<CellRtcTick> pTick);
error_code cellRtcGetCurrentTick(vm::ptr<CellRtcTick> pTick);

CellRtcDateTime tick_to_date_time(u64 tick);
