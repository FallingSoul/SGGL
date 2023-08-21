#ifndef __SG_GL_GRAPHICS_OPENGL_RENDERBUFFER__
#define __SG_GL_GRAPHICS_OPENGL_RENDERBUFFER__



#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"
#include "sggl/graphics/opengl/object.h"
#include "sggl/graphics/opengl/operator.h"
#include "sggl/graphics/opengl/color_type.h"



namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            class sgRenderbuffer : public sgOglObject
            {
            public:
                sgRenderbuffer()
                {
                    glGenRenderbuffers(1,&this->identifier());
                }
                ~sgRenderbuffer()
                {
                    if(false == this->invalid())
                    {
                        glDeleteRenderbuffers(1,&this->identifier());
                    }
                    
                }
            public:
                class sgOglOperator : opengl::sgOglOperator
                {
                private:
                    static constexpr sguint _target = GL_RENDERBUFFER;
                public:
                    sgOglOperator(sgRenderbuffer & renderbuffer)
                    {
                        glBindRenderbuffer(_target,renderbuffer.identifier());
                    }
                    sgOglOperator()
                    {
                        glBindRenderbuffer(_target,GL_NONE);
                    }
                    template<sgOglColorType Type>
                    sgvoid storage(sgint width,sgint height)
                    {
                        glRenderbufferStorage(_target,sgOglColorTarget<Type>::target,width,height);
                    }
                    template<sgOglColorType Type>
                    sgvoid storage(sgint width,sgint height,sgint samples)
                    {
                        glRenderbufferStorageMultisample(_target,samples,sgOglColorTarget<Type>::target,width,height);
                    }

                };
            };
        }
    }
}
#endif //!__SG_GL_GRAPHICS_OPENGL_RENDERBUFFER__