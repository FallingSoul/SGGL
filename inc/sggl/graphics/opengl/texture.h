#ifndef __SG_GL_GRAPHICS_OPENGL_TEXTURE__
#define __SG_GL_GRAPHICS_OPENGL_TEXTURE__

#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"
#include "sggl/graphics/opengl/object.h"
#include "sggl/graphics/opengl/operator.h"
#include "sggl/graphics/opengl/type.h"
#include "sggl/graphics/opengl/texture_type.h"
#include "sggl/graphics/opengl/color_type.h"
#include "sggl/graphics/opengl/filter_type.h"
#include "sggl/graphics/opengl/wrap_type.h"
#include "sggl/graphics/opengl/framebuffer_type.h"



namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            class sgOglTexture : public sgOglObject
            {
            public:
                sgOglTexture()
                {
                    glGenTextures(1,&this->identifier());
                }
                ~sgOglTexture()
                {
                    if(false == this->invalid())
                    {
                        glDeleteTextures(1,&this->identifier());
                    }
                }
            public:
                template<sgOglTextureType Type>
                class sgOglOperator;
            public:
                friend class sgOglFramebuffer;
            };
            template<>
            class sgOglTexture::sgOglOperator<sgOglTextureType::Texture2D> : public opengl::sgOglOperator
            {
            private:
                static constexpr sguint _target = sgOglTextureTarget<sgOglTextureType::Texture2D>::target;
            public:
                sgOglOperator(sgOglTexture & texture)
                {
                    glBindTexture(_target,texture.identifier());
                }
                sgOglOperator(sgOglTexture & texture,sguint index)
                {
                    glActiveTexture(GL_TEXTURE0 + index);
                    glBindTexture(_target,texture.identifier());
                }
                template<class Type,sgOglColorType Format>
                sgvoid load(const Type * data,sgint width,sgint height,sgint level = 0)
                {
                    glTexImage2D(_target,level,sgOglColorTarget<Format>::target,width,height,0,sgOglColorTarget<Format>::target,sgOglType<Type>::type,data);
                }
                template<class Type,sgOglColorType Format,sgOglColorType InternalFormat>
                sgvoid load(const Type * data,sgint width,sgint height,sgint level = 0)
                {
                    glTexImage2D(_target,level,sgOglColorTarget<InternalFormat>::target,width,height,0,sgOglColorTarget<Format>::target,sgOglType<Type>::type,data);
                }
                template<class Type,sgOglColorType Format>
                sgvoid storage(sgint width,sgint height)
                {
                    glTexImage2D(_target,0,sgOglColorTarget<Format>::target,width,height,0,sgOglColorTarget<Format>::target,sgOglType<Type>::type,nullptr);
                }
                template<class Type,sgOglColorType Format,sgOglColorType InternalFormat>
                sgvoid storage(sgint width,sgint height)
                {
                    glTexImage2D(_target,0,sgOglColorTarget<InternalFormat>::target,width,height,0,sgOglColorTarget<Format>::target,sgOglType<Type>::type,nullptr);
                }
                template<sgOglFilter MagFilter,sgOglFilter MinFilter>
                sgvoid set_filter()
                {
                    glTexParameteri(_target,GL_TEXTURE_MAG_FILTER,sgOglFilterType<MagFilter>::type);
                    glTexParameteri(_target,GL_TEXTURE_MIN_FILTER,sgOglFilterType<MinFilter>::type);
                }
                template<sgOglFilter Filter>
                sgvoid set_filter()
                {
                    glTexParameteri(_target,GL_TEXTURE_MAG_FILTER,sgOglFilterType<Filter>::type);
                    glTexParameteri(_target,GL_TEXTURE_MIN_FILTER,sgOglFilterType<Filter>::type);
                }
                template<sgOglWrap SWrap,sgOglWrap TWrap>
                sgvoid set_wrap()
                {
                    glTexParameteri(_target,GL_TEXTURE_WRAP_S,sgOglWarpType<SWrap>::type);
                    glTexParameteri(_target,GL_TEXTURE_WRAP_T,sgOglWarpType<TWrap>::type);
                }
                template<sgOglWrap Wrap>
                sgvoid set_wrap()
                {
                    glTexParameteri(_target,GL_TEXTURE_WRAP_S,sgOglWarpType<Wrap>::type);
                    glTexParameteri(_target,GL_TEXTURE_WRAP_T,sgOglWarpType<Wrap>::type);
                }
                sgvoid gen_mipmap()
                {
                    glGenerateMipmap(_target);
                }
            };
        }
    }
}




#endif //!__SG_GL_GRAPHICS_OPENGL_TEXTURE__