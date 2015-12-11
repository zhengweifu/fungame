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
    glGenVertexArraysAPPLE(1, &vao);
    glBindVertexArrayAPPLE(vao);
    
    fungame::math::Vector2 v2(10, 18);
    
    fungame::math::Matrix4 m4;
    
    std::cout << m4 << std::endl;
    
    std::cout << v2 << std::endl;
    

    while (!window.closed()) {
        window.clear();
#if 1
        glBegin(GL_TRIANGLES);
        glVertex2d(0.0f, 0.5f);
        glVertex2d(-0.5f, 0.0f);
        glVertex2d(0.5f, 0.0f);
        glEnd();
#else
        glDrawArrays(GL_ARRAY_BUFFER, 0, 8);
#endif
        window.update();
    }
    
    return 0;
}
