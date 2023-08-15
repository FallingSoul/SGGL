
#include <stdio.h>


//#define SG_GL_OPENGL_USE_GLEW
#include "sggl/sggl.h"
#include "sggl/opengl/opengl.h"
#include "sggl/glfw/glfw.h"

#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 1280

GLuint vao = GL_NONE;
GLuint vbo = GL_NONE;
GLuint program = GL_NONE;
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
    glewExperimental = true;
    GLenum errCode = glewInit();
    if(errCode)
    {
        printf("cannot init opengl: %s\n",glewGetErrorString(errCode));
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    glGenVertexArrays(1,&vao);
    glGenBuffers(1,&vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(float) * 5,nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(float) * 5,reinterpret_cast<const void *>(sizeof(float) * 2));
    glEnableVertexAttribArray(1);
    glBindVertexArray(GL_NONE);
    glBindBuffer(GL_ARRAY_BUFFER,GL_NONE);

    GLuint shader = GL_NONE;
    GLint status = 0;
    char loginfo[1024]{};
    program = glCreateProgram();

    shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader,1,&vertexShaderSource,nullptr);
    glCompileShader(shader);
    glGetShaderiv(shader,GL_COMPILE_STATUS,&status);
    if(GL_FALSE == status)
    {
        glGetShaderInfoLog(shader,1024,nullptr,loginfo);
        printf(loginfo);
    }
    glAttachShader(program,shader);
    glDeleteShader(shader);

    shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shader,1,&fragmentShaderSource,nullptr);
    glCompileShader(shader);
    glGetShaderiv(shader,GL_COMPILE_STATUS,&status);
    if(GL_FALSE == status)
    {
        glGetShaderInfoLog(shader,1024,nullptr,loginfo);
        printf(loginfo);
    }
    glAttachShader(program,shader);
    glDeleteShader(shader);
    glLinkProgram(program);


    glfwShowWindow(window);
    while(GLFW_FALSE == glfwWindowShouldClose(window))
    {
        glClearColor(0.0,0.0,0.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glBindVertexArray(vao);
        glUseProgram(program);
        glDrawArrays(GL_TRIANGLES,0,3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
	glDeleteBuffers(1,&vbo);
	glDeleteVertexArrays(1,&vao);
	glDeleteProgram(program);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}