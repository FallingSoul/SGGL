#ifndef __SG_GL_GRAPHICS_OPENGL_USAGE__
#define __SG_GL_GRAPHICS_OPENGL_USAGE__



#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"



namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            enum class sgOglUsage
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
            template<sgOglUsage Usage>
            struct sgOglUsageType;

            template<>
            struct sgOglUsageType<sgOglUsage::StaticDraw>{static constexpr sguint type = GL_STATIC_DRAW;};
            template<>
            struct sgOglUsageType<sgOglUsage::StaticRead>{static constexpr sguint type = GL_STATIC_READ;};
            template<>
            struct sgOglUsageType<sgOglUsage::StaticCopy>{static constexpr sguint type = GL_STATIC_COPY;};

            
            template<>
            struct sgOglUsageType<sgOglUsage::StreamDraw>{static constexpr sguint type = GL_STREAM_DRAW;};
            template<>
            struct sgOglUsageType<sgOglUsage::StreamRead>{static constexpr sguint type = GL_STREAM_READ;};
            template<>
            struct sgOglUsageType<sgOglUsage::StreamCopy>{static constexpr sguint type = GL_STREAM_COPY;};

            
            template<>
            struct sgOglUsageType<sgOglUsage::DynamicDraw>{static constexpr sguint type = GL_DYNAMIC_DRAW;};
            template<>
            struct sgOglUsageType<sgOglUsage::DynamicRead>{static constexpr sguint type = GL_DYNAMIC_READ;};
            template<>
            struct sgOglUsageType<sgOglUsage::DynamicCopy>{static constexpr sguint type = GL_DYNAMIC_COPY;};

        }
    }
}


#endif //!__SG_GL_GRAPHICS_OPENGL_USAGE__