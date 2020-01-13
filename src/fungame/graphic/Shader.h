#ifndef __GRAPHIC_SHADER_H__
#define __GRAPHIC_SHADER_H__

#include <GL/glew.h>

namespace fungrame { namespace graphic {
    class Shader {
	private:
		GLint vertexShader = -1;
		GLint fragmentShader = -1;
		GLint Shader::createShader(const GLchar *shaderSource, const GLenum &shaderType);
	public:
		inline GLint getVShader() { return vertexShader; }
		inline GLint getFShader() { return fragmentShader; }
		bool Shader::create(const GLchar *vShaderSource, const GLchar *fShaderSource);

		void use(GLuint& program);

		void remove();
    };
}}


#endif /* __GRAPHIC_SHADER_H__ */
