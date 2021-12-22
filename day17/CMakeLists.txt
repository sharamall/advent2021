set(PART1_SRC_FILES
        src/day17part1.c
        src/input.c
        )
#set(PART2_SRC_FILES
#        src/day17part2.c
#        src/input.c
#        )
add_executable(day17part1 ${PART1_SRC_FILES})
target_include_directories(day17part1 PUBLIC include)
target_link_libraries(day17part1 PUBLIC shared)
target_include_directories(day17part1 PUBLIC include)

#add_executable(day17part2 ${PART2_SRC_FILES})
#target_include_directories(day17part2 PUBLIC include)
#target_link_libraries(day17part2 PUBLIC shared)
#target_include_directories(day17part2 PUBLIC include)
