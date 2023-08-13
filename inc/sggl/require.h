#ifndef __SG_GL_REQUIRE__
#define __SG_GL_REQUIRE__


#include "sggl/platform.h"



#ifndef SG_GL_HOST
#warning "sggl: unknown host, some functions will be not callable."
#endif

#if !defined(SG_GL_CL_MSVC) && !defined(SG_GL_CL_GCC) && !defined(SG_GL_CL_CLANG)
#error "sggl: unsupported compiler, only support msvc, gcc and clang."
#endif

#ifndef SG_GL_LANG_CPP
#error "sggl: unsupported language, only for cplusplus."
#elif SG_GL_LANG_CPP_STD < 17
#error "sggl: too low std, only support cpp17 and above."
#endif

#if !defined(SG_GL_CPU_X86) && !defined(SG_GL_CPU_X64) && !defined(SG_GL_CPU_ARM64) && !defined(SG_GL_CPU_ARM32) && !defined(SG_GL_CPU_THUMB)
#error "sggl: unsupported cpu architecture, only support x86, x64, arm64, arm32, thumb."
#endif



#endif //!__SG_GL_REQUIRE__