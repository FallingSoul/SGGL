#ifndef __SG_GL_GRAPHICS_OPENGL_FRAMEBUFFER_TYPE__
#define __SG_GL_GRAPHICS_OPENGL_FRAMEBUFFER_TYPE__

#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"


namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            enum class sgOglFramebufferType
            {
                Default,
                Draw,
                Read
            };
            template<sgOglFramebufferType Type>
            struct sgOglFramebufferTarget;

            
            template<>
            struct sgOglFramebufferTarget<sgOglFramebufferType::Default>{static constexpr sguint target = GL_FRAMEBUFFER;};
            template<>
            struct sgOglFramebufferTarget<sgOglFramebufferType::Draw>{static constexpr sguint target = GL_DRAW_FRAMEBUFFER;};
            template<>
            struct sgOglFramebufferTarget<sgOglFramebufferType::Read>{static constexpr sguint target = GL_READ_FRAMEBUFFER;};
        }
    }
}


#endif //!__SG_GL_GRAPHICS_OPENGL_FRAMEBUFFER_TYPE__