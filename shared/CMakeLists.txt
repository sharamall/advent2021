set(PART1_SRC_FILES
        src/shared.c
        )
add_library(shared STATIC ${PART1_SRC_FILES})
target_include_directories(shared PUBLIC include)