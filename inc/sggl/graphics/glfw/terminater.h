#ifndef __SG_GL_GRAPHICS_GLFW_TERMINATER__
#define __SG_GL_GRAPHICS_GLFW_TERMINATER__

#include <string>
#include "sggl/family.h"
#include "sggl/graphics/glfw/incglfw.h"

namespace sggl
{
    namespace graphics
    {
        namespace glfw
        {
            class sgGlfwTerminater
            {
            public:
                sgGlfwTerminater() = delete;
                ~sgGlfwTerminater() = delete;

                static const sgchar * terminate()
                {
                    glfwTerminate();
                    return nullptr;
                }
            };
        }
    }
}

#endif //!__SG_GL_GRAPHICS_GLFW_TERMINATER__
