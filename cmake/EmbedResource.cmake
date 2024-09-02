macro(embed_resource TARGET_NAME INPUT)
        set(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}.o)
        add_custom_target(
                ${TARGET_NAME}
                DEPENDS ${OUTPUT}
        )
        add_custom_command(
                OUTPUT ${OUTPUT}
                COMMAND ${CMAKE_LINKER} --relocatable --format binary --output ${OUTPUT} ${INPUT}
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                DEPENDS ${INPUT}
        )
endmacro()