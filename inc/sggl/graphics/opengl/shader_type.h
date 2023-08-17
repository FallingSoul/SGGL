#ifndef __SG_GL_GRAPHICS_OPENGL_SHADER_TYPE__
#define __SG_GL_GRAPHICS_OPENGL_SHADER_TYPE__



#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"
#include "sggl/graphics/opengl/object.h"
#include "sggl/graphics/opengl/operator.h"

namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            enum class sgOglShaderType
            {
                Vertex,
                TESS_Control,
                TESS_Evaluation,
                Geometry,
                Fragment
            };

            template<sgOglShaderType Type>
            struct sgOglShaderTarget;
            
            template<>
            struct sgOglShaderTarget<sgOglShaderType::Vertex>{static constexpr sguint target = GL_VERTEX_SHADER;};
            template<>
            struct sgOglShaderTarget<sgOglShaderType::TESS_Control>{static constexpr sguint target = GL_TESS_CONTROL_SHADER;};
            template<>
            struct sgOglShaderTarget<sgOglShaderType::TESS_Evaluation>{static constexpr sguint target = GL_TESS_EVALUATION_SHADER;};
            template<>
            struct sgOglShaderTarget<sgOglShaderType::Geometry>{static constexpr sguint target = GL_GEOMETRY_SHADER;};
            template<>
            struct sgOglShaderTarget<sgOglShaderType::Fragment>{static constexpr sguint target = GL_FRAGMENT_SHADER;};
        }
    }
}




#endif //!__SG_GL_GRAPHICS_OPENGL_SHADER_TYPE__