cmake_minimum_required(VERSION 3.27)
project(UCSC)

set(CMAKE_CXX_STANDARD 14)

# Include GoogleTest and enable testing
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.10.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

include_directories(week3/src)
add_definitions(-DDEBUG_MODE)

add_executable(UCSC
        week3/src/main.cpp
        week3/lib/graph/src/graph.cpp
        week3/lib/graph/src/graph.h
        week3/lib/graph/src/graph.cpp
        week3/src/common.h
        week3/lib/debug/src/debug.cpp
        week3/lib/debug/src/debug.h
        week3/lib/monteCarloSim/src/monteCarloSim.cpp
        week3/lib/monteCarloSim/src/monteCarloSim.h
        week3/lib/integration/src/integration.cpp
        week3/lib/integration/src/integration.h
        week3/lib/runtime_parameters/src/runtime_parameters.cpp
        week3/lib/runtime_parameters/src/runtime_parameters.h
)


       # week3/src/main.h)
add_executable(imgui_demo
        imgui/examples/Dijkstra_gui/main.cpp
        imgui/imgui.cpp
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_widgets.cpp
        imgui/imgui_tables.cpp
        imgui/backends/imgui_impl_opengl3.cpp
        imgui/backends/imgui_impl_glfw.cpp

        #imgui/examples/libs/glfw/include/GLFW/glfw3.h
    )

target_include_directories(imgui_demo
        PRIVATE imgui
        PRIVATE imgui/backends
        PRIVATE imgui/examples/libs/glfw/include)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(unit_test_ucsc
        week3/tests/test_main.cpp
        week3/tests/test_graph.cpp
        week3/tests/test_montecarlo_sim.cpp

        week3/lib/graph/src/graph.cpp
        week3/lib/graph/src/graph.h
        week3/lib/monteCarloSim/src/monteCarloSim.cpp
        week3/lib/monteCarloSim/src/monteCarloSim.h
        week3/src/common.h

)
target_link_libraries(unit_test_ucsc gtest_main)
enable_testing()

add_test(NAME unit_test_ucsc COMMAND unit_test_ucsc)
add_executable(duc_solution_graph week3/solution/duc_graph.cpp
        week3/lib/appstate/src/appstate.tpp
        week3/lib/appstate/src/appstate.h)
add_executable(new_graph week3/compare/sim_graph.cpp)
