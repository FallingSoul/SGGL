#ifndef __SG_GL_GRAPHICS_OPENGL_BUFFER__
#define __SG_GL_GRAPHICS_OPENGL_BUFFER__

#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"
#include "sggl/graphics/opengl/object.h"
#include "sggl/graphics/opengl/operator.h"
#include "sggl/graphics/opengl/buffer_type.h"
#include "sggl/graphics/opengl/usage.h"
#include "sggl/graphics/opengl/access.h"

namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            class sgOglBuffer : public sgOglObject
            {
            public:
                sgOglBuffer()
                {
                    glGenBuffers(1,&this->identifier());
                }
                ~sgOglBuffer()
                {
                    if(false == this->invalid())
                    {
                        glDeleteBuffers(1,&this->identifier());
                    }
                }
            public:
                template<sgOglBufferType Type>
                class sgOglOperator : public opengl::sgOglOperator
                {
                private:
                    static constexpr auto _target = sgOglBufferTarget<Type>::target;
                public:
                    sgOglOperator(sgOglBuffer & ubo)
                    {
                        glBindBuffer(_target,ubo.identifier());
                    }
                    sgOglOperator(sgOglBuffer & ubo,sguint index)
                    {
                        glBindBufferBase(_target,index,ubo.identifier());
                    }
                    template<sgOglUsage Usage>
                    sgvoid buffer_data(const sgvoid * data,sgint size)
                    {
                        glBufferData(_target,size,data,sgOglUsageType<Usage>::type);
                    }
                    template<sgOglUsage Usage>
                    sgvoid buffer_data(const sgvoid * data,sgint size,sguintptr offset)
                    {
                        glBufferSubData(_target,offset,size,data);
                    }
                    template<sgOglAccess Access>
                    sgvoid * map()
                    {
                        return glMapBuffer(_target,sgOglAccessType<Access>::type);
                    }
                    template<sgOglAccess Access>
                    sgvoid * map(sguintptr offset,sgint size)
                    {
                        return glMapBufferRange(_target,offset,size,sgOglAccessType<Access>::type);
                    }
                    sgvoid read_data(sgvoid * data,sgint size,sguintptr offset)
                    {
                        glGetBufferSubData(_target,offset,size,data);
                    }
                };
            };
        }
    }
}


#endif //!__SG_GL_GRAPHICS_OPENGL_BUFFER__
