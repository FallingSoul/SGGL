#ifndef __SG_GL_GRAPHICS_OPENGL_FILTER_TYPE__
#define __SG_GL_GRAPHICS_OPENGL_FILTER_TYPE__



#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"


namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            enum class sgOglFilter
            {
                Nearest,
                Linear
            };
            template<sgOglFilter>
            struct sgOglFilterType;

            
            template<>
            struct sgOglFilterType<sgOglFilter::Nearest>{static constexpr sguint type = GL_NEAREST;};
            template<>
            struct sgOglFilterType<sgOglFilter::Linear>{static constexpr sguint type = GL_LINEAR;};

        }
    }
}


#endif //!__SG_GL_GRAPHICS_OPENGL_FILTER_TYPE__