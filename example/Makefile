BUILDDIR = build

# Если изменили имя теста, то надо изменить его и здесь тоже
TEST_EXEC = $(BUILDDIR)/my_class_test

all: build

build:
	cmake -B$(BUILDDIR) -H.
	$(MAKE) -C $(BUILDDIR)

test: build
	$(TEST_EXEC)

memory: build
	valgrind --leak-check=full $(TEST_EXEC)

format: 
	find . -iname "*.h" -o -iname "*.cpp" | xargs clang-format -i --Werror

lint: 
	cpplint --filter=-legal/copyright,-build/include_subdir --recursive . 

clean:
	$(RM) -r $(BUILDDIR)

.PHONY: all build test memory format lint check clean 
