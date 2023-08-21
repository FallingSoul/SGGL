#ifndef __SG_GL_GRAPHICS_OPENGL_FRAMEBUFFER__
#define __SG_GL_GRAPHICS_OPENGL_FRAMEBUFFER__

#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"
#include "sggl/graphics/opengl/object.h"
#include "sggl/graphics/opengl/operator.h"
#include "sggl/graphics/opengl/framebuffer_type.h"
#include "sggl/graphics/opengl/attachment.h"
#include "sggl/graphics/opengl/texture.h"

namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            class sgOglFramebuffer : public sgOglObject
            {
            public:
                sgOglFramebuffer()
                {
                    glGenFramebuffers(1,&this->identifier());
                }
                ~sgOglFramebuffer()
                {
                    if(false == this->invalid())
                    {
                        glDeleteFramebuffers(1,&this->identifier());
                    }
                }
            public:
                template<sgOglFramebufferType Type>
                class sgOglOperator;
            };
            
            template<>
            class sgOglFramebuffer::sgOglOperator<sgOglFramebufferType::Default> : public opengl::sgOglOperator
            {
            private:
                static constexpr sguint _target = sgOglFramebufferTarget<sgOglFramebufferType::Default>::target;
            public:
                sgOglOperator(sgOglFramebuffer & framebuffer)
                {
                    glBindFramebuffer(_target,framebuffer.identifier());
                }
                ~sgOglOperator()
                {
                    glBindFramebuffer(_target,GL_NONE);
                }
                template<sgOglAttachment Attachment>
                sgvoid attach_tex2D(sgOglTexture & texture,sgint level = 0)
                {
                    glFramebufferTexture2D(_target,sgOglAttachmentTarget<Attachment>::target,sgOglTextureTarget<sgOglTextureType::Texture2D>::target,texture.identifier(),level);
                }
                template<sgOglAttachment ... Attachments>
                sgvoid draw_buffers()
                {
                    sguint buffers[] = {sgOglAttachmentTarget<Attachments>::target...};
                    glDrawBuffers(sizeof...(Attachments),&buffers[0]);
                }
                sgbool completed()const
                {
                    return GL_FRAMEBUFFER_COMPLETE == glCheckFramebufferStatus(_target);
                }
            };
        }
    }
}


#endif //!__SG_GL_GRAPHICS_OPENGL_FRAMEBUFFER__