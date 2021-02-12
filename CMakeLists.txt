cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(DogGraphicDisplay_project)

pico_sdk_init()
add_executable(DogGraphicDisplayPico
	DogGraphicDisplayPico.cpp
	DogGraphicDisplay.cpp
)

pico_enable_stdio_usb(DogGraphicDisplayPico 1)

pico_enable_stdio_uart(DogGraphicDisplayPico 1)

pico_add_extra_outputs(DogGraphicDisplayPico)

target_link_libraries(DogGraphicDisplayPico pico_stdlib hardware_spi)
