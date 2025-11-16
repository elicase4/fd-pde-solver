# Compiler warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
	add_compile_options(
		-Wall
		-Wextra
		-Wpedantic
		-Wshadow
		-Wconversion
		-Wfloat-equal
		-Wnon-virtual-dtor
	)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	add_compile_options(/W4)
endif()
