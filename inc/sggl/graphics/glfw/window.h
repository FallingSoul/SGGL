#ifndef __SG_GL_GRAPHICS_GLFW_WINDOW__
#define __SG_GL_GRAPHICS_GLFW_WINDOW__

#include <string>
#include <functional>
#include "sggl/family.h"
#include "sggl/graphics/glfw/incglfw.h"

namespace sggl
{
    namespace graphics
    {
        namespace glfw
        {
            class sgGlfwWindow
            {
            private:
                GLFWwindow *m_window;
                int m_width, m_height;
                std::string m_caption;
                GLFWmonitor *m_moniter;
                GLFWwindow *m_share;
                std::function<void(sgGlfwWindow*)> m_on_key_input;
                std::function<void(sgGlfwWindow*)> m_on_sizing;
                std::function<void(sgGlfwWindow*)> m_on_render;
            private:
                static void m_framebuffer_size_callback(GLFWwindow *window, int w, int h)
                {
                    sgGlfwWindow *sgwindow = (sgGlfwWindow *)glfwGetWindowUserPointer(window);
                    sgwindow->m_width = w;
                    sgwindow->m_height = h;
                    sgwindow->m_on_sizing(sgwindow);
                }
            public:
                sgGlfwWindow()
                {
                    this->m_width = 960;
                    this->m_height = 640;
                    this->m_caption = "SG Window";
                    this->m_moniter = nullptr;
                    this->m_share = nullptr;
                    this->m_window = glfwCreateWindow(this->m_width, this->m_height, 
                        this->m_caption.c_str(), this->m_moniter, this->m_share);

                    if(!this->m_window)
                    {
                        printf("Failed to create GLFW window!");
                    }

                    //保存this指针到用户数据
                    glfwSetWindowUserPointer(this->m_window, (void *)this);

                    //大小改变时的回调函数
                    glfwSetFramebufferSizeCallback(this->m_window, &sgGlfwWindow::m_framebuffer_size_callback);
                }

                sgGlfwWindow(int w, int h, const std::string& caption, 
                    GLFWmonitor *monitor, GLFWwindow *share)
                {
                    this->m_width = w;
                    this->m_height = h;
                    this->m_caption = caption;
                    this->m_moniter = monitor;
                    this->m_share = share;
                    this->m_window = glfwCreateWindow(this->m_width, this->m_height, 
                        this->m_caption.c_str(), this->m_moniter, this->m_share);
                    this->m_on_render = [](sgGlfwWindow *){};
                    this->m_on_sizing = [](sgGlfwWindow *){};
                    this->m_on_key_input = [](sgGlfwWindow *){};                    

                    if(!this->m_window)
                    {
                        printf("Failed to create GLFW window!");
                    }

                    //保存this指针到用户数据
                    glfwSetWindowUserPointer(this->m_window, (void *)this);

                    //大小改变时的回调函数
                    glfwSetFramebufferSizeCallback(this->m_window, &sgGlfwWindow::m_framebuffer_size_callback);
                }
                ~sgGlfwWindow()
                {
                    glfwDestroyWindow(this->m_window);
                }
                void set_width(int width)
                {
                    this->m_width = width;
                    glfwSetWindowSize(this->m_window, this->m_width, this->m_height);
                }
                void set_height(int height)
                {
                    this->m_height = height;
                    glfwSetWindowSize(this->m_window, this->m_width, this->m_height);
                }
                void set_size(int width, int height)
                {
                    this->m_width = width;
                    this->m_height = height;
                    glfwSetWindowSize(this->m_window, this->m_width, this->m_height);
                }
                void set_caption(const std::string& caption)
                {
                    this->m_caption = caption;
                    glfwSetWindowTitle(this->m_window, this->m_caption.c_str());
                }
                void set_window_should_close(bool b_close)
                {
                    glfwSetWindowShouldClose(this->m_window, b_close);
                }
                void set_on_key_input(std::function<void(sgGlfwWindow*)> on_key_input)
                {
                    this->m_on_key_input = on_key_input;
                }
                void set_on_render(std::function<void(sgGlfwWindow*)> on_render)
                {
                    this->m_on_render = on_render;
                }
                void set_on_sizing(std::function<void(sgGlfwWindow*)> on_sizing)
                {
                    this->m_on_sizing = on_sizing;
                }

                int get_width()
                {
                    return this->m_width;
                }
                int get_height()
                {
                    return this->m_height;
                }
                std::string get_caption()
                {
                    return this->m_caption;
                }
                bool get_window_should_close()
                {
                    return glfwWindowShouldClose(this->m_window);
                }

                void make_context_current()
                {
                    glfwMakeContextCurrent(this->m_window);
                }
                void swap_buffers()
                {
                    glfwSwapBuffers(this->m_window);
                }
                void poll_events()
                {
                    glfwPollEvents();
                }

                void render_loop()
                {
                    while(!get_window_should_close())
                    {
                        this->m_on_key_input(this);
                        this->m_on_render(this);
                        this->swap_buffers();
                        this->poll_events();
                    }
                }

                void show()
                {
                    glfwShowWindow(this->m_window);
                }

                void destroy()
                {
                    glfwDestroyWindow(this->m_window);
                }
            };
        }
    }
}

#endif //!__SG_GL_GRAPHICS_GLFW_WINDOW__
