file (GLOB HEADERS "*.h")
file (GLOB SOURCES "[^_]*.cpp")

set(LIB libtexrecon)
include_directories(BEFORE /opt/vcpkg/installed/arm64-ios/include /Users/daniel/prj/pkg/oneTBB/include)
add_library(${LIB} ${SOURCES})
set_property(TARGET ${LIB} PROPERTY INTERPROCEDURAL_OPTIMIZATION True)
add_dependencies(${LIB} ext_mve)
install(TARGETS ${LIB} RUNTIME DESTINATION bin)
