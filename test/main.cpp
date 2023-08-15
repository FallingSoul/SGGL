
#include <stdio.h>


//#define SG_GL_OPENGL_USE_GLEW
#include "sggl/sggl.h"
#include "sggl/opengl/opengl.h"
#include "sggl/glfw/glfw.h"

#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 1280

float vertices[] =
{
     0.0, 0.5,1.0,0.0,0.0,
    -0.5,-0.5,0.0,0.0,1.0,
     0.5,-0.5,0.0,1.0,0.0
};
const char * vertexShaderSource = 
    R"(
        #version 330 core
        layout(location = 0) in vec2 aPos;
        layout(location = 1) in vec3 aColor;
        out vec4 color;
        void main()
        {
            color = vec4(aColor,1.0);
            gl_Position = vec4(aPos,0.0,1.0);
        }
    )"
;
const char * fragmentShaderSource = 
    R"(
        #version 330 core
        in vec4 color;
        void main()
        {
            gl_FragColor = color;
        }
    )"
;
const char * errString = nullptr;


int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);
#ifdef SG_GL_HOST_APPLE_MAC
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
#endif

    GLFWwindow * window = glfwCreateWindow(WINDOW_WIDTH,WINDOW_HEIGHT,"Hello OpenGL!",nullptr,nullptr);
    if(nullptr == window)
    {
        const char * errString = nullptr;
        glfwGetError(&errString);
        printf("cannot create glfw window: %s\n",errString);
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glViewport(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);

    if(errString = sggl::ogl::basic::sgOpenGLInitializer::initialze(true))
    {
        printf("cannot init opengl: %s\n",errString);
        glfwTerminate();
        return -1;
    }

    sggl::ogl::basic::sgVertexArray vao;
    sggl::ogl::basic::sgBuffer vbo;
    vao.bind();
    vbo.bind<sggl::ogl::basic::sgBufferType::Array>();
    vbo.setData<sggl::ogl::basic::sgBufferType::Array,sggl::ogl::basic::sgUsageType::StaticDraw>(&vertices[0],sizeof(vertices));
    vao.setAttr<sggl::sgfloat>(0,2,5 * sizeof(sggl::sgfloat),0);
    vao.setAttr<sggl::sgfloat>(1,3,5 * sizeof(sggl::sgfloat),2 * sizeof(sggl::sgfloat));
    vao.enable(0);
    vao.enable(1);
    vbo.unbind<sggl::ogl::basic::sgBufferType::Array>();
    vao.unbind();

    sggl::ogl::basic::sgProgram program;
    sggl::ogl::basic::sgShader shader;
    sggl::sgchar loginfo[1024]{};

    shader.create<sggl::ogl::basic::sgShaderType::Vertex>();
    shader.loadSource(vertexShaderSource,0);
    shader.compile();
    if(false == shader.compiled())
    {
        shader.loginfo(&loginfo[0],1024);
        printf(&loginfo[0]);
    }
    program.attach(shader);
    shader.~sgShader();

    shader.create<sggl::ogl::basic::sgShaderType::Fragment>();
    shader.loadSource(fragmentShaderSource,0);
    shader.compile();
    if(false == shader.compiled())
    {
        shader.loginfo(&loginfo[0],1024);
        printf(&loginfo[0]);
    }
    program.attach(shader);
    shader.~sgShader();

    program.link();





    glfwShowWindow(window);
    while(GLFW_FALSE == glfwWindowShouldClose(window))
    {
        glClearColor(0.0,0.0,0.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        vao.bind();
        program.use();
        glDrawArrays(GL_TRIANGLES,0,3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    vao.~sgVertexArray();
    vbo.~sgBuffer();
    program.~sgProgram();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}