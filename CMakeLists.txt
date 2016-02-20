cmake_minimum_required (VERSION 2.6)
project(STAFSEAsq-TwoCircles)

SET(CMAKE_BUILD_TYPE Debug)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(SOURCE_DIR ${PROJECT_BINARY_DIR}/src/main)
set(TESTS_DIR ${PROJECT_BINARY_DIR}/src/test)

configure_file(
	${SOURCE_DIR}/STAFSEAsq/init/TwoCircles.h.in
	${PROJECT_BINARY_DIR}/include/STAFSEAsq/init/TwoCircles.h
)

include_directories(${PROJECT_BINARY_DIR}/include)

install(FILES ${PROJECT_BINARY_DIR}/include/STAFSEAsq/init/TwoCircles.h
        DESTINATION include/STAFSEAsq
        CONFIGURATIONS Release Debug)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

add_library(STAFSEAsq_TwoCircles ${SOURCE_DIR}/STAFSEAsq/init/TwoCircles.cc)

install(TARGETS STAFSEAsq_TwoCircles
		ARCHIVE DESTINATION lib
		CONFIGURATIONS Release Debug)

add_executable(test_circles ${TESTS_DIR}/test_circles.cc)
add_dependencies(test_circles STAFSEAsq_TwoCircles)
target_link_libraries(test_circles STAFSEAsq_TwoCircles)

install(TARGETS test_circles
		RUNTIME DESTINATION bin
		CONFIGURATIONS Debug)

install(FILES ${TESTS_DIR}/test_circles.gnuplot
		DESTINATION bin
		CONFIGURATIONS Debug)
