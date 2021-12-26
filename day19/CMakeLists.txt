set(PART1_SRC_FILES
        src/day19part1.c
        src/input.c
        )
#set(PART2_SRC_FILES
#        src/day19part2.c
#        src/input.c
#        )
add_executable(day19part1 ${PART1_SRC_FILES})
target_include_directories(day19part1 PUBLIC include)
target_link_libraries(day19part1 PUBLIC shared)
target_include_directories(day19part1 PUBLIC include)

#add_executable(day19part2 ${PART2_SRC_FILES})
#target_include_directories(day19part2 PUBLIC include)
#target_link_libraries(day19part2 PUBLIC shared)
#target_include_directories(day19part2 PUBLIC include)