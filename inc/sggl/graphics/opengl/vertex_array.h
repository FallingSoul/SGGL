#ifndef __SG_GL_GRAPHICS_OPENGL_VERTEX_ARRAY__
#define __SG_GL_GRAPHICS_OPENGL_VERTEX_ARRAY__


#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"
#include "sggl/graphics/opengl/type.h"
#include "sggl/graphics/opengl/object.h"
#include "sggl/graphics/opengl/operator.h"


namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            class sgOglVertexArray : public sgOglObject
            {
            public:
                sgOglVertexArray()
                {
                    glGenVertexArrays(1,&this->identifier());
                }
                ~sgOglVertexArray()
                {
                    if(false == this->invalid())
                    {
                        glDeleteVertexArrays(1,&this->identifier());
                    }
                }
            public:
                class sgOglOperator : public opengl::sgOglOperator
                {
                public:
                    sgOglOperator(sgOglVertexArray & array)
                    {
                        glBindVertexArray(array.identifier());
                    }
                    template<class Type>
                    sgvoid set_attr(sguint index,sgint count,sgsize stride,sguintptr offset,sgbool normalized = false)
                    {
                        glVertexAttribPointer(index,count,sgOglType<Type>::type,normalized,stride,reinterpret_cast<const sgvoid *>(offset));
                    }
                    sgvoid enable(sguint index)
                    {
                        glEnableVertexAttribArray(index);
                    }
                    sgvoid disable(sguint index)
                    {
                        glDisableVertexAttribArray(index);   
                    }
                };
            };
        }
    }
}


#endif //!__SG_GL_GRAPHICS_OPENGL_VERTEX_ARRAY__