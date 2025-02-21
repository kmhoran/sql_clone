set(EXEC sql_exercise)
file(GLOB SOURCES "*.c")
add_executable(${EXEC} ${SOURCES})