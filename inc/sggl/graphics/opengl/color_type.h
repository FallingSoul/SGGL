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
                D24S8
            };

            template<sgOglColorType Type>
            struct sgOglColorTarget;

            
            template<>
            struct sgOglColorTarget<sgOglColorType::RGB>{static constexpr sguint target = GL_RGB;};
            template<>
            struct sgOglColorTarget<sgOglColorType::RGBA>{static constexpr sguint target = GL_RGBA;};
            template<>
            struct sgOglColorTarget<sgOglColorType::D24S8>{static constexpr sguint target = GL_DEPTH24_STENCIL8;};

        }
    }
}


#endif //!__SG_GL_GRAPHICS_OPENGL_COLOR_TYPE__