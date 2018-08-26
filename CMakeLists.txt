cmake_minimum_required ( VERSION 3.1 )

project ( lig-image )

### Modules
set     ( CMAKE_MODULE_PATH   ${PROJECT_SOURCE_DIR}/cmake )

include ( BuildLocation )

### Compile Commands (for vim, YouCompleteMe and other cpp plugins) 
set ( CMAKE_EXPORT_COMPILE_COMMANDS   ON )

if( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
  execute_process( COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    )
endif()

### Configuration
set ( CMAKE_CXX_STANDARD 11 )


### Targets
file (
	GLOB
	LIBIMAGE_SRC
	src/*.cpp
)

list (
	APPEND
	LIBIMAGE_INCLUDE_DIRS
	${CMAKE_SOURCE_DIR}/include/
)

add_library (
	image
	STATIC
	${LIBIMAGE_SRC}
)

target_include_directories (
	image
	PRIVATE
	${LIBIMAGE_INCLUDE_DIRS}
)

