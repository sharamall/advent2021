set(PART1_SRC_FILES
        src/day20part1.c
        src/input.c
        )
#set(PART2_SRC_FILES
#        src/day20part2.c
#        src/input.c
#        )
add_executable(day20part1 ${PART1_SRC_FILES})
target_include_directories(day20part1 PUBLIC include)
target_link_libraries(day20part1 PUBLIC shared)
target_include_directories(day20part1 PUBLIC include)

#add_executable(day20part2 ${PART2_SRC_FILES})
#target_include_directories(day20part2 PUBLIC include)
#target_link_libraries(day20part2 PUBLIC shared)
#target_include_directories(day20part2 PUBLIC include)