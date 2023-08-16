#ifndef __SG_GL_GRAPHICS_OPENGL_OBJECT__
#define __SG_GL_GRAPHICS_OPENGL_OBJECT__

#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"
#include "sggl/graphics/opengl/objtype.h"


namespace sggl
{
    namespace ogl
    {
            template<sgObjectType Type>
            class sgObject;

            template<>
            class sgObject<sgObjectType::Unknown>
            {
            protected:
                typedef GLuint sgObjectID;
                static constexpr sgObjectID InvalidObject = GL_NONE;
            public:
                sgObject(const sgObject &) = delete;
                const sgObject & operator= (const sgObject &) = delete;
            protected:
                sgObject()noexcept
                    :_obj(InvalidObject)
                {}
                sgObject(sgObjectID obj)noexcept
                    :_obj(obj)
                {}
                ~sgObject()
                {
                    this->_obj = InvalidObject;
                }
                sgObjectID id()const noexcept
                {
                    return this->_obj;
                }
                sgObjectID & id()noexcept
                {
                    return this->_obj;
                }
                operator sgObjectID ()const noexcept
                {
                    return this->_obj;
                }
                operator sgObjectID & ()noexcept
                {
                    return this->_obj;
                }
            public:
                sgbool invalid()const noexcept
                {
                    return this->_obj == InvalidObject;
                }
                sgvoid swap(sgObject & obj)noexcept
                {
                    sgObjectID temp = this->_obj;
                    this->_obj = obj._obj;
                    obj._obj = temp;
                }
                static sgObjectType type()noexcept
                {
                    return sgObjectType::Unknown;
                }
            private:
                sgObjectID _obj;
            };

            template<sgObjectType Type>
            class sgObject : public sgObject<sgObjectType::Unknown>
            {
            public:
                sgObject(const sgObject &) = delete;
                const sgObject & operator= (const sgObject &) = delete;
            protected:
                sgObject()noexcept
                    :sgObject<sgObjectType::Unknown>::sgObject(InvalidObject)
                {}
                sgObject(sgObjectID obj)noexcept
                    :sgObject<sgObjectType::Unknown>::sgObject(obj)
                {}
                ~sgObject()
                {}
            public:
                static sgObjectType type()noexcept
                {
                    return Type;
                }
            private:
                sgObjectID _obj;
            };
    }
}



#endif //!__SG_GL_GRAPHICS_OPENGL_OBJECT__