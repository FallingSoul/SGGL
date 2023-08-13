#ifndef __SG_GL_PLATFORM_CPU__
#define __SG_GL_PLATFORM_CPU__

#include "sggl/platform/compiler.h"

#if defined(SG_GL_CL_MSVC)
#if defined(_M_IX86)
#define SG_GL_CPU_X86 1
#elif defined(_M_X64) || defined(_M_AMD64)
#define SG_GL_CPU_X64 1
#elif defined(_M_ARM64)
#define SG_GL_CPU_ARM64 1
#elif defined(_M_ARM)
#define SG_GL_CPU_ARM32 1
#elif defined(_M_THUMB)
#define SG_GL_CPU_THUMB 1
#endif
#endif

#if defined(SG_GL_CL_GCC) || defined(SG_GL_CL_CLANG)
#if defined(__i386__)
#define SG_GL_CPU_X86 1
#elif defined(__x86_64__)
#define SG_GL_CPU_X64 1
#elif defined(__aarch64__)
#define SG_GL_CPU_ARM64 1
#elif defined(__arm__)
#define SG_GL_CPU_ARM32 1
#elif defined(__thumb__)
#define SG_GL_CPU_THUMB 1
#endif
#endif


#endif //!__SG_GL_PLATFORM_CPU__