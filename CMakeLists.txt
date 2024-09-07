cmake_minimum_required(VERSION 3.24)

project(xv6 LANGUAGES C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

macro(t name)
add_executable(${name} ${name}.c)
endmacro()

t(copy)
t(open)
t(fork)
t(exec)
t(forkexec)
t(redirect)
