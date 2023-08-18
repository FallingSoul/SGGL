#ifndef __SG_GL_GRAPHICS_OPENGL_TEXTURE_TYPE__
#define __SG_GL_GRAPHICS_OPENGL_TEXTURE_TYPE__

#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"





namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            enum class sgOglTextureType
            {
                Texture1D,
                Texture1DArray,
                Texture2D,
                Texture2DArray,
                Texture3D,
                TextureCubeMap,
                TextureCubeMapArray,
                TextureRectangle,
                Texture2DMultisample,
                Texture2DMultisampleArray,
                TextureBuffer
            };

            template<sgOglTextureType Type>
            struct sgOglTextureTarget;

            
            template<>
            struct sgOglTextureTarget<sgOglTextureType::Texture1D>{static constexpr sguint target = GL_TEXTURE_1D;};
            template<>
            struct sgOglTextureTarget<sgOglTextureType::Texture1DArray>{static constexpr sguint target = GL_TEXTURE_1D_ARRAY;};
            template<>
            struct sgOglTextureTarget<sgOglTextureType::Texture2D>{static constexpr sguint target = GL_TEXTURE_2D;};
            template<>
            struct sgOglTextureTarget<sgOglTextureType::Texture2DArray>{static constexpr sguint target = GL_TEXTURE_2D_ARRAY;};
            template<>
            struct sgOglTextureTarget<sgOglTextureType::Texture3D>{static constexpr sguint target = GL_TEXTURE_3D;};
            template<>
            struct sgOglTextureTarget<sgOglTextureType::TextureCubeMap>{static constexpr sguint target = GL_TEXTURE_CUBE_MAP;};
            template<>
            struct sgOglTextureTarget<sgOglTextureType::TextureCubeMapArray>{static constexpr sguint target = GL_TEXTURE_CUBE_MAP_ARRAY;};
            template<>
            struct sgOglTextureTarget<sgOglTextureType::TextureRectangle>{static constexpr sguint target = GL_TEXTURE_RECTANGLE;};
            template<>
            struct sgOglTextureTarget<sgOglTextureType::Texture2DMultisample>{static constexpr sguint target = GL_TEXTURE_2D_MULTISAMPLE;};
            template<>
            struct sgOglTextureTarget<sgOglTextureType::Texture2DMultisampleArray>{static constexpr sguint target = GL_TEXTURE_2D_MULTISAMPLE_ARRAY;};
            template<>
            struct sgOglTextureTarget<sgOglTextureType::TextureBuffer>{static constexpr sguint target = GL_TEXTURE_BUFFER;};
        }
    }
}


#endif //!__SG_GL_GRAPHICS_OPENGL_TEXTURE_TYPE__