#ifndef __SG_GL_OPENGL_BASIC_INITIALIZER__
#define __SG_GL_OPENGL_BASIC_INITIALIZER__

#include "sggl/family.h"
#include "sggl/opengl/incogl.h"

namespace sggl
{
    namespace ogl
    {
        namespace basic
        {
            class sgOpenGLInitializer
            {
            public:
                sgOpenGLInitializer() = delete;
                ~sgOpenGLInitializer() = delete;

                static const sgchar * initialze()
                {
                    sguint errCode = glewInit();
                    if(errCode)
                    {
                        return reinterpret_cast<const sgchar *>(glewGetErrorString(errCode));
                    }
                    return nullptr;
                }
                static const sgchar * initialze(sgbool experimental)
                {
                    glewExperimental = experimental;
                    sguint errCode = glewInit();
                    if(errCode)
                    {
                        return reinterpret_cast<const sgchar *>(glewGetErrorString(errCode));
                    }
                    return nullptr;
                }
            };
        }
    }
}


#endif //!__SG_GL_OPENGL_BASIC_INITIALIZER__