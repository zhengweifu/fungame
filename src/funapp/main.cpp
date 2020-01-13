//
//  main.cpp
//  fungame
//
//  Created by zwf on 09/12/2015.
//  Copyright © 2015 com.zwf. All rights reserved.
//

#include <iostream>

#include <fungame/fungame.h>


int main(int argc, const char * argv[]) {
    

    fungrame::graphic::Window window("fungrame", 600, 800);
    
    glClearColor(0.5f, 0.2f, 0.6f, 1.0f);
    
    GLuint vao;
#if defined(__APPLE__)
    glGenVertexArraysAPPLE(1, &vao);
    glBindVertexArrayAPPLE(vao);
#esle
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
#endif
    
    fungame::math::Vector2 v2(10, 18);
    
    fungame::math::Matrix4 m4;
    
    std::cout << m4 << std::endl;
    
    std::cout << v2 << std::endl;
    

    while (!window.closed()) {
        window.clear();
#if 0
        glBegin(GL_TRIANGLES);
        glVertex2d(0.0f, 0.5f);
        glVertex2d(-0.5f, 0.0f);
        glVertex2d(0.5f, 0.0f);
        glEnd();
#else
		float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		// create vbo
		GLuint vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		

		// create program
		GLuint shaderProgram = glCreateProgram();

		// create shader
		std::string pvs = "#version 330 core\nlayout(location = 0) in vec3 position;\nvoid main(){\ngl_Position = vec4(position, 1.0);\n}";
		std::string pfs = "#version 330 core\nout vec4 FragColor;\nvoid main(){FragColor = vec4(1.0, 0.0, 1.0, 1.0);}";
		const char* vs = pvs.c_str();
		const char* fs = pfs.c_str();

		fungrame::graphic::Shader shader;
		shader.create(vs, fs);
		shader.use(shaderProgram);

		glUseProgram(shaderProgram);

		// enable vbo and draw
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glDrawArrays(GL_TRIANGLES, 0, 3);


		// disable vbo
		glDisableVertexAttribArray(0);


#endif
        window.update();
    }
    
    return 0;
}
