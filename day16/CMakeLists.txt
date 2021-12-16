set(PART1_SRC_FILES
        src/day16part1.c
        src/input.c
        )
#set(PART2_SRC_FILES
#        src/day16part2.c
#        src/input.c
#        )
add_executable(day16part1 ${PART1_SRC_FILES})
target_include_directories(day16part1 PUBLIC include)
target_link_libraries(day16part1 PUBLIC shared)
target_include_directories(day16part1 PUBLIC include)

#add_executable(day16part2 ${PART2_SRC_FILES})
#target_include_directories(day16part2 PUBLIC include)
#target_link_libraries(day16part2 PUBLIC shared)
#target_include_directories(day16part2 PUBLIC include)
