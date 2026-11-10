SHELL := /bin/zsh

Gomoku: main.cpp Makefile
	time clang++ -Wextra main.cpp -o Gomoku

.PHONY: run
run: Gomoku
	./Gomoku

.PHONY: debug
debug:
	lldb Gomoku

