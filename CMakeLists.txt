cmake_minimum_required(VERSION 3.20)  
project(cpp_http_server)  

set(CMAKE_CXX_STANDARD 20)   
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pthread")   

# Подключаем Boost  
find_package(Boost REQUIRED COMPONENTS system)  

# Собираем сервер  
add_executable(server src/main.cpp)  
target_link_libraries(server PRIVATE Boost::system pthread) 