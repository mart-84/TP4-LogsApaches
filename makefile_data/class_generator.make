DATE_FCT = date -d now +%d/%m/%Y
ifeq ($(OS), Windows_NT)
    DATE_FCT = date /T
endif

DATE := $(shell $(DATE_FCT))
YEAR := $(word 3, $(subst /, ,$(DATE)))
EMAIL = $(file < makefile_data$(PS)mail)
AUTEUR = $(file < makefile_data$(PS)auteur)

create_class:
ifeq ($(NAME),)
	$(ECHO) Il faut choisir un nom pour la classe avec l'option NAME=...
else
	@sed "s/XXX/$(NAME)/g" makefile_data$(PS)squelettes$(PS)Xxx.h > $(NAME).h
	@sed -i -e "s/$(NAME)/\U&/g" -e "s/Xxx/$(NAME)/g" -e "s|%DATE%|$(DATE)|g" -e "s/%YEAR%/$(YEAR)/g" -e "s/%EMAIL%/$(EMAIL)/g" -e "s/%AUTHOR%/$(AUTEUR)/g" $(NAME).h
	@sed "s/XXX/$(NAME)/g" makefile_data$(PS)squelettes$(PS)Xxx.cpp > $(NAME).cpp
	@sed -i -e "s/$(NAME)/\U&/g" -e "s/Xxx/$(NAME)/g" -e "s|%DATE%|$(DATE)|g" -e "s/%YEAR%/$(YEAR)/g" -e "s/%EMAIL%/$(EMAIL)/g" -e "s/%AUTHOR%/$(AUTEUR)/g" $(NAME).cpp
	$(ECHO) ======= Classe '$(NAME)' : OK =======
endif

create_test:
ifeq ($(NAME),)
	$(ECHO) "Il faut choisir un nom pour le test avec l'option NAME=..."
else
	@mkdir Tests$(PS)$(NAME)
	$(CP) makefile_data$(PS)squelettes$(PS)Test$(PS)run Tests$(PS)$(NAME)$(PS)run
	$(CP) makefile_data$(PS)squelettes$(PS)Test$(PS)description Tests$(PS)$(NAME)$(PS)description
	$(CP) makefile_data$(PS)squelettes$(PS)Test$(PS)std.out Tests$(PS)$(NAME)$(PS)std.out
	$(CP) makefile_data$(PS)squelettes$(PS)Test$(PS)after Tests$(PS)$(NAME)$(PS)after
	$(CP) makefile_data$(PS)squelettes$(PS)Test$(PS)Test.cpp Tests$(PS)$(NAME)$(PS)Test.cpp
endif

.PHONY: create_class create_test