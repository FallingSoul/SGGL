#ifndef __SG_GL_GRAPHICS_OPENGL_USAGETYPE__
#define __SG_GL_GRAPHICS_OPENGL_USAGETYPE__



#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"

namespace sggl
{
    namespace ogl
    {
            enum class sgUsageType
            {
                StaticDraw,
                StaticRead,
                StaticCopy,
                StreamDraw,
                StreamRead,
                StreamCopy,
                DynamicDraw,
                DynamicRead,
                DynamicCopy
            };
            template<sgUsageType Usage>
            struct sgUsageType2Usage;
            template<>
            struct sgUsageType2Usage<sgUsageType::StaticDraw>{static constexpr sguint usage = GL_STATIC_DRAW;};
            template<>
            struct sgUsageType2Usage<sgUsageType::StaticRead>{static constexpr sguint usage = GL_STATIC_READ;};
            template<>
            struct sgUsageType2Usage<sgUsageType::StaticCopy>{static constexpr sguint usage = GL_STATIC_COPY;};

            template<>
            struct sgUsageType2Usage<sgUsageType::StreamDraw>{static constexpr sguint usage = GL_STREAM_DRAW;};
            template<>
            struct sgUsageType2Usage<sgUsageType::StreamRead>{static constexpr sguint usage = GL_STREAM_READ;};
            template<>
            struct sgUsageType2Usage<sgUsageType::StreamCopy>{static constexpr sguint usage = GL_STREAM_COPY;};
            
            template<>
            struct sgUsageType2Usage<sgUsageType::DynamicDraw>{static constexpr sguint usage = GL_DYNAMIC_DRAW;};
            template<>
            struct sgUsageType2Usage<sgUsageType::DynamicRead>{static constexpr sguint usage = GL_DYNAMIC_READ;};
            template<>
            struct sgUsageType2Usage<sgUsageType::DynamicCopy>{static constexpr sguint usage = GL_DYNAMIC_COPY;};
    }
}

#endif //!__SG_GL_GRAPHICS_OPENGL_USAGETYPE__