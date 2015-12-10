//
//  Window.cpp
//  fungame
//
//  Created by zwf on 09/12/2015.
//  Copyright © 2015 com.zwf. All rights reserved.
//

#include <deps/glew/include/mac/glew.h>
#include "Window.h"
#include <iostream>

namespace fungrame { namespace graphic {
    
    void windowResize(GLFWwindow *window, int width, int height) {
        glViewport(0, 0, width, height);
    }
    
    Window::Window(const char *title, int width, int height) {
        m_title = title;
        m_width = width;
        m_height = height;
        if (!init()) {
            glfwTerminate();
        }
    }

    Window::~Window() {}
    
    
    bool Window::init() {
        
        if(!glfwInit()) {
            std::cout << "Failed to init glfw." << std::endl;
            return false;
        }
        
        m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
        
        if (!m_window) {
            std::cout << "Failed to create GLFW window." << std::endl;
            return false;
        }
        
        glfwMakeContextCurrent(m_window);
        
        glfwSetWindowSizeCallback(m_window, windowResize);
        
        if(glewInit() != GLEW_OK) {
            std::cout << "Failed to init glew!" << std::endl;
            return false;
        }
        
        return true;
    }
    
    void Window::clear() const {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    
    bool Window::closed() const {
        return glfwWindowShouldClose(m_window) == 1;
    }

    void Window::update() const {
        glfwPollEvents();
//        glfwGetFramebufferSize(m_window, &m_width, &m_height);
        glfwSwapBuffers(m_window);
    }

}}