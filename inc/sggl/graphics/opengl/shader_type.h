#ifndef __SG_GL_GRAPHICS_OPENGL_SHADER_TYPE__
#define __SG_GL_GRAPHICS_OPENGL_SHADER_TYPE__

#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"


namespace sggl
{
    namespace ogl
    {
            enum class sgShaderType
            {
                Vertex,
                TESSControl,
                TESSEvaluation,
                Geometry,
                Fragment
            };
            template<sgShaderType Type>
            struct sgShaderType2ShaderType;
            template<>
            struct sgShaderType2ShaderType<sgShaderType::Vertex>{static constexpr sguint type = GL_VERTEX_SHADER;};
            template<>
            struct sgShaderType2ShaderType<sgShaderType::TESSControl>{static constexpr sguint type = GL_TESS_CONTROL_SHADER;};
            template<>
            struct sgShaderType2ShaderType<sgShaderType::TESSEvaluation>{static constexpr sguint type = GL_TESS_EVALUATION_SHADER;};
            template<>
            struct sgShaderType2ShaderType<sgShaderType::Geometry>{static constexpr sguint type = GL_GEOMETRY_SHADER;};
            template<>
            struct sgShaderType2ShaderType<sgShaderType::Fragment>{static constexpr sguint type = GL_FRAGMENT_SHADER;};

    }
}

#endif //!__SG_GL_GRAPHICS_OPENGL_SHADER_TYPE__