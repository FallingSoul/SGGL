#ifndef __SG_GL_PLATFORM_COMPILER__
#define __SG_GL_PLATFORM_COMPILER__

// Compiler
#if defined(_MSC_VER)
#define SG_GL_CL_MSVC 1

// for "safe function"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#if _MSC_VER == 1200
#define SG_GL_CL_MAJOR 6
#define SG_GL_CL_MINOR 0
#elif _MSC_VER == 1300
#define SG_GL_CL_MAJOR 7
#define SG_GL_CL_MINOR 0
#elif _MSC_VER == 1310
#define SG_GL_CL_MAJOR 7
#define SG_GL_CL_MINOR 1
#elif _MSC_VER == 1400
#define SG_GL_CL_MAJOR 8
#define SG_GL_CL_MINOR 0
#elif _MSC_VER == 1500
#define SG_GL_CL_MAJOR 9
#define SG_GL_CL_MINOR 0
#elif _MSC_VER == 1600
#define SG_GL_CL_MAJOR 10
#define SG_GL_CL_MINOR 0
#elif _MSC_VER == 1700
#define SG_GL_CL_MAJOR 11
#define SG_GL_CL_MINOR 0
#elif _MSC_VER == 1800
#define SG_GL_CL_MAJOR 12
#define SG_GL_CL_MINOR 0
#elif _MSC_VER == 1900
#define SG_GL_CL_MAJOR 14
#define SG_GL_CL_MINOR 0
#elif _MSC_VER == 1910
#define SG_GL_CL_MAJOR 15
#define SG_GL_CL_MINOR 0
#elif _MSC_VER == 1911
#define SG_GL_CL_MAJOR 15
#define SG_GL_CL_MINOR 3
#elif _MSC_VER == 1912
#define SG_GL_CL_MAJOR 15
#define SG_GL_CL_MINOR 5
#elif _MSC_VER == 1913
#define SG_GL_CL_MAJOR 15
#define SG_GL_CL_MINOR 6
#elif _MSC_VER == 1914
#define SG_GL_CL_MAJOR 15
#define SG_GL_CL_MINOR 7
#elif _MSC_VER == 1915
#define SG_GL_CL_MAJOR 15
#define SG_GL_CL_MINOR 8
#elif _MSC_VER == 1916
#define SG_GL_CL_MAJOR 15
#define SG_GL_CL_MINOR 9
#elif _MSC_VER == 1920
#define SG_GL_CL_MAJOR 16
#define SG_GL_CL_MINOR 0
#elif _MSC_VER == 1921
#define SG_GL_CL_MAJOR 16
#define SG_GL_CL_MINOR 1
#elif _MSC_VER == 1922
#define SG_GL_CL_MAJOR 16
#define SG_GL_CL_MINOR 2
#elif _MSC_VER == 1923
#define SG_GL_CL_MAJOR 16
#define SG_GL_CL_MINOR 3
#elif _MSC_VER == 1924
#define SG_GL_CL_MAJOR 16
#define SG_GL_CL_MINOR 4
#elif _MSC_VER == 1925
#define SG_GL_CL_MAJOR 16
#define SG_GL_CL_MINOR 5
#elif _MSC_VER == 1926
#define SG_GL_CL_MAJOR 16
#define SG_GL_CL_MINOR 6
#elif _MSC_VER == 1927
#define SG_GL_CL_MAJOR 16
#define SG_GL_CL_MINOR 7
#elif _MSC_VER == 1928
#define SG_GL_CL_MAJOR 16
#define SG_GL_CL_MINOR 8
#elif _MSC_VER == 1929
#define SG_GL_CL_MAJOR 16
#define SG_GL_CL_MINOR 10
#elif _MSC_VER == 1930
#define SG_GL_CL_MAJOR 17
#define SG_GL_CL_MINOR 0
#elif _MSC_VER == 1931
#define SG_GL_CL_MAJOR 17
#define SG_GL_CL_MINOR 1
#elif _MSC_VER == 1932
#define SG_GL_CL_MAJOR 17
#define SG_GL_CL_MINOR 2
#endif

#endif

#if defined(__GNUC__)
#define SG_GL_CL_GCC 1

#define SG_GL_CL_MAJOR __GNUC__
#define SG_GL_CL_MINOR __GNUC_MINOR__

#if __GNUC__ >= 3
#define SG_GL_CL_REVISION __GNUC_PATCHLEVEL__
#endif

#endif

#if defined(__clang__)
#define SG_GL_CL_CLANG 1

#define SG_GL_CL_MAJOR __clang_major__
#define SG_GL_CL_MINOR __clang_minor__
#define SG_GL_CL_REVISION __clang_patchlevel__

#endif

#if !defined(SG_GL_CL_REVISION)
#define SG_GL_CL_REVISION 0
#endif

#endif //!__SG_GL_PLATFORM_COMPILER__