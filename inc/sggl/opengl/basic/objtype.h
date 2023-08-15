#ifndef __SG_GL_OPENGL_BASIC_OBJTYPE__
#define __SG_GL_OPENGL_BASIC_OBJTYPE__


#include "sggl/family.h"

namespace sggl
{
    namespace ogl
    {
        namespace basic
        {

            enum class sgObjectType
            {
                Unknown,
                VertexArray,
                Buffer,
                Shader,
                Program,
                Texture
            };
        }
    }
}


#endif //!__SG_GL_OPENGL_BASIC_OBJTYPE__