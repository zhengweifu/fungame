//
//  Window.cpp
//  fungame
//
//  Created by zwf on 09/12/2015.
//  Copyright © 2015 com.zwf. All rights reserved.
//

#include <GL/glew.h>
#include "fungame/graphic/Window.h"
#include <iostream>

namespace fungrame { namespace graphic {

    // window resize callback
    void window_resize(GLFWwindow *window, int width, int height) {
        glViewport(0, 0, width, height);
    }
    
    // key callback
    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
        std::cout << "key: " << key << " scancode: " << scancode << " action: " << action << " mods: " << mods << std::endl;
    }
    
    // cursor position callback
    void cursor_position_callback(GLFWwindow *window, double xpos, double ypos) {
        std::cout << "x : " << xpos << " y: " << ypos << std::endl;
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
        glfwSetWindowUserPointer(m_window, this);
        glfwSetWindowSizeCallback(m_window, window_resize); // execute window resize callback
        glfwSetKeyCallback(m_window, key_callback); // execute key callback
        glfwSetCursorPosCallback(m_window, cursor_position_callback); // execute mouse callback
        
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