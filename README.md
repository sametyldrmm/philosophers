# Philosophers Problem
This project aims to solve the well-known dining philosophers problem using threads in C language.

## Problem Description
The problem of the dining philosophers consists of five philosophers sitting at a round table with five plates and five forks. They alternate between eating and thinking. In order to eat, each philosopher must have access to the two forks closest to them. However, if a philosopher grabs the fork to their left and the philosopher to their right has already grabbed that fork, they will be stuck waiting forever. The goal of the project is to design a solution that prevents deadlocks and starvation.

## Project Overview
In this project, the solution to the philosophers problem is implemented using threads. The program creates the necessary threads, assigns each philosopher to a thread, and ensures that they can eat and think without causing any deadlocks or starvation.

## Usage
This is a program that solves the dining philosophers problem using threads. The program takes 4 or 5 arguments as inputs:

- Number of philosophers
- Death time of philosophers
- Eating time
- Sleeping time
- Maximum number of meals to be eaten (optional)

## How to compile and run
```
make
./philosophers [number of philosophers] [death time of philosophers] [eating time] [sleeping time] [maximum number of meals (optional)]
./philosophers 5 30 100 200 5
```
This command runs the program with 5 philosophers, each with a death time of 30 seconds, an eating time of 100 milliseconds, a sleeping time of 200 milliseconds, and a maximum of 5 meals.



