include_directories(
	${PROJECT_SOURCE_DIR}/sys
)

set(LIB_HEADERS
	sqlite3.h
	sqlite3ext.h
	vData.h
	tSqlite3.h
)
set(LIB_SRCS 
	sqlite3.c
	tSqlite3.cpp
)

add_library(sqlite3 ${LIB_SRCS} ${LIB_HEADERS})

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

set_target_properties(sqlite3 PROPERTIES OUTPUT_NAME "sqlite3")
