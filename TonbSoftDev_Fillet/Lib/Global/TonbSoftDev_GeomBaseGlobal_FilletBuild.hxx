#pragma once

#ifndef _TonbSoftDev_GeomBaseGlobal_FilletBuild_Header
#define _TonbSoftDev_GeomBaseGlobal_FilletBuild_Header

# if defined(TonbSoftDev_Fillet_LIB)

// Building Library

#  define TonbSoftDev_Fillet_EXPORT __declspec(dllexport)
# else
// Reading Library
#  define TonbSoftDev_Fillet_EXPORT __declspec(dllimport)
# endif

#endif // !_TonbSoftDev_GeomBaseGlobal_FilletBuild_Header