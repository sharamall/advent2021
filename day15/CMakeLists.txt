set(PART1_SRC_FILES
        src/day15part1.c
        src/input.c
        )
set(PART2_SRC_FILES
        src/day15part1.c
        src/day15part2.c
        )
add_executable(day15part1 ${PART1_SRC_FILES})
target_include_directories(day15part1 PUBLIC include)
target_link_libraries(day15part1 PUBLIC shared)
target_include_directories(day15part1 PUBLIC include)

add_executable(day15part2 ${PART2_SRC_FILES})
target_include_directories(day15part2 PUBLIC include)
target_link_libraries(day15part2 PUBLIC shared)
target_include_directories(day15part2 PUBLIC include)