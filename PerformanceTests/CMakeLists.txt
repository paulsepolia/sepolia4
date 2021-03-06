SET(Boost_USE_STATIC_LIBS OFF)
SET(CMAKE_CXX_STANDARD 17)
PROJECT(PERFORMANCE_TESTS_RUN)

#================#
# BOOST settings #
#================#

SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "/opt/boost/1.70.0/include")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "/opt/boost/1.70.0/lib")

FIND_PACKAGE(Boost REQUIRED COMPONENTS unit_test_framework)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

#===============#
# BLAS settings #
#===============#

FIND_PACKAGE(BLAS REQUIRED)

if(BLAS_FOUND)
    INCLUDE_DIRECTORIES(${BLAS_INCLUDE_DIR})
    LINK_DIRECTORIES(${BLAS_LIBRARIES})
else(BLAS_FOUND)
    MESSAGE(FATAL_ERROR "BLAS NOT FOUND")
endif(BLAS_FOUND)

#=================#
# LAPACK settings #
#=================#

FIND_PACKAGE(LAPACK REQUIRED)
if(LAPACK_FOUND)
    INCLUDE_DIRECTORIES(${Lapack_INCLUDE_DIR})
    LINK_DIRECTORIES(${Lapack_LIBRARIES})
else(LAPACK_FOUND)
    MESSAGE(FATAL_ERROR "LAPACK NOT FOUND")
endif(LAPACK_FOUND)

#=====================#
# Executable settings #
#=====================#

ADD_EXECUTABLE(PERFORMANCE_TESTS_RUN
        ../Containers/List/List.h
        ../Containers/Matrix/Matrix.h
        ../Containers/Vector/Vector.h
        UblasPerfTests.cpp ContainersPerfTests.cpp ../Utilities/Clock.cpp ../Utilities/Clock.h)

TARGET_LINK_LIBRARIES(PERFORMANCE_TESTS_RUN ${Boost_LIBRARIES} ${BLAS_LIBRARIES} ${Lapack_LIBRARIES})