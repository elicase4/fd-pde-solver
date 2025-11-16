cmake_minimum_required(VERSION 3.18)

project(PoissonPDESolver
	VERSION 1.0
	DESCRIPTION "Poisson PDE Solver"
	LANGUAGES CXX C
)

# User Options
option(ENABLE_MPI "Enable MPI backend" ON)
option(ENABLE_OMP "Enable OpenMP backend" ON)
option(ENABLE_CUDA "Enable CUDA backend" ON)
option(ENABLE_TESTS "Enable unit tests" ON)

# Cpp Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include custom CMake files
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(compiler_flags)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(apps)

# Add testing
if (ENABLE_TESTS)
	enable_testing()
	add_subdirectory(tests)
endif()
