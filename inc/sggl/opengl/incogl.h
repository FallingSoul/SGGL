#ifndef __SG_GL_INCOGL__
#define __SG_GL_INCOGL__

#include "sggl/family.h"


#if defined(SG_GL_OPENGL_USE_GLEW)
#include <GL/glew.h>
#elif defined(SG_GL_OPENGL_USE_GLAD)
#include <GL/glad.h>
#else
#error "choose glew or glad (define SG_GL_OPENGL_USE_GLEW or SG_GL_OPENGL_USE_GLAD)"
#endif


#endif //!__SG_GL_INCOGL__