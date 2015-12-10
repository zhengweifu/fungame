//
//  Window.hpp
//  fungame
//
//  Created by zwf on 09/12/2015.
//  Copyright © 2015 com.zwf. All rights reserved.
//

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <stdio.h>
#include <deps/glfw3/include/mac/glfw3.h>

namespace fungrame { namespace graphic {
    
    void windowResize(GLFWwindow *window, int width, int height);
    
    class Window {
    private:
        int m_width;
        int m_height;
        const char *m_title;
        GLFWwindow *m_window;
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


#endif /* __WINDOW_H__ */
