add_executable(benchmark.exe benchmark.cpp)
target_link_libraries(benchmark.exe PRIVATE solvers)

add_executable(solver_app.exe solver.cpp)
target_link_libraries(solver_app.exe PRIVATE solvers)

add_executable(visualization.exe visualization.cpp)
target_link_libraries(visualization.exe PRIVATE solvers)
