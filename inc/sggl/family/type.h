#ifndef __SG_GL_FAMILY_TYPE__
#define __SG_GL_FAMILY_TYPE__

#include <stdint.h>
#include "sggl/platform.h"

namespace sggl
{
    typedef wchar_t sgwchar;
    typedef char sgchar;
    typedef signed char sgschar;
    typedef unsigned char sguchar;

    typedef short sgshort;
    typedef unsigned short sgushort;
    
    typedef int sgint;
    typedef unsigned int sguint;
    
    typedef long sglong;
    typedef unsigned long sgulong;

    typedef long long sgllong;
    typedef unsigned long long sgullong;

    typedef __int8 sgint8;
    typedef unsigned __int8 sguint8;

    typedef __int16 sgint16;
    typedef unsigned __int16 sguint16;
    
    typedef __int32 sgint32;
    typedef unsigned __int32 sguint32;
    
    typedef __int64 sgint64;
    typedef unsigned __int64 sguint64;

    typedef float sgfloat;
    typedef double sgdouble;
    typedef long double sgldouble;

    typedef bool sgbool,sgboolean;
    typedef void sgvoid;
    typedef void * sgptr;
    typedef decltype(nullptr) sgnullptr;

    typedef char sgbyte;
    typedef unsigned char sgubyte;

#ifdef SG_GL_HOST_WIN64
    typedef sgint64 sgintptr;
    typedef sguint64 sguintptr;
    typedef sguint64 sgsize;
#elif defined(SG_GL_HOST_WINDOWS)
    typedef sgint32 sgintptr;
    typedef sguint32 sguintptr;
    typedef sguint32 sgsize;
#else
#if defined(SG_GL_CPU_X86) || defined(SG_GL_CPU_ARM32) || defined(SG_GL_CPU_THUMB)
    typedef sgint32 sgintptr;
    typedef sguint32 sguintptr;
    typedef sguint32 sgsize;
#elif defined(SG_GL_CPU_X64) || defined(SG_GL_CPU_ARM64)
    typedef sgint64 sgintptr;
    typedef sguint64 sguintptr;
    typedef sguint64 sgsize;
#endif
#endif

}


#endif //!__SG_GL_FAMILY_TYPE__