DISPGCC = g++
GCC = @$(DISPGCC)
CFLAGS = -g -Wall -ansi -pedantic -std=c++11 -Ilib
LDFLAGS = -g -Wall
LIBS =
SUFFIX = 
ifneq ($(findstring debug, $(MAKECMDGOALS)),)
SUFFIX =.d
CFLAGS := $(CFLAGS) -DMAP
endif

MAIN = main
EXEC = analog
INT = LigneLog.h AnalyseurLogs.h Statistiques.h GenerateurGraphe.h Controleur.h VerificateurCommande.h
REAL = $(INT:.h=.c)
OBJ = $(INT:.h=.o) $(MAIN).o

PS = /
RM = @rm -rf
CP = @cp
MV = @mv
ECHO = @echo
MEMCHECK = @valgrind --leak-check=full
NULL_FILE = /dev/null # Utile pour la redirection de sortie
DEPENDENCIES_FOLDER = makefile_data/dependencies/%.make

ifeq ($(OS), Windows_NT) # Version spéciale Windows
EXEC := $(EXEC).exe
PS = \\
RM = @del /Q /F /S
CP = @copy
MV = @move
MEMCHECK = @drmemory -batch
NULL_FILE = nul
DEPENDENCIES_FOLDER = makefile_data\\dependencies\\%.make
else
EXEC := ./$(EXEC)
endif


all debug : $(EXEC)
	$(ECHO) ======= BUILD : OK =======


$(EXEC) : depend $(OBJ:.o=$(SUFFIX).o)
	$(ECHO) ======= COMPILATION : OK =======
	$(ECHO) Edition des liens pour $@ avec \"$(DISPGCC) $(LDFLAGS) -o $@ $(OBJ:.o=$(SUFFIX).o) $(LIBS)\"
	$(GCC) $(LDFLAGS) -o $@ $(OBJ:.o=$(SUFFIX).o) $(LIBS)
	$(ECHO) ======= LINK EDITION : OK =======

%.o %$(SUFFIX).o : %.cpp
	$(ECHO) Compilation pour $@ avec \"$(DISPGCC) $(CFLAGS) -o $@ -c $<\"
	$(GCC) $(CFLAGS) -o $@ -c $<


# Cibles spéciales qui ne correspondent pas à des fichiers
.PHONY : all debug run memcheck rebuild clean clear full_clean depend test

rebuild : clean all

run:
ifneq ($(wildcard $(EXEC)), )
	$(ECHO) ======= RUN EXEC =======
	@$(EXEC)
else
	$(ECHO) Le fichier executable n'existe pas.
endif

memcheck:
	$(MEMCHECK) $(EXEC)

clean clear :
	$(RM) $(EXEC) $(OBJ) $(OBJ:.o=.d.o) $(TEST_EXEC) $(TEST_OBJ) $(TEST_OBJ:.o=.d.o) \
		$(subst /,$(PS),$(TEST_MAIN_OBJ)) $(subst /,$(PS),$(TEST_MAIN_OBJ:.o=.d.o)) core \
		bin$(PS)$(EXEC) > $(NULL_FILE) 2>&1
	$(ECHO) ======= CLEANING : OK =======

full_clean: clean
	$(RM) makefile_data$(PS)dependencies > $(NULL_FILE) 2>&1

test: all
	$(ECHO) ======= STARTING TESTS =======
	cd Tests; ./mktest.sh


ifneq ($(findstring create, $(MAKECMDGOALS)),)
-include makefile_data$(PS)class_generator.make
endif

# Gestion des #include entre .cpp et h.
# Crée des fichiers .make dans le dossier dependencies qui sont ensuite inclus dans ce makefile principal
# Il n'est plus nécessaire de noter les règles de dépendance à la main
ifeq ($(findstring clean, $(MAKECMDGOALS)),)
-include $(OBJ:%.o=$(DEPENDENCIES_FOLDER))
endif

depend : $(OBJ:%.o=$(DEPENDENCIES_FOLDER))
	$(ECHO) ======= DEPENDENCIES : OK =======

$(DEPENDENCIES_FOLDER) : %.cpp
	$(ECHO) Generation des dependances de $<
	-@mkdir makefile_data > $(NULL_FILE) 2>&1 ||:
	-@mkdir makefile_data$(PS)dependencies > $(NULL_FILE) 2>&1 ||:
	-$(RM) "$@"  > $(NULL_FILE) 2>&1
	$(GCC) -MM $< > "$@.tmp"
	@sed "s,\($*\)\.o[ :]*,\1.o \1.make \1.d.o : ,g" < "$@.tmp" > "$@"
	-$(RM) "$@.tmp" > $(NULL_FILE) 2>&1
