#ifndef __SG_GL_GRAPHICS_OPENGL_INITIALIZER__
#define __SG_GL_GRAPHICS_OPENGL_INITIALIZER__

#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"

namespace sggl
{
    namespace ogl
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


#endif //!__SG_GL_GRAPHICS_OPENGL_INITIALIZER__