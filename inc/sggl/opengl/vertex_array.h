#ifndef __SG_GL_OPENGL_VERTEX_ARRAY__
#define __SG_GL_OPENGL_VERTEX_ARRAY__


#include "sggl/family.h"
#include "sggl/opengl/incogl.h"
#include "sggl/opengl/object.h"

namespace sggl
{
    namespace ogl
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
            sgvoid bind()const noexcept
            {
                glBindVertexArray(this->id());
            }
        };
    }
}


#endif //!__SG_GL_OPENGL_VERTEX_ARRAY__