set(PART1_SRC_FILES
        src/day10part1.c
        src/input.c
        )
set(PART2_SRC_FILES
        src/day10part2.c
        src/input.c
        )
add_executable(day10part1 ${PART1_SRC_FILES})
add_dependencies(day10part1 shared)
target_link_libraries(day10part1 PUBLIC shared)
target_include_directories(day10part1 PUBLIC include)

add_executable(day10part2 ${PART2_SRC_FILES})
add_dependencies(day10part2 shared)
target_link_libraries(day10part2 PUBLIC shared)
target_include_directories(day10part2 PUBLIC include)