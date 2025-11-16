add_executable(pde_solve solver.cpp)

target_include_directories(pde_solve PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(pde_solve PUBLIC solvers serial_backend)

if (ENABLE_OMP)
	target_link_libraries(pde_solve PUBLIC openmp_backend)
endif()

if (ENABLE_MPI)
	target_link_libraries(pde_solve PUBLIC mpi_backend)
endif()

if (ENABLE_CUDA)
	target_link_libraries(pde_solve PUBLIC cuda_backend)
endif()

add_executable(benchmark benchmark.cpp)
target_link_libraries(benchmark PUBLIC solvers serial_backend)
