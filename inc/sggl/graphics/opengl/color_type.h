#ifndef __SG_GL_GRAPHICS_OPENGL_COLOR_TYPE__
#define __SG_GL_GRAPHICS_OPENGL_COLOR_TYPE__

#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"





namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            enum class sgOglColorType
            {
                RGB,
                RGBA,
            };

            template<sgOglColorType Type>
            struct sgOglColorTarget;

            
            template<>
            struct sgOglColorTarget<sgOglColorType::RGB>{static constexpr sguint target = GL_RGB;};
            template<>
            struct sgOglColorTarget<sgOglColorType::RGBA>{static constexpr sguint target = GL_RGBA;};

        }
    }
}


#endif //!__SG_GL_GRAPHICS_OPENGL_COLOR_TYPE__