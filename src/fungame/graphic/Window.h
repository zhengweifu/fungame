//
//  Window.h
//  fungame
//
//  Created by zwf on 09/12/2015.
//  Copyright © 2015 com.zwf. All rights reserved.
//

#ifndef __GRAPHIC_WINDOW_H__
#define __GRAPHIC_WINDOW_H__

#include <stdio.h>
#include <GLFW/glfw3.h>

namespace fungrame { namespace graphic {

#define MAX_KEYS    1024
#define MAX_BUTTONS 32
    
    void window_resize(GLFWwindow *window, int width, int height);
    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
    void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
    
    class Window {
    private:
        int m_width;
        int m_height;
        const char *m_title;
        GLFWwindow *m_window;
        
        static bool m_keys[MAX_KEYS];
        static bool m_buttons[MAX_BUTTONS];
        static double m_x, m_y;
    public:
        Window(const char *title, int width, int height);
        ~Window();
        void clear() const;
        bool closed() const;
        void update() const;
        
        inline int getWindow() const {return m_width;}
        inline int getHeight() const {return m_height;}
        
    private:
        bool init();
    };
}}


#endif /* __GRAPHIC_WINDOW_H__ */
