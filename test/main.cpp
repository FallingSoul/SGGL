
#include <stdio.h>

//#define SG_GL_OPENGL_USE_GLEW
#include "sggl/sggl.h"
#include "sggl/graphics/opengl.h"
#include "sggl/graphics/glfw.h"

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

    if(errString = sggl::graphics::opengl::sgOglInitializer::initialize(true))
    {
        printf("cannot init opengl: %s\n",errString);
        glfwTerminate();
        return -1;
    }

    sggl::graphics::opengl::sgOglVertexArray vao;
    sggl::graphics::opengl::sgOglBuffer vbo;
    decltype(vao)::sgOglOperator vao_op(vao);
    decltype(vbo)::sgOglOperator<sggl::graphics::opengl::sgOglBufferType::Array> vbo_op(vbo);
    vbo_op.buffer_data<sggl::graphics::opengl::sgOglUsage::StaticDraw>(vertices,sizeof(vertices));
    vao_op.set_attr<sggl::sgfloat>(0,2,sizeof(sggl::sgfloat) * 5,sizeof(sggl::sgfloat) * 0);
    vao_op.set_attr<sggl::sgfloat>(1,3,sizeof(sggl::sgfloat) * 5,sizeof(sggl::sgfloat) * 2);
    vao_op.enable(0);
    vao_op.enable(1);

    sggl::sgchar loginfo[1024];
    sggl::graphics::opengl::sgOglShader<sggl::graphics::opengl::sgOglShaderType::Vertex> vshader;
    sggl::graphics::opengl::sgOglShader<sggl::graphics::opengl::sgOglShaderType::Fragment> fshader;
    vshader.source(vertexShaderSource,0);
    vshader.compile();
    if(false == vshader.compiled())
    {
        vshader.loginfo(&loginfo[0],sizeof(loginfo));
        printf("cannot compile vertex shader: %s\n",&loginfo[0]);
    }
    fshader.source(fragmentShaderSource,0);
    fshader.compile();
    if(false == fshader.compiled())
    {
        fshader.loginfo(&loginfo[0],sizeof(loginfo));
        printf("cannot compile fragment shader: %s\n",&loginfo[0]);
    }
    
    sggl::graphics::opengl::sgOglProgram program;
    program.attach(vshader);
    program.attach(fshader);
    program.link();
    if(false == program.linked())
    {
        program.loginfo(&loginfo[0],sizeof(loginfo));
        printf("cannot link program: %s\n",&loginfo[0]);
    }









    glfwShowWindow(window);
    while(GLFW_FALSE == glfwWindowShouldClose(window))
    {
        glClearColor(0.0,0.0,0.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        program.use();
        decltype(vao)::sgOglOperator vao_op(vao);

        glDrawArrays(GL_TRIANGLES,0,3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }



    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}