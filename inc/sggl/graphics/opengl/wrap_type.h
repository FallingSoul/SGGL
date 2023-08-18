#ifndef __SG_GL_GRAPHICS_OPENGL_WRAP_TYPE__
#define __SG_GL_GRAPHICS_OPENGL_WRAP_TYPE__



#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"


namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            enum class sgOglWrap
            {
                Repeat,
                MirrorRepeat,
                ClampToEdge,
                ClampToBorder
            };
            template<sgOglWrap>
            struct sgOglWarpType;

            
            template<>
            struct sgOglWarpType<sgOglWrap::Repeat>{static constexpr sguint type = GL_REPEAT;};
            template<>
            struct sgOglWarpType<sgOglWrap::MirrorRepeat>{static constexpr sguint type = GL_MIRRORED_REPEAT;};
            template<>
            struct sgOglWarpType<sgOglWrap::ClampToEdge>{static constexpr sguint type = GL_CLAMP_TO_EDGE;};
            template<>
            struct sgOglWarpType<sgOglWrap::ClampToBorder>{static constexpr sguint type = GL_CLAMP_TO_BORDER;};


        }
    }
}


#endif //!__SG_GL_GRAPHICS_OPENGL_WRAP_TYPE__