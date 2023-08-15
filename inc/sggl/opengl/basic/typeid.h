#ifndef __SG_GL_OPENGL_BASIC_TYPEID__
#define __SG_GL_OPENGL_BASIC_TYPEID__



#include "sggl/family.h"
#include "sggl/opengl/incogl.h"



namespace sggl
{
    namespace ogl
    {
        namespace basic
        {
            template<class Type>
            struct sgType2Typeid;

            template<>
            struct sgType2Typeid<sgbool>{static constexpr sguint type = GL_BOOL;};
            template<>
            struct sgType2Typeid<sgbyte>{static constexpr sguint type = GL_BYTE;};
            template<>
            struct sgType2Typeid<sgubyte>{static constexpr sguint type = GL_UNSIGNED_BYTE;};
            template<>
            struct sgType2Typeid<sgshort>{static constexpr sguint type = GL_SHORT;};
            template<>
            struct sgType2Typeid<sgushort>{static constexpr sguint type = GL_UNSIGNED_SHORT;};
            template<>
            struct sgType2Typeid<sgint>{static constexpr sguint type = GL_INT;};
            template<>
            struct sgType2Typeid<sguint>{static constexpr sguint type = GL_UNSIGNED_INT;};
            template<>
            struct sgType2Typeid<sgfloat>{static constexpr sguint type = GL_FLOAT;};
            template<>
            struct sgType2Typeid<sgdouble>{static constexpr sguint type = GL_DOUBLE;};
        }
    }
}

#endif //!__SG_GL_OPENGL_BASIC_TYPEID__