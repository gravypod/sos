cmake_minimum_required (VERSION 2.8.11)
project(sos)


# Setup build configuration
set_target_properties(${modules}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build"
)

# Include modules
set(modules kernel)
foreach(module ${modules})
	message(STATUS "LOADING MODULE ${module}")
	add_subdirectory("${CMAKE_SOURCE_DIR}/src/${module}")
	message(STATUS "	DONE")
endforeach()

# Build ISO
add_custom_target(sos ALL
	COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/os/boot"
	COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/src/grub.cfg" "${CMAKE_BINARY_DIR}/os/boot"
	COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_BINARY_DIR}/src/kernel/kernel.bin"   "${CMAKE_BINARY_DIR}/os/boot"
	COMMAND grub-mkrescue -o "${CMAKE_BINARY_DIR}/sos.iso" "${CMAKE_BINARY_DIR}/os/"
	DEPENDS ${modules}
)
