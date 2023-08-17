#ifndef __SG_GL_GRAPHICS_OPENGL_PROGRAM__
#define __SG_GL_GRAPHICS_OPENGL_PROGRAM__



#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"
#include "sggl/graphics/opengl/object.h"
#include "sggl/graphics/opengl/operator.h"
#include "sggl/graphics/opengl/shader.h"



namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            class sgOglProgram : public sgOglObject
            {
            public:
                sgOglProgram()
                    :sgOglObject(glCreateProgram())
                {}
                ~sgOglProgram()
                {
                    if(false == this->invalid())
                    {
                        glDeleteProgram(this->identifier());
                    }
                }
                template<sgOglShaderType Type>
                sgvoid attach(sgOglShader<Type> & shader)
                {
                    glAttachShader(this->identifier(),shader.identifier());
                }
                template<sgOglShaderType Type>
                sgvoid detach(sgOglShader<Type> & shader)
                {
                    glDetachShader(this->identifier,shader.identifier());
                }
                sgvoid link()
                {
                    glLinkProgram(this->identifier());
                }
                sgbool linked()const
                {
                    sgint status = 0;
                    glGetProgramiv(this->identifier(),GL_LINK_STATUS,&status);
                    return GL_FALSE != status;
                }
                sgsize loginfo(sgchar * buffer,sgsize max_len)const
                {
                    sgsize len = 0;
                    glGetProgramInfoLog(this->identifier(),max_len,reinterpret_cast<GLsizei *>(&len),reinterpret_cast<GLchar *>(buffer));
                    return len;
                }
                sgvoid use()
                {
                    glUseProgram(this->identifier());
                }

            };
        }
    }
}

#endif //!__SG_GL_GRAPHICS_OPENGL_PROGRAM__