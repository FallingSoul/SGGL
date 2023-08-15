#ifndef __SG_GL_OPENGL_BASIC_VERTEX_ARRAY__
#define __SG_GL_OPENGL_BASIC_VERTEX_ARRAY__


#include "sggl/family.h"
#include "sggl/opengl/incogl.h"
#include "sggl/opengl/basic/object.h"
#include "sggl/opengl/basic/typeid.h"

namespace sggl
{
    namespace ogl
    {
        namespace basic
        {

            class sgVertexArray : public sgObject<sgObjectType::VertexArray>
            {
            public:
                sgVertexArray()
                {
                    glGenVertexArrays(1,&this->id());
                }
                ~sgVertexArray()
                {
                    if(false == this->invalid())
                    {
                        glDeleteVertexArrays(1,&this->id());
                    }
                }
                sgvoid bind()const
                {
                    glBindVertexArray(this->id());
                }
                static sgvoid unbind()
                {
                    glBindVertexArray(InvalidObject);
                }
                template<class Type>
                static sgvoid setAttr(sguint index,sgsize count,sgsize strideBytes,sguintptr offset = 0,sgbool nomralized = false)
                {
                    glVertexAttribPointer(index,count,sgType2Typeid<Type>::type,nomralized,strideBytes,reinterpret_cast<const sgvoid *>(offset));
                }
                static sgvoid enable(sguint index)
                {
                    glEnableVertexAttribArray(index);
                }
                static sgvoid disable(sguint index)
                {
                    glDisableVertexAttribArray(index);
                }
            };
        }
    }
}


#endif //!__SG_GL_OPENGL_BASIC_VERTEX_ARRAY__