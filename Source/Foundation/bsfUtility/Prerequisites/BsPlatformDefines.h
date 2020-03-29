//************************************ bs::framework - Copyright 2018 Marko Pintera **************************************//
//*********** Licensed under the MIT license. See LICENSE.md for full terms. This notice is not to be removed. ***********//
#pragma once

#define BS_PLATFORM_WIN32 1

#if defined(__WIN32__) || defined(_WIN32)
#   define BS_PLATFORM BS_PLATFORM_WIN32
#endif

// dll import
#if BS_PLATFORM == BS_PLATFORM_WIN32
#   if defined(BS_STATIC_LIB)
#       define BS_UTILITY_EXPORT
#   else
#       if defined(BS_UTILITY_EXPORTS)
#           define BS_UTILITY_EXPORT __declspec(dllexport)
#       else
#           define BS_UTILITY_EXPORT __declspec(dllimport)
#       endif
#   endif()
#endif