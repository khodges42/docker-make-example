BUILDFILES = conway.c
EXECUTABLENAME = conway
DOCKERIMAGE = gcc

.PHONY: build devshell run full
devshell:
	docker run -v $(shell pwd):/build -it -w "/build" $(DOCKERIMAGE) bash

build:
	docker run -v $(shell pwd):/build -w "/build" $(DOCKERIMAGE) gcc $(BUILDFILES) -o $(EXECUTABLENAME)

run:
	docker run -v $(shell pwd):/build -w "/build" $(DOCKERIMAGE) ./$(EXECUTABLENAME)

full: build run
