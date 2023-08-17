#ifndef __SG_GL_GRAPHICS_OPENGL_OBJECT__
#define __SG_GL_GRAPHICS_OPENGL_OBJECT__

#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"

namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            class sgOglObject
            {
            public:
                typedef GLuint sgOglObjectID;
                sgOglObject(const sgOglObject &) = delete;
            protected:
                static constexpr sgOglObjectID InvalidObjectID = GL_NONE;
                sgOglObject()
                    :_identifier(InvalidObjectID)
                {}
                sgOglObject(sgOglObjectID id)
                    :_identifier(id)
                {}
                ~sgOglObject()
                {
                    this->_identifier = InvalidObjectID;
                }
            protected:
                sgOglObjectID identifier()const noexcept
                {
                    return this->_identifier;
                }
                sgOglObjectID & identifier()noexcept
                {
                    return this->_identifier;
                }
            public:
                sgbool invalid()const noexcept
                {
                    return this->_identifier == InvalidObjectID;
                }
            private:
                sgOglObjectID _identifier;
            };
        }
    }
}



#endif //!__SG_GL_GRAPHICS_OPENGL_OBJECT__