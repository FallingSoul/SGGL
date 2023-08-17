#ifndef __SG_GL_GRAPHICS_OPENGL_ACCESS__
#define __SG_GL_GRAPHICS_OPENGL_ACCESS__


#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"


namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            enum class sgOglAccess
            {
                ReadOnly,
                WriteOnly,
                ReadWrite
            };
            template<sgOglAccess Access>
            struct sgOglAccessType;

            
            template<>
            struct sgOglAccessType<sgOglAccess::ReadOnly>{static constexpr sguint type = GL_READ_ONLY;};
            template<>
            struct sgOglAccessType<sgOglAccess::WriteOnly>{static constexpr sguint type = GL_WRITE_ONLY;};
            template<>
            struct sgOglAccessType<sgOglAccess::ReadWrite>{static constexpr sguint type = GL_READ_WRITE;};
        }
    }
}


#endif //!__SG_GL_GRAPHICS_OPENGL_ACCESS__