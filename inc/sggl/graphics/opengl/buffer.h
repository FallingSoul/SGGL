#ifndef __SG_GL_GRAPHICS_OPENGL_BUFFER__
#define __SG_GL_GRAPHICS_OPENGL_BUFFER__


#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"
#include "sggl/graphics/opengl/object.h"
#include "sggl/graphics/opengl/buftype.h"
#include "sggl/graphics/opengl/usagetype.h"


namespace sggl
{
    namespace ogl
    {
            class sgBuffer : public sgObject<sgObjectType::Buffer>
            {
            public:
                sgBuffer()
                {
                    glGenBuffers(1,&this->id());
                }
                ~sgBuffer()
                {
                    if(false == this->invalid())
                    {
                        glDeleteBuffers(1,&this->id());
                    }
                }
                template<sgBufferType Type>
                sgvoid bind()
                {
                    glBindBuffer(sgBufferType2Target<Type>::target,this->id());
                }
                template<sgBufferType Type>
                sgvoid bind(sguint index)
                {
                    glBindBufferBase(sgBufferType2Target<Type>::target,index,this->id());
                }
                template<sgBufferType Type>
                static sgvoid unbind()
                {
                    glBindBuffer(sgBufferType2Target<Type>::target,InvalidObject);
                }
                template<sgBufferType Type>
                static sgvoid unbind(sguint index)
                {
                    glBindBufferBase(sgBufferType2Target<Type>::target,index,InvalidObject);
                }
                template<sgBufferType Type,sgUsageType Usage>
                static sgvoid setData(const sgvoid * data,sgsize size)
                {
                    glBufferData(sgBufferType2Target<Type>::target,size,data,sgUsageType2Usage<Usage>::usage);
                }
                template<sgBufferType Type>
                static sgvoid setSubData(const sgvoid * data,sgsize size,sguintptr offset)
                {
                    glBufferSubData(sgBufferType2Target<Type>::target,offset,size,data);
                }
                template<sgBufferType Type>
                static sgvoid getSubData(sgvoid * data,sgsize size,sguintptr offset)
                {
                    glGetBufferSubData(sgBufferType2Target<Type>::target,offset,size,data);
                }

            };
    }
}

#endif //!__SG_GL_GRAPHICS_OPENGL_BUFFER__