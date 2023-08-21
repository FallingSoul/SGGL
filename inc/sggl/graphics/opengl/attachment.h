#ifndef __SG_GL_GRAPHICS_OPENGL_ATTACHMENT__
#define __SG_GL_GRAPHICS_OPENGL_ATTACHMENT__

#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"



namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            enum class sgOglAttachment
            {
                Color0,
                Color1,
                Color2,
                Color3,
                Color4,
                Color5,
                Color6,
                Color7,
                Color8,
                Color9,
                Color10,
                Color11,
                Color12,
                Color13,
                Color14,
                Color15,
                Depth,
                Stencil,
                DepthStencil
            };
            template<sgOglAttachment Attachment>
            struct sgOglAttachmentTarget;

            
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Color0>{static constexpr sguint target = GL_COLOR_ATTACHMENT0;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Color1>{static constexpr sguint target = GL_COLOR_ATTACHMENT1;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Color2>{static constexpr sguint target = GL_COLOR_ATTACHMENT2;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Color3>{static constexpr sguint target = GL_COLOR_ATTACHMENT3;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Color4>{static constexpr sguint target = GL_COLOR_ATTACHMENT4;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Color5>{static constexpr sguint target = GL_COLOR_ATTACHMENT5;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Color6>{static constexpr sguint target = GL_COLOR_ATTACHMENT6;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Color7>{static constexpr sguint target = GL_COLOR_ATTACHMENT7;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Color8>{static constexpr sguint target = GL_COLOR_ATTACHMENT8;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Color9>{static constexpr sguint target = GL_COLOR_ATTACHMENT9;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Color10>{static constexpr sguint target = GL_COLOR_ATTACHMENT10;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Color11>{static constexpr sguint target = GL_COLOR_ATTACHMENT11;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Color12>{static constexpr sguint target = GL_COLOR_ATTACHMENT12;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Color13>{static constexpr sguint target = GL_COLOR_ATTACHMENT13;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Color14>{static constexpr sguint target = GL_COLOR_ATTACHMENT14;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Color15>{static constexpr sguint target = GL_COLOR_ATTACHMENT15;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Depth>{static constexpr sguint target = GL_DEPTH_ATTACHMENT;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::Stencil>{static constexpr sguint target = GL_STENCIL_ATTACHMENT;};
            template<>
            struct sgOglAttachmentTarget<sgOglAttachment::DepthStencil>{static constexpr sguint target = GL_DEPTH_STENCIL_ATTACHMENT;};
        }
    }
}

#endif //!__SG_GL_GRAPHICS_OPENGL_ATTACHMENT__