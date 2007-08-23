/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __ASSERT_H_
#define __ASSERT_H_

#include <_mingw.h>
#ifdef __cplusplus
#include <stdlib.h>
#endif

#undef assert

#ifdef NDEBUG
#define assert(_Expression) ((void)0)
#else

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
_CRTIMP __declspec(noreturn) void __cdecl exit(int _Code);
_CRTIMP __declspec(noreturn) void __cdecl _exit(int _Code);
#if !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
void __cdecl __declspec(noreturn) _Exit(int); /* Declare to get noreturn attribute.  */
__CRT_INLINE void __cdecl _Exit(int status)
{  _exit(status); }
#endif
_CRTIMP void __cdecl __declspec(noreturn) abort(void);
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern void __cdecl _wassert(const wchar_t *_Message,const wchar_t *_File,unsigned _Line);

#ifdef __cplusplus
}
#endif

#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))


#endif

#endif
