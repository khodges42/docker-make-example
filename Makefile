BUILDFILES = conway.c
EXECUTABLENAME = conway
DOCKERIMAGE = gcc

.PHONY: build devshell run full buildlocal runlocal
devshell:
	docker run -v $(shell pwd):/build -it -w "/build" $(DOCKERIMAGE) bash

build:
	docker run -v $(shell pwd):/build -w "/build" $(DOCKERIMAGE) make buildlocal

run:
	docker run -v $(shell pwd):/build -w "/build" $(DOCKERIMAGE) make runlocal

full: build run

buildlocal:
	gcc $(BUILDFILES) -o $(EXECUTABLENAME)

runlocal:
	./$(EXECUTABLENAME)