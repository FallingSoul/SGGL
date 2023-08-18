
#include <stdio.h>

//#define SG_GL_OPENGL_USE_GLEW
#include "sggl/sggl.h"
#include "sggl/graphics/opengl.h"
#include "sggl/graphics/glfw.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 1280

float vertices[] =
{
    -0.5, 0.5,0.0,1.0,
    -0.5,-0.5,0.0,0.0,
     0.5,-0.5,1.0,0.0,
    -0.5, 0.5,0.0,1.0,
     0.5,-0.5,1.0,0.0,
     0.5, 0.5,1.0,1.0
};
const char * vertexShaderSource = 
    R"(
        #version 330 core
        layout(location = 0) in vec2 aPos;
        layout(location = 1) in vec2 aTexCoord;
        out vec2 tex_coord;
        void main()
        {
            tex_coord = aTexCoord * 2;
            gl_Position = vec4(aPos,0.0,1.0);
        }
    )"
;
const char * fragmentShaderSource = 
    R"(
        #version 330 core
        in vec2 tex_coord;
        uniform sampler2D tex;
        void main()
        {
            gl_FragColor = texture(tex,tex_coord);
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
    vao_op.set_attr<sggl::sgfloat>(0,2,sizeof(sggl::sgfloat) * 4,sizeof(sggl::sgfloat) * 0);
    vao_op.set_attr<sggl::sgfloat>(1,2,sizeof(sggl::sgfloat) * 4,sizeof(sggl::sgfloat) * 2);
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

    sggl::graphics::opengl::sgOglTexture texture;
    int width,height,channel;
    stbi_set_flip_vertically_on_load(true);
    stbi_uc * data = stbi_load(R"(./image.png)",&width,&height,&channel,0);
    if(nullptr == data)
    {
        printf("cannot load image!\n");
    }
    else
    {
        decltype(texture)::sgOglOperator<sggl::graphics::opengl::sgOglTextureType::Texture2D> texture_op(texture);
        if(channel == 3)texture_op.load<stbi_uc,sggl::graphics::opengl::sgOglColorType::RGB>(data,width,height);
        else if(channel == 4)texture_op.load<stbi_uc,sggl::graphics::opengl::sgOglColorType::RGBA>(data,width,height);
        else printf("unsupported image format!");
        stbi_image_free(data);
        texture_op.set_filter<sggl::graphics::opengl::sgOglFilter::Linear>();
        texture_op.set_wrap<sggl::graphics::opengl::sgOglWrap::MirrorRepeat>();
        texture_op.gen_mipmap();
    }








    glfwShowWindow(window);
    while(GLFW_FALSE == glfwWindowShouldClose(window))
    {
        glClearColor(0.0,0.0,0.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        program.use();
        decltype(vao)::sgOglOperator vao_op(vao);
        decltype(texture)::sgOglOperator<sggl::graphics::opengl::sgOglTextureType::Texture2D> texture_op(texture);

        glDrawArrays(GL_TRIANGLES,0,6);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }



    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}