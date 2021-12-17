set(PART1_SRC_FILES
        src/day13part1.c
        src/input.c
        )
set(PART2_SRC_FILES
        src/day13part2.c
        src/input.c
        )
add_executable(day13part1 ${PART1_SRC_FILES})
target_include_directories(day13part1 PUBLIC include)
target_link_libraries(day13part1 PUBLIC shared)
target_include_directories(day13part1 PUBLIC include)

add_executable(day13part2 ${PART2_SRC_FILES})
target_include_directories(day13part2 PUBLIC include)
target_link_libraries(day13part1 PUBLIC shared)
target_include_directories(day13part1 PUBLIC include)