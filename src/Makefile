FLAGS=-Werror -Wextra -Wall -I/opt/homebrew/Cellar/check/0.15.2/include
SOURCE=$(wildcard sourceFiles/*.c)
GCOV=-fprofile-arcs -ftest-coverage

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    LCHECK=-L/opt/homebrew/Cellar/check/0.15.2/lib -lcheck
else ifeq ($(filter Ubuntu, $(OS)), Ubuntu)
    LCHECK=-lcheck -lsubunit -lm
else ifeq ($(filter Manjaro, $(OS)), Manjaro)
    LCHECK=-lcheck -lm
else
    LCHECK=-lcheck -lm
endif

OBJ_DIR=obj
GCD_DIR=gcdFiles
REP_DIR=report_html
OBJ_FILES=$(patsubst sourceFiles/%.c,$(OBJ_DIR)/%.o,$(SOURCE))

all: s21_math.a test gcov_report

s21_math.a: $(OBJ_FILES)
	ar rc s21_math.a $(OBJ_FILES)

$(OBJ_DIR)/%.o: sourceFiles/%.c | $(OBJ_DIR)
	gcc $(FLAGS) -c $< -o $@

test: s21_math.a
	gcc $(FLAGS) s21_math_test.c s21_math.a -o s21_math_test $(LCHECK)
	./s21_math_test

gcov_report: s21_math.a
	gcc $(FLAGS) s21_math_test.c $(SOURCE) -o s21_math_test $(LCHECK) $(GCOV)
	./s21_math_test
	mkdir -p $(REP_DIR)
	lcov --capture --directory . --output-file $(REP_DIR)/report.info
	genhtml $(REP_DIR)/report.info -o $(REP_DIR)
	mkdir -p $(GCD_DIR)
	mv *.gcda *.gcno $(GCD_DIR)

rebuild: clean all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(GCD_DIR) $(REP_DIR) *.info s21_math_test s21_math.a $(OBJ_DIR)


#.PHONY: all test gcov_report rebuild clean
