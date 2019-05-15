file(GLOB TESTS ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
target_sources(run_tests PRIVATE ${TESTS})
target_include_directories(run_tests PUBLIC 
    "${CMAKE_SOURCE_DIR}/include"
    ${BREW_INCLUDE_DIRS}
)
