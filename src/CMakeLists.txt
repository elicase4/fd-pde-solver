# Core math library
file(GLOB CORE_SOURCES
	pde/*.cpp
)

add_library(core ${CORE_SOURCES})
target_include_directories(core PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Solver library
file(GLOB SOLVER_SOURCES
	solvers/*.cpp
)

add_library(solvers ${SOLVER_SOURCES})
target_include_directories(solvers PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(solvers PUBLIC core)

# Backends
add_subdirectory(backends)
