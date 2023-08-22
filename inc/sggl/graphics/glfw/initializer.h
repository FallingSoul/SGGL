#ifndef __SG_GL_GRAPHICS_GLFW_INITIALIZER__
#define __SG_GL_GRAPHICS_GLFW_INITIALIZER__

#include <string>
#include "sggl/family.h"
#include "sggl/graphics/glfw/incglfw.h"

namespace sggl
{
    namespace graphics
    {
        namespace glfw
        {
            class sgGlfwInitializer
            {
            public:
            enum class sgGlfwWindowHintEnum
                {
                    ContextVersionMajor = GLFW_CONTEXT_VERSION_MAJOR,
                    ContextVersionMinor = GLFW_CONTEXT_VERSION_MINOR,
                    OpenGLProfile = GLFW_OPENGL_PROFILE,
                    Resizable = GLFW_RESIZABLE,
                    Focused = GLFW_FOCUSED,
                    Iconified = GLFW_ICONIFIED,
                    Visible = GLFW_VISIBLE,
                    Decorated = GLFW_DECORATED,
                    AutoIconify = GLFW_AUTO_ICONIFY,
                    Floating = GLFW_FLOATING,
                    Maximized = GLFW_MAXIMIZED,
                    CenterCursur = GLFW_CENTER_CURSOR,
                    TransparentFramebuffer = GLFW_TRANSPARENT_FRAMEBUFFER,
                    FocusOnShow = GLFW_FOCUS_ON_SHOW,
                    ScaleToMonitor = GLFW_SCALE_TO_MONITOR,
                    CocoaRetinaFramebuffer = GLFW_COCOA_RETINA_FRAMEBUFFER,
                    CocoaFrameName = GLFW_COCOA_FRAME_NAME,
                    CocoaGraphicsSwitching = GLFW_COCOA_GRAPHICS_SWITCHING,
                    X11ClassName = GLFW_X11_CLASS_NAME,
                    X11InstanceName = GLFW_X11_INSTANCE_NAME
                };
                enum class sgGlfwOpenglProfile
                {
                    Core = GLFW_OPENGL_CORE_PROFILE,
                    Any = GLFW_OPENGL_ANY_PROFILE,
                    Compat = GLFW_OPENGL_COMPAT_PROFILE
                };

                sgGlfwInitializer() = delete;
                ~sgGlfwInitializer() = delete;

                static const sgchar * initialize()
                {
                    glfwInit();
                    return nullptr;
                }
                
                template<typename T>
                static void hint(sgGlfwWindowHintEnum hint, T value)
                {
                    glfwWindowHint((int)hint, (int)value);
                }

                static void swap_interval(int interval)
                {
                    glfwSwapInterval(interval);
                }
            };
        }
    }
}

#endif //!__SG_GL_GRAPHICS_GLFW_INITIALIZER__
