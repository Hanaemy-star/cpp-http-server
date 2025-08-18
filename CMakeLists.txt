cmake_minimum_required(VERSION 3.10)
project(cpp_http_server)

set(CMAKE_CXX_STANDARD 17)

# Ищем Boost (указываем все нужные компоненты)
find_package(Boost REQUIRED COMPONENTS system asio)

if(Boost_FOUND)
    message(STATUS "Boost include dirs: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost libraries: ${Boost_LIBRARIES}")
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Boost not found!")
endif()

add_executable(cpp_http_server src/main.cpp src/server.cpp)

# Линкуем все нужные компоненты
target_link_libraries(cpp_http_server PRIVATE 
    Boost::boost
    Boost::system
    Boost::asio
    ws2_32  # Добавляем Winsock
)