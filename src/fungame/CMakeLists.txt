set(INC
    ..)

set(SRC
    graphic/Window.cpp
    graphic/VBO.cpp
    graphic/Shader.cpp
    math/FMath.cpp
    math/Matrix4.cpp
    math/Vector2.cpp
    math/Vector3.cpp
)

set(SRC_HEADERS
    fungame.h
    graphic/Window.h
    graphic/VBO.h
    graphic/Shader.h
    math/FMath.h
    math/Matrix4.h
    math/Vector2.h
    math/Vector3.h

)

include_directories(${INC})

add_library(fungame STATIC ${SRC} ${SRC_HEADERS})