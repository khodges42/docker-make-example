BUILDFILES = conway.c
EXECUTABLENAME = conway

.PHONY: build devshell run full
devshell:
	docker run -v $(shell pwd):/build -it -w "/build" gcc bash

build:
	docker run -v $(shell pwd):/build -w "/build" gcc gcc $(BUILDFILES) -o $(EXECUTABLENAME)

run:
	docker run -v $(shell pwd):/build -w "/build" gcc ./$(EXECUTABLENAME)

full: build run
