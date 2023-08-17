#ifndef __SG_GL_GRAPHICS_OPENGL_SHADER__
#define __SG_GL_GRAPHICS_OPENGL_SHADER__



#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"
#include "sggl/graphics/opengl/object.h"
#include "sggl/graphics/opengl/operator.h"
#include "sggl/graphics/opengl/shader_type.h"

namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            template<sgOglShaderType Type>
            class sgOglShader : public sgOglObject
            {
            public:
                friend class sgOglProgram;
            private:
                static constexpr sguint _target = sgOglShaderTarget<Type>::target;
            public:
                sgOglShader()
                    :sgOglObject(glCreateShader(_target))
                {}
                ~sgOglShader()
                {
                    if(false == this->invalid())
                    {
                        glDeleteShader(this->identifier());
                    }
                }
                sgvoid source(const sgchar * src,sgsize len)
                {
                    if(len)
                    {
                        glShaderSource(this->identifier(),1,&src,reinterpret_cast<const GLint *>(&len));
                    }
                    else
                    {
                        glShaderSource(this->identifier(),1,&src,nullptr);
                    }
                }
                sgvoid source(const sgchar * const * src,const sgsize * lengths,sgsize count)
                {
                    glShaderSource(this->identifier(),count,src,lengths);
                }
                sgvoid read_source(sgchar * buffer,sgsize max_len,sgsize * len)
                {
                    glGetShaderSource(this->identifier(),max_len,len,buffer);
                }
                sgvoid compile()
                {
                    glCompileShader(this->identifier());
                }
                sgbool compiled()const
                {
                    sgint status = 0;
                    glGetShaderiv(this->identifier(),GL_COMPILE_STATUS,&status);
                    return GL_FALSE != status;
                }
                sgsize loginfo(sgchar * buffer,sgsize max_len)const
                {
                    sgsize len = 0;
                    glGetShaderInfoLog(this->identifier(),max_len,reinterpret_cast<GLsizei *>(&len),reinterpret_cast<GLchar *>(buffer));
                    return len;
                }

            };
        }
    }
}




#endif //!__SG_GL_GRAPHICS_OPENGL_SHADER__