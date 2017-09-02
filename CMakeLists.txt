cmake_minimum_required(VERSION 3.7)
project(BaekJoonAlgorithms)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp pro2448.h pro2448.h pro10828.h pro1874.h pro9012.h pro2504.h pro10845.h pro1260.h pro1966.h pro11866.h pro1152.h pro2577.h pro8958.h pro2920.h pro10039.h pro10866.h pro2750.h pro2751.h pro1021.h pro5430.h pro11718.h pro9426.h pro2747.h pro2748.h pro1003.h pro11050.h pro11051.h pro11401.h pro14627.h pro1920.h pro1654.h pro1629.h pro1427.h pro3344.h pro10872.h pro1932.h pro2749.h pro1676.h pro2407.h pro6591.h pro9375.h pro2579.h pro1149.h pro2580.h pro2098.h pro1780.h pro1725.h pro9663.h pro11047.h pro1931.h pro11723.h pro9997.h pro2003.h pro2096.h pro11003.h pro11724.h pro4963.h pro1991.h pro9237.h pro2970.h pro1058.h pro1197.h pro1922.h pro1753.h pro1719.h pro2468.h pro1697.h pro2042.h pro1261.h pro10868.h pro2357.h pro1600.cpp pro11404.h pro1389.h pro1012.h pro9466.h pro1937.h pro4485.h pro6118.h pro2931.h pro9370.h pro1463.h pro1005.h pro1992.h pro1074.h pro6593.h pro9461.h pro14501.h pro11657.h)
add_executable(BaekJoonAlgorithms ${SOURCE_FILES})




set(BOOST_ROOT "/Users/joonyoungjeon/CLionProjects/boost_1_64_0")

cmake_minimum_required(VERSION 2.8.4)


message(STATUS "start running cmake...")

find_package(Boost 1.64.0 COMPONENTS REQUIRED)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})

endif()

