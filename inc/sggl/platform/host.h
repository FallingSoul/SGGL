#ifndef __SG_GL_PLATFORM_HOST__
#define __SG_GL_PLATFORM_HOST__

#if __STDC_HOSTED__

#define SG_GL_HOST 1
// OS
#if defined(_WIN64)
#define SG_GL_HOST_WIN64 1
#elif defined(_WIN32)
#define SG_GL_HOST_WINDOWS 1
#endif

#if defined(__linux__)
#define SG_GL_HOST_LINUX 1
#endif

#if defined(__unix__)
#define SG_GL_HOST_UNIX 1
#endif

#if defined(__ADNROID__)
#define SG_GL_HOST_ANDROID 1
#endif

#if defined(__APPLE__) || defined(__MACH__)
#define SG_GL_HOST_APPLE 1

#include <TargetConditionals.h>

#if defined(TARGET_OS_EMBEDDED)
#define SG_GL_HOST_APPLE_EMBEDDED 1
#endif

#if defined(TARGET_IPHONE_SIMULATOR)
#define SG_GL_HOST_APPLE_IPHONE_SIMULATOR 1
#endif

#if defined(TARGET_OS_IPHONE)
#define SG_GL_HOST_APPLE_IPHONE 1
#endif

#ifdef defined(TARGET_OS_MAC)
#define SG_GL_HOST_APPLE_MAC 1
#endif

#endif

#if defined(_POSIX_VERSION)
#define SG_GL_HOST_CYGWIN 1
#endif

#if defined(__sun)
#define SG_GL_HOST_SOLARIS 1
#endif

#if defined(__hpux)
#define SG_GL_HOST_HPUX 1
#endif

#if defined(BSD)
#define SG_GL_HOST_BSD 1

#if defined(__DragonFly__)
#define SG_GL_HOST_BSD_DRONGFLY 1
#endif

#if defined(__FreeBSD__)
#define SG_GL_HOST_BSD_FREE 1
#endif

#if defined(__NetBSD__)
#define SG_GL_HOST_BSD_NET 1
#endif

#if defined(__OpenBSD__)
#define SG_GL_HOST_BSD_OPEN 1
#endif

#endif

#endif

#endif //!__SG_GL_PLATFORM_HOST__