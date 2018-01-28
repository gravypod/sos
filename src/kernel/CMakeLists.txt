cmake_minimum_required (VERSION 2.8.11)
project(kernel)

add_executable(kernel
	./main.c
)

set_target_properties(kernel PROPERTIES
	OUTPUT_NAME "kernel.bin"
	COMPILE_FLAGS "-T${CMAKE_SOURCE_DIR}/src/kernel/link.ld -ffreestanding -nostdlib -static -nostdinc -fno-stack-protector -m32 -march=i386 -mtune=i386"
	LINK_FLAGS    "-T${CMAKE_SOURCE_DIR}/src/kernel/link.ld -ffreestanding -nostdlib -static -nostdinc -fno-stack-protector -m32 -march=i386 -mtune=i386"
)
