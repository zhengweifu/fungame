#include "fungame/graphic/shader.h"
#include <iostream>

namespace fungrame { namespace graphic {
	GLint Shader::createShader(const GLchar* shaderSource, const GLenum &shaderType) 
	{
		const char* shaderName = shaderType == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT";
		GLuint shader = glCreateShader(shaderType);
		glShaderSource(shader, 1, &shaderSource, NULL);
		glCompileShader(shader);
		GLint success;
		GLchar infoLog[1024];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) 
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "Error::SHADER::" << shaderName << "::COMPILE_FAILED\n" << infoLog << std::endl;
			return -1;
		}

		return shader;
	}

	bool Shader::create(const GLchar* vShaderSource, const GLchar* fShaderSource) 
	{
		vertexShader = createShader(vShaderSource, GL_VERTEX_SHADER);
		fragmentShader = createShader(fShaderSource, GL_FRAGMENT_SHADER);
		if (vertexShader >= 0 && fragmentShader >= 0)
		{
			return true;
		}
		else 
		{
			vertexShader = -1;
			fragmentShader = -1;
			return false;
		}
	}


	void Shader::use(GLuint& program)
	{
		if (vertexShader >= 0 && fragmentShader >= 0) 
		{
			glAttachShader(program, vertexShader);
			glAttachShader(program, fragmentShader);
			glLinkProgram(program);
		}
		else 
		{
			std::cerr << "Error:" << std::endl;
		}
	}

	void Shader::remove() 
	{
		if (vertexShader >= 0)
		{
			glDeleteShader(vertexShader);
			vertexShader = -1;
		}

		if (fragmentShader >= 0)
		{
			glDeleteShader(fragmentShader);
			fragmentShader = -1;
		}
	}
}}
