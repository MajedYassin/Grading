set(HEADER_LIST "${Grading_SOURCE_DIR}/include/grade.h" "${Grading_SOURCE_DIR}/include/Student_Info.h")

add_library(grading_library read_grade.cpp grade.cpp ${HEADER_LIST})
