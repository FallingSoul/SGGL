#ifndef __SG_GL_GRAPHICS_OPENGL_TYPE__
#define __SG_GL_GRAPHICS_OPENGL_TYPE__


#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"



namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            template<class Type>
            struct sgOglType;

            template<>
            struct sgOglType<sgbyte>{static constexpr sguint type = GL_BYTE;};
            template<>
            struct sgOglType<sgubyte>{static constexpr sguint type = GL_UNSIGNED_BYTE;};

            template<>
            struct sgOglType<sgshort>{static constexpr sguint type = GL_SHORT;};
            template<>
            struct sgOglType<sgushort>{static constexpr sguint type = GL_UNSIGNED_SHORT;};

            template<>
            struct sgOglType<sgint>{static constexpr sguint type = GL_INT;};
            template<>
            struct sgOglType<sguint>{static constexpr sguint type = GL_UNSIGNED_INT;};

            template<>
            struct sgOglType<sgfloat>{static constexpr sguint type = GL_FLOAT;};
            template<>
            struct sgOglType<sgdouble>{static constexpr sguint type = GL_DOUBLE;};

            
        }
    }
}



#endif //!__SG_GL_GRAPHICS_OPENGL_TYPE__