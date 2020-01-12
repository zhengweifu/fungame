link_directories(
	${GLEW_LIBPATH}
	${GLFW_LIBPATH}
	${SELF_LIBPATH}
) 
include_directories(..)

set(OUT_MOUDLE_NAME fun)
add_executable (${OUT_MOUDLE_NAME} "main.cpp")
target_link_libraries(${OUT_MOUDLE_NAME}
	glfw3dll
	glew32s
	${OPENGL_LIBRARIES}
	fungame
)
