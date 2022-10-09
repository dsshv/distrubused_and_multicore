cmake_minimum_required(VERSION 3.23)
project(distrubused_and_multicore C)

set(CMAKE_C_STANDARD 99)

add_executable(distrubused_and_multicore lesson1/helloworld01.c lesson1/programm.c lesson1/programm2.c lesson1/ring.c text_message.c homeworks/homework_1/src/task_1_s.c homeworks/homework_1/src/task_1_p.c homeworks/homework_1/src/task_2.c homeworks/homework_1/src/task_3.c)
