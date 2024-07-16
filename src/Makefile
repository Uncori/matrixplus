CC = g++
CPPFLAGS = -lgtest -std=c++17
CHECKFLAGS = -Wall -Werror -Wextra

all: matrix_oop.a

test: 
	@${CC} main.cpp matrix_oop.cpp ${CHECKFLAGS} ${CPPFLAGS} -o main
	@./main

%.o: %.cpp
	@${CC} -std=c++17 ${CHECKFLAGS} -c $^

%.a: %.o
	@ar rcs $@ $^
	@ranlib $@

clean:
	@/bin/rm -rf *.o *.a main *.gcno *gcda report *.info main *.out

gcov_report: main.cpp matrix_oop.cpp
	@$(CC) --coverage $^ ${CPPFLAGS} ${CHECKFLAGS} -o main
	@./main
	@lcov -t "main" -o main.info -c -d ./
	@genhtml -o report main.info

style:
	python3 ../materials/linters/cpplint.py --extensions=cpp *.cpp *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem . *.cpp

leaks: test
	CK_FORK=no leaks --atExit -- ./main
