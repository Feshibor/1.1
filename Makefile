CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wpedantic -fsanitize=address
CLIBS = -lm

SOURCES = laba1functions.c laba1main.c
TEST_SOURCES = laba1functions.c laba1tests.c
EXECUTABLE = laba1
TEST_EXECUTABLE = laba1tests

.PHONY: all test clean unit_test integration_test

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	@$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE) $(CLIBS)

$(TEST_EXECUTABLE): $(TEST_SOURCES)
	@$(CC) $(CFLAGS) $(TEST_SOURCES) -o $(TEST_EXECUTABLE) $(CLIBS)

clean:
	@rm -f $(EXECUTABLE) $(TEST_EXECUTABLE)

unit_test: $(TEST_EXECUTABLE)
	@echo "=== Running unit tests ==="
	@./$(TEST_EXECUTABLE)
	@echo "=== Unit tests completed ==="
	@echo ""

integration_test: $(EXECUTABLE)
	@echo "=== Running integration tests ==="

	@echo "Test 1: Invalid number of arguments"
	@./$(EXECUTABLE) 2>/dev/null && echo "ERROR: Program did not return error" || [ $$? -eq 1 ] && echo "SUCCESS: Correct handling of insufficient arguments"

	@echo ""
	@echo "Test 2: Invalid number input"
	@./$(EXECUTABLE) 123abc -h 2>/dev/null && echo "ERROR: Program did not return error" || [ $$? -eq 1 ] && echo "SUCCESS: Correct handling of invalid number"

	@echo ""
	@echo "Test 3: Invalid flag"
	@./$(EXECUTABLE) 123 -x 2>/dev/null && echo "ERROR: Program did not return error" || [ $$? -eq 1 ] && echo "SUCCESS: Correct handling of invalid flag"

	@echo ""
	@echo "Test 4: Flag -h (multiples)"
	@echo "Subtest 4.1: Number with multiples"
	@./$(EXECUTABLE) 10 -h 2>&1 | grep -q "10 20 30 40 50 60 70 80 90 100" && echo "SUCCESS: Correct multiples output" || echo "ERROR: Incorrect multiples output"
	@echo "Subtest 4.2: Number without multiples"
	@./$(EXECUTABLE) 101 -h 2>&1 | grep -q "no multiples" && echo "SUCCESS: Correct no multiples output" || echo "ERROR: Incorrect no multiples output"

	@echo ""
	@echo "Test 5: Flag -p (prime numbers)"
	@echo "Subtest 5.1: Prime number"
	@./$(EXECUTABLE) 7 -p 2>&1 | grep -q "prime" && echo "SUCCESS: Correct prime detection" || echo "ERROR: Incorrect prime detection"
	@echo "Subtest 5.2: Composite number"
	@./$(EXECUTABLE) 10 -p 2>&1 | grep -q "composite" && echo "SUCCESS: Correct composite detection" || echo "ERROR: Incorrect composite detection"

	@echo ""
	@echo "Test 6: Flag -s (hexadecimal)"
	@./$(EXECUTABLE) 255 -s 2>&1 | grep -q "F F" && echo "SUCCESS: Correct hexadecimal output" || echo "ERROR: Incorrect hexadecimal output"

	@echo ""
	@echo "Test 7: Flag -a (sum)"
	@./$(EXECUTABLE) 5 -a 2>&1 | grep -q "15" && echo "SUCCESS: Correct sum calculation" || echo "ERROR: Incorrect sum calculation"

	@echo ""
	@echo "Test 8: Flag -f (factorial)"
	@./$(EXECUTABLE) 5 -f 2>&1 | grep -q "120" && echo "SUCCESS: Correct factorial calculation" || echo "ERROR: Incorrect factorial calculation"

	@echo ""
	@echo "Test 9: Error handling for overflow"
	@./$(EXECUTABLE) 1e12 -a 2>&1 | grep -q "overflow" && echo "SUCCESS: Correct sum overflow handling" || echo "ERROR: Sum overflow handling failed"
	@./$(EXECUTABLE) 30 -f 2>&1 | grep -q "overflow" && echo "SUCCESS: Correct factorial overflow handling" || echo "ERROR: Factorial overflow handling failed"

	@echo "=== Integration tests completed ==="

test: unit_test integration_test
	@echo ""
	@echo "=== All tests completed successfully! ==="
