# Using Makefiles and Docker for Development

## To Run
`make full` will build the C source (defined in the makefile), and execute it.

If the docker image (also defined in the makefile) isn't on your machine, docker will try to download it.

## How it works
The makefile can be looked at like a series of functions/commands.

`build` and `run` are meant to be run from your computer. They use docker to do work inside of a container (the docker image is defined in the makefile). `make full` just runs both build AND run, to save a command.

The interesting part, is that once the container is spun up, the makefile is then run again inside of the container. This is where `buildlocal` and `runlocal` come into play- they define the actual commands to build and run your project.

## Using this for your own project
Make a copy of the makefile inside of your own project. There are a few things to customize, based on what you're doing.

