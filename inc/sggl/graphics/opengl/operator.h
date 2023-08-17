#ifndef __SG_GL_GRAPHICS_OPENGL_OPERATOR__
#define __SG_GL_GRAPHICS_OPENGL_OPERATOR__

#include "sggl/family.h"
#include "sggl/graphics/opengl/incogl.h"

namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            class sgOglOperator
            {
            public:
                sgOglOperator(const sgOglOperator &) = delete;
                const sgOglOperator & operator= (const sgOglOperator &) = delete;
            protected:
                sgOglOperator()
                {}
                ~sgOglOperator()
                {}
            };
        }
    }
}



#endif //!__SG_GL_GRAPHICS_OPENGL_OPERATOR__