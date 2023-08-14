#ifndef __SG_GL_CONFIG__
#define __SG_GL_CONFIG__

#define SG_GL_VERSION_MAJOR 0
#define SG_GL_VERSION_MINOR 1
#define SG_GL_VERSION_REVISION 0


#define SG_GL_VERSION_STRING_EX(major,minor,revsion) #major "." #minor "." #revsion
#define SG_GL_VERSION_STRING(major,minor,revsion) SG_GL_VERSION_STRING_EX(major,minor,revsion)
#define SG_GL_VERSION SG_GL_VERSION_STRING(SG_GL_VERSION_MAJOR,SG_GL_VERSION_MINOR,SG_GL_VERSION_REVISION)

#define SG_GL_STDCALL __stdcall
#define SG_GL_CDECL __cdecl
#define SG_GL_FASTCALL __fastcall




#define SG_GL_API_ATTR
#define SG_GL_API

// for debugging
#define SG_GL_DEBUG 1


#endif //!__SG_GL_CONFIG__