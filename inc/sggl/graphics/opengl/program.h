#ifndef __SG_GL_GRAPHICS_OPENGL_PROGRAM__
#define __SG_GL_GRAPHICS_OPENGL_PROGRAM__


#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"
#include "sggl/graphics/opengl/object.h"
#include "sggl/graphics/opengl/shader.h"


namespace sggl
{
    namespace ogl
    {
            class sgProgram : public sgObject<sgObjectType::Program>
            {
            public:
                sgProgram()
                    :sgObject(glCreateProgram())
                {}
                ~sgProgram()
                {
                    if(false == this->invalid())
                    {
                        glDeleteProgram(this->id());
                    }
                }
                sgvoid attach(const sgShader & shader)
                {
                    glAttachShader(this->id(),shader.id());
                }
                sgvoid detach(const sgShader & shader)
                {
                    glDetachShader(this->id(),shader.id());
                }
                sgvoid link()const
                {
                    glLinkProgram(this->id());
                }
                sgvoid use()const
                {
                    glUseProgram(this->id());
                }
                sgbool linked()
                {
                    GLint status = 0;
                    glGetProgramiv(this->id(),GL_LINK_STATUS,&status);
                    return GL_FALSE != status;
                }
                sgsize loginfo(sgchar * buffer,sgsize size)const
                {
                    sgsize length;
                    glGetProgramInfoLog(this->id(),size,reinterpret_cast<GLsizei *>(&length),buffer);
                    return length;
                }
                sgint getUniformLocation(const sgchar * name)const
                {
                    return glGetUniformLocation(this->id(),name);
                }
            };
    }
}


#endif //!__SG_GL_GRAPHICS_OPENGL_PROGRAM__