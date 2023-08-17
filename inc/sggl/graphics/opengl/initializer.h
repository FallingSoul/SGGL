#ifndef __SG_GL_GRAPHICS_OPENGL_INITIALIZER__
#define __SG_GL_GRAPHICS_OPENGL_INITIALIZER__


#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"


namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            class sgOglInitializer
            {
            public:
                sgOglInitializer() = delete;
                ~sgOglInitializer() = delete;

                static const sgchar * initialize()
                {
                    sguint errCode = glewInit();
                    if(errCode)
                    {
                        return reinterpret_cast<const sgchar *>(glewGetErrorString(errCode));
                    }
                    return nullptr;
                }
                static const sgchar * initialize(sgbool experimental)
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




#endif //!__SG_GL_GRAPHICS_OPENGL_INITIALIZER__