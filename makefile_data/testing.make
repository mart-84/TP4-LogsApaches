TEST_MAIN = $(wildcard Tests/Test*.cpp)
TEST_MAIN_OBJ =$(TEST_MAIN:.cpp=$(SUFFIX).o)
TEST_INT = 
TEST_REAL = $(TEST_INT:.h=.c)
TEST_OBJ = $(TEST_INT:.h=$(SUFFIX).o)
TEST_EXEC = test

ifeq ($(OS), Windows_NT) # Version spéciale Windows
TEST_EXEC := $(TEST_EXEC).exe
BLANK_LINE = $(ECHO).
else
TEST_EXEC := ./$(TEST_EXEC)
BLANK_LINE = $(ECHO)
endif

define TEST_PROC =
$(ECHO).
$(ECHO) Edition des liens pour $@ avec \"$(DISPGCC) $(LDFLAGS) -o $(TEST_EXEC) $(INT:.h=.o) $(TEST_OBJ) $(1) $(LIBS)\"
$(GCC) $(LDFLAGS) -o $(TEST_EXEC) $(INT:.h=$(SUFFIX).o) $(TEST_OBJ) $(1) $(LIBS)
$(ECHO) ======= DEBUT DU $(1:Tests/%.o=%) =======
@$(TEST_EXEC)
$(ECHO) ======= $(1:Tests/%.o=%) REUSSI =======

endef

ifeq ($(TEST_NAME),) # Tous les tests
test test_debug : depend $(OBJ:.o=$(SUFFIX).o) $(TEST_OBJ) $(TEST_MAIN_OBJ)
	$(ECHO) ======= COMPILATION : OK =======
	$(foreach test, $(TEST_MAIN_OBJ), $(call TEST_PROC, $(test)))
	$(BLANK_LINE)
	$(ECHO) ======= $(words $(TEST_MAIN_OBJ)) TESTS REUSSIS =======
else
ifneq ($(wildcard Tests/$(TEST_NAME).cpp),) # Uniquement le test TEST_NAME
test test_debug : depend $(OBJ:.o=$(SUFFIX).o) $(TEST_OBJ) Tests/$(TEST_NAME)$(SUFFIX).o
	$(ECHO) ======= COMPILATION : OK =======
	$(call TEST_PROC, Tests/$(TEST_NAME)$(SUFFIX).o)
else # Aucun test
test test_debug :
	$(ECHO) Le test $(TEST_NAME) n'existe pas
endif
endif

.PHONY: test test_debug