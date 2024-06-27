# C:\Libraries\xgboost\lib
# C:\Libraries\xgboost\include
# xgboost
cmake_minimum_required(VERSION 3.18.0)

project(training1 LANGUAGES CXX C)

# set(XGBOOST_DIRECTORY C:/Libraries/xgboost)
set(XGBOOST_DIRECTORY ${CMAKE_SOURCE_DIR}/xgboost)

set(XGBOOST_INCLUDE_DIRECTORY ${XGBOOST_DIRECTORY}/include)
set(XGBOOST_LIB_DIRECTORY ${XGBOOST_DIRECTORY}/lib)

include_directories(${XGBOOST_INCLUDE_DIRECTORY})

link_directories(${XGBOOST_LIB_DIRECTORY})

set(SOURCES main.c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(main ${SOURCES})

target_link_libraries(main xgboost)

set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_custom_command(TARGET main POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${XGBOOST_LIB_DIRECTORY}/xgboost.dll $<TARGET_FILE_DIR:main>)