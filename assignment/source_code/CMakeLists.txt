cmake_minimum_required(VERSION 3.16)
project(source_code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(source_code
        include/common.h
        include/cpu.h
        include/loader.h
        include/mem.h
        include/queue.h
        include/sched.h
        include/timer.h
        input/proc/m0
        input/proc/m1
        input/proc/p0
        input/proc/p1
        input/proc/s0
        input/proc/s1
        input/proc/s2
        input/proc/s3
        input/os_0
        input/os_1
        input/sched_0
        input/sched_1
        output/m0
        output/m1
        output/os_0
        output/os_1
        output/sched_0
        output/sched_1
        src/cpu.c
        src/loader.c
        src/mem.c
        src/os.c
        src/paging.c
        src/queue.c
        src/sched.c
        src/timer.c)
