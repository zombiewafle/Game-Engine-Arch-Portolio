cmake_minimum_required(VERSION 3.23)

project(GAME VERSION 1.0)

# Enable C++20 features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# message(STATUS "SDL2_IMAGE_LIBRARIES: ${SDL2_IMAGE_LIBRARIES}")


# Añadiendo la ruta de vcpkg al PREFIX_PATH para que CMake pueda encontrar los paquetes instalados por vcpkg
list(APPEND CMAKE_PREFIX_PATH "/home/zombiewafle/vcpkg/installed/x64-linux/share")

# Encontrar y vincular la librería EnTT
find_package(EnTT CONFIG REQUIRED)

# Encontrar y vincular la librería SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Encontrar y vincular la biblioteca glm
find_package(glm CONFIG REQUIRED)

find_package(SDL2_image 2.0.5 REQUIRED)  # Asume que estás usando la versión 2.0.5; ajusta según sea necesario
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

# Encontrar la biblioteca sol2
find_package(sol2 CONFIG REQUIRED)

# Encontrar y vincular la librería SDL2_image
# find_package(SDL2_image REQUIRED)
# include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
message(STATUS "LUA_LIBRARIES: ${LUA_LIBRARIES}")

set(SDL2_IMAGE_LIBRARIES "/usr/lib/libSDL2_image.so")



# Encontrar y vincular la librería Lua
find_package(Lua REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(${PROJECT_NAME}
    src/main.cpp
    ${SOURCES}
)

# Modifica tus directorios include
target_include_directories(${PROJECT_NAME}
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
        ${GLM_INCLUDEDIR} 
        ${SDL2_IMAGE_INCLUDE_DIRS}  # Añade el directorio include de SDL2_image
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/src
)

# Enlaza las bibliotecas
target_link_libraries(${PROJECT_NAME}
    ${SDL2_IMAGE_LIBRARIES}
    SDL2
    ${LUA_LIBRARIES}
    EnTT::EnTT # Añadido para vincular la librería EnTT
    sol2
)

