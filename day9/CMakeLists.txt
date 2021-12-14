set(PART1_SRC_FILES
        src/day9part1.c
        src/input.c
        )
set(PART2_SRC_FILES
        src/day9part2.c
        src/input.c
        )
add_executable(day9part1 ${PART1_SRC_FILES})
target_include_directories(day9part1 PUBLIC include)
add_dependencies(day9part1 shared)
target_link_libraries(day9part1 PUBLIC shared)

add_executable(day9part2 ${PART2_SRC_FILES})
target_include_directories(day9part2 PUBLIC include)
add_dependencies(day9part2 shared)
target_link_libraries(day9part2 PUBLIC shared)