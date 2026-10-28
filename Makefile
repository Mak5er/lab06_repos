CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra

TEST_SRCS = $(wildcard tests/UnitTest_*.cpp)
TEST_BINS = $(TEST_SRCS:.cpp=)

LAB_SRCS = $(wildcard Lab_*.cpp)
LAB_BINS = $(LAB_SRCS:.cpp=)

.PHONY: all labs tests test clean

all: labs tests

labs: $(LAB_BINS)

tests: $(TEST_BINS)

Lab_%: Lab_%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

tests/UnitTest_%: tests/UnitTest_%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

test: tests
	@for t in $(TEST_BINS); do \
		echo "===> Running $$t <==="; \
		$$t || exit 1; \
	done

clean:
	rm -f $(LAB_BINS) $(TEST_BINS)
