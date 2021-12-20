set(PART1_SRC_FILES
        src/day18part1.c
        src/input.c
        )
set(PART2_SRC_FILES
        src/day18part2.c
        src/input.c
        )
add_executable(day18part1 ${PART1_SRC_FILES})
target_include_directories(day18part1 PUBLIC include)
target_link_libraries(day18part1 PUBLIC shared)
target_include_directories(day18part1 PUBLIC include)

add_executable(day18part2 ${PART2_SRC_FILES})
target_include_directories(day18part2 PUBLIC include)
target_link_libraries(day18part2 PUBLIC shared)
target_include_directories(day18part2 PUBLIC include)