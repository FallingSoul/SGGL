#ifndef __SG_GL_OPENGL_BASIC_SHADER__
#define __SG_GL_OPENGL_BASIC_SHADER__


#include "sggl/family.h"
#include "sggl/opengl/incogl.h"
#include "sggl/opengl/basic/object.h"
#include "sggl/opengl/basic/shader_type.h"

namespace sggl
{
    namespace ogl
    {
        namespace basic
        {
            class sgShader : public sgObject<sgObjectType::Shader>
            {
            public:
                template<sgShaderType Type>
                sgShader()
                    :sgObject(glCreateShader(sgShaderType2ShaderType<Type>::type))
                {}
                sgShader()
                {}
                ~sgShader()
                {
                    if(false == this->id())
                    {
                        glDeleteShader(this->id());
                    }
                }
                template<sgShaderType Type>
                sgvoid create()
                {
                    this->id() = glCreateShader(sgShaderType2ShaderType<Type>::type);
                }
                sgvoid loadSource(const sgchar * const * source,const sgsize * lengths,sgsize count)
                {
                    glShaderSource(this->id(),count,source,reinterpret_cast<const GLint *>(lengths));
                }
                sgvoid loadSource(const sgchar * source,const sgsize length)
                {
                    const GLint * lengths = nullptr;
                    if(0 != length)
                    {
                        lengths = reinterpret_cast<const GLint *>(&length);
                    }
                    glShaderSource(this->id(),1,&source,reinterpret_cast<const GLint *>(lengths));   
                }
                sgvoid compile()const
                {
                    glCompileShader(this->id());
                }
                sgbool compiled()const
                {
                    GLint status = 0;
                    glGetShaderiv(this->id(),GL_COMPILE_STATUS,&status);
                    return GL_FALSE != status;
                }
                sgsize loginfo(sgchar * buffer,sgsize size)const
                {
                    sgsize length;
                    glGetShaderInfoLog(this->id(),size,reinterpret_cast<GLsizei *>(&length),buffer);
                    return length;
                }

            public:
                friend class sgProgram;
            };
        }
    }
}


#endif //!__SG_GL_OPENGL_BASIC_SHADER__