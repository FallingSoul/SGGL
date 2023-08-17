#ifndef __SG_GL_GRAPHICS_OPENGL_BUFFER_TYPE__
#define __SG_GL_GRAPHICS_OPENGL_BUFFER_TYPE__



namespace sggl
{
    namespace graphics
    {
        namespace opengl
        {
            enum class sgOglBufferType
            {
                Array,
                Element,
                ShaderStorage,
                Uniform,
                Read,
                Write,
            };
            template<sgOglBufferType Type>
            struct sgOglBufferTarget;

            
            template<>
            struct sgOglBufferTarget<sgOglBufferType::Array>{static constexpr sguint target = GL_ARRAY_BUFFER;};
            template<>
            struct sgOglBufferTarget<sgOglBufferType::Element>{static constexpr sguint target = GL_ELEMENT_ARRAY_BUFFER;};
            template<>
            struct sgOglBufferTarget<sgOglBufferType::ShaderStorage>{static constexpr sguint target = GL_SHADER_STORAGE_BUFFER;};
            template<>
            struct sgOglBufferTarget<sgOglBufferType::Uniform>{static constexpr sguint target = GL_UNIFORM_BUFFER;};
            template<>
            struct sgOglBufferTarget<sgOglBufferType::Read>{static constexpr sguint target = GL_COPY_READ_BUFFER;};
            template<>
            struct sgOglBufferTarget<sgOglBufferType::Write>{static constexpr sguint target = GL_COPY_WRITE_BUFFER;};
        }
    }
}
#endif //!__SG_GL_GRAPHICS_OPENGL_BUFFER_TYPE__