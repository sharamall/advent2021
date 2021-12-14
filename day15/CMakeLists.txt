set(PART1_SRC_FILES
        src/day15part1.c
        src/input.c
        ../shared/src/shared.c
        )
#set(PART2_SRC_FILES
#        src/day15part2.c
#        src/input.c
#        ../shared/src/shared.c
#        )
add_executable(day15part1 ${PART1_SRC_FILES})
target_include_directories(day15part1 PUBLIC include ../shared/include)
#add_executable(day15part2 ${PART2_SRC_FILES})
#target_include_directories(day15part2 PUBLIC include ../shared/include)