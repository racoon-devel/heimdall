file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp *.hpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${3RDPARTY_INCLUDES}
)

target_link_libraries(${PROJECT_NAME} ${3RDPARTY_LIBRARIES})
