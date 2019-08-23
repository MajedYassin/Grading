set(HEADER_LIST "${untitled_SOURCE_DIR}/include/grade.h" "${untitled_SOURCE_DIR}/include/Student_Info.h")

add_library(grading_library read_grade.cpp grade.cpp ${HEADER_LIST})