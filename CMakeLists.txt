cmake_minimum_required(VERSION 2.8.6)

project(RandomSequence)
file(GLOB SRCFILES *.cpp)
file(GLOB INCFILES *.h)
add_executable(RandomSequence ${SRCFILES} ${INCFILES})

enable_testing()
add_test(VerifyUnique RandomSequence verifyunique)
