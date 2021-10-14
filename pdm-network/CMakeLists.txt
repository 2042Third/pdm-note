#if (WIN32)
#    include_directories(lib/)
#    link_directories(include/)
#elseif (APPLE)
#    include_directories(lib_mac/)
#    link_directories(include_mac/)
#elseif (UNIX)
#    include_directories(lib_linux/)
#    link_directories(include_linux/)
#endif ()

set(CURL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
#set(CURL_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CURL_LIBRARY "-lcurl")
#add_library( curl SHARED IMPORTED )
#add_definitions("-DCURL_STATICLIB")

#find_package(curl REQUIRED)
#SET_PROPERTY(TARGET curl PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/libcurl.dll.a)
#include(${CURL_INCLUDE_DIRS})

include_directories(${CURL_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(pdm-network
        pdm-network.h
        pdm-network.cpp)
target_compile_options(
        pdm-network PRIVATE
        -m64

)
if(WIN32)
    target_link_libraries(pdm-network ${CMAKE_CURRENT_SOURCE_DIR}/lib/libcurl.dll.a ${CURL_LIBRARIES} )
endif()


target_include_directories(pdm-network PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
