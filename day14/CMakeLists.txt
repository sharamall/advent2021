set(PART1_SRC_FILES
        src/day14part1.c
        src/input.c
        )
set(PART2_SRC_FILES
        src/day14part2.c
        src/input.c
        )
add_executable(day14part1 ${PART1_SRC_FILES})
target_include_directories(day14part1 PUBLIC include)
target_link_libraries(day14part1 PUBLIC shared)
target_include_directories(day14part1 PUBLIC include)

add_executable(day14part2 ${PART2_SRC_FILES})
target_include_directories(day14part2 PUBLIC include)
target_link_libraries(day14part2 PUBLIC shared)
target_include_directories(day14part2 PUBLIC include)