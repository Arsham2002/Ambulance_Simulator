cmake_minimum_required(VERSION 3.0)
set(CMake_CXX_STANDARD 11)
project(Ambulance_Simulator)
set(SOURCES
	main
	src/App
	src/level
	src/Ambulance
	src/player
)
add_executable(${PROJECT_NAME} ${SOURCES})
include_directories(include)
target_link_libraries(${PROJECT_NAME} sfml-window sfml-system sfml-graphics)