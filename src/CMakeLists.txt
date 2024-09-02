include(EmbedResource)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp *.hpp)

# Embed JSON schema of config
embed_resource(config_schema config/schema.json)

add_executable(${PROJECT_NAME} 
    ${SOURCES}
    ${CMAKE_CURRENT_BINARY_DIR}/config_schema.o
)

add_dependencies(${PROJECT_NAME} config_schema)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${3RDPARTY_INCLUDES}
)

target_link_libraries(${PROJECT_NAME} ${3RDPARTY_LIBRARIES})

target_compile_definitions(${PROJECT_NAME} PRIVATE 
    -DPROJECT_VERSION="${CMAKE_PROJECT_VERSION}"
    -DRAPIDJSON_HAS_STDSTRING
    -DRAPIDJSON_SCHEMA_USE_INTERNALREGEX=0
)
