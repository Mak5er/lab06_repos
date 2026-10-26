CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra

SOURCES = Lab_06_1_it.cpp Lab_06_1_rec.cpp Lab_06_2_it.cpp Lab_06_2_rec.cpp Lab_06_3_it.cpp Lab_06_3_rec.cpp Lab_06_4_it.cpp Lab_06_4_rec.cpp
BINARIES = $(SOURCES:.cpp=)

TEST_SOURCES = $(wildcard tests/UnitTest_*.cpp)
TEST_BINARIES = $(TEST_SOURCES:.cpp=)

all: $(BINARIES)

$(BINARIES): %: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

test: $(TEST_BINARIES)
	@echo "=== Running all unit tests ==="
	@for t in $(TEST_BINARIES); do \
		echo "Running $$t..."; \
		./$$t || exit 1; \
	done
	@echo "All unit tests passed successfully!"

$(TEST_BINARIES): %: %.cpp
	$(CXX) $(CXXFLAGS) -I tests $< -o $@

clean:
	rm -f $(BINARIES) $(TEST_BINARIES)

.PHONY: all test clean
