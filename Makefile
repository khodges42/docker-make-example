####################################
# Stuff to modify for your project #
####################################

# This is just the docker image. Either one local to you, or from dockerhub.
DOCKERIMAGE = gcc

.PHONY: build shell run full buildlocal runlocal
# The command to build. For things like python, you may not need this step.
buildlocal:
	gcc conway.c -o conway

# The commands to run.
runlocal:
	./conway

######################################################
# The stuff below shouldn't need to be modified much #
######################################################

shell:
	docker run -v $(shell pwd):/build -it -w "/build" $(DOCKERIMAGE) bash

build:
	docker run -v $(shell pwd):/build -w "/build" $(DOCKERIMAGE) make buildlocal

run:
	docker run -v $(shell pwd):/build -w "/build" $(DOCKERIMAGE) make runlocal

full: build run

my_computer_very_hot_oh_god_stop:
	docker run -v $(shell pwd):/build -w "/build" docker make my_computer_very_hot_oh_god_stop