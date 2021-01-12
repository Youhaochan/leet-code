cmake_minimum_required (VERSION 2.8)
project (cmake_test)
# 这里是为了enable c++11
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)


##下面语句是确保加入头文件，这样引用头文件才不会报错

find_package(Eigen3 REQUIRED)


#PROJECT_SOURCE_DIR 是根目录的意思
include_directories(
${PROJECT_SOURCE_DIR}/include 
)
include_directories(
${PROJECT_SOURCE_DIR}/lib_func 
)
include_directories(
        include
        ${catkin_INCLUDE_DIRS}
        ${EIGEN3_INCLUDE_DIRS}
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

##第一种增加库并且链接库的方法
set(HEADERS
    include/testfunc.h
    include/class_usage.h
    include/headfile.h
    include/huawei_code.h
    include/leet_code.h
    include/std_practices.h

)

set(SOURCES
  src/testfunc.cpp
  lib_func/huawei_code.cpp
  lib_func/leet_code.cpp
  lib_func/std_practices.cpp
)

set(HEADERS2
    lib_func/func.h
)

set(SOURCES2
  lib_func/func.cpp
  lib_func/pointer.cpp
  lib_func/string_learn.cpp
)
##将俩个头文件链接在一起，这样，.ｍａｉｎ文件就可以调用俩个头文件了
add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${SOURCES2} ${HEADERS2})
add_executable(main src/main.cpp)
add_executable(huawei_code_main src/huawei_code_main.cpp)
add_executable(leet_code_main src/leet_code_main.cpp)
add_executable(std_practices_main src/std_practices_main.cpp)
##如果没有用target_link_libraries　这个语句进行链接不同的库，就会报错说没有定义函数
target_link_libraries(main ${catkin_LIBRARIES}${PROJECT_NAME})
target_link_libraries(huawei_code_main ${catkin_LIBRARIES}${PROJECT_NAME})
target_link_libraries(leet_code_main ${catkin_LIBRARIES}${PROJECT_NAME})
target_link_libraries(std_practices_main ${catkin_LIBRARIES}${PROJECT_NAME})
#有俩种方法来链接一个库。　上面三行代码是一种下面两是一种
#add_library( funcshared SHARED lib_func/func.cpp )
#target_link_libraries (main funcshared)
#add_library( srcshared SHARED src/testfunc.cpp )
#target_link_libraries (main srcshared)


