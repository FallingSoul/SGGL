#ifndef __SG_GL_GRAPHICS_OPENGL_OBJTYPE__
#define __SG_GL_GRAPHICS_OPENGL_OBJTYPE__


#include "sggl/family.h"

namespace sggl
{
    namespace ogl
    {
            enum class sgObjectType
            {
                Unknown,
                Memory,
                VertexArray,
                Buffer,
                Shader,
                Program,
                Texture
            };
    }
}


#endif //!__SG_GL_GRAPHICS_OPENGL_OBJTYPE__