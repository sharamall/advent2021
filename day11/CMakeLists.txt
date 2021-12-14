set(PART1_SRC_FILES
        src/day11part1.c
        src/input.c
        )
set(PART2_SRC_FILES
        src/day11part2.c
        src/input.c
        )
add_executable(day11part1 ${PART1_SRC_FILES})
target_include_directories(day11part1 PUBLIC include)
target_link_libraries(day11part1 PUBLIC shared)
target_include_directories(day11part1 PUBLIC include)

add_executable(day11part2 ${PART2_SRC_FILES})
target_include_directories(day11part2 PUBLIC include)
target_link_libraries(day11part2 PUBLIC shared)
target_include_directories(day11part2 PUBLIC include)