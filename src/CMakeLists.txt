set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

add_library(main17 STATIC main17.cpp)
add_library(main19 STATIC main19.cpp)

target_include_directories(main17 PUBLIC ${INCLUDE_DIR})
target_include_directories(main19 PUBLIC ${INCLUDE_DIR})

add_executable(main17exec main17.cpp)
target_link_libraries(main17exec main17)
add_executable(main19exec main19.cpp)
target_link_libraries(main19exec main19)
