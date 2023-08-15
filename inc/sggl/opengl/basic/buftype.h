#ifndef __SG_GL_OPENGL_BASIC_BUFTYPE__
#define __SG_GL_OPENGL_BASIC_BUFTYPE__


#include "sggl/family.h"
#include "sggl/opengl/incogl.h"

namespace sggl
{
    namespace ogl
    {
        namespace basic
        {
            enum class sgBufferType
            {
                Array,
                Element,
                Uniform
            };
            template<sgBufferType Type>
            struct sgBufferType2Target;
            template<>
            struct sgBufferType2Target<sgBufferType::Array>{static constexpr sguint target = GL_ARRAY_BUFFER;};
            template<>
            struct sgBufferType2Target<sgBufferType::Element>{static constexpr sguint target = GL_ELEMENT_ARRAY_BUFFER;};
            template<>
            struct sgBufferType2Target<sgBufferType::Uniform>{static constexpr sguint target = GL_UNIFORM_BUFFER;};
        }
    }
}

#endif //!__SG_GL_OPENGL_BASIC_BUFTYPE__