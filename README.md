This repository contains the challenge benchmarks used to evaluate our program synthesis tool. 

There are three directories, each representing an algorithm. Inside the directories are various challenges, with differing numbers representing differing holes. The suffixes `none`, `some`, and `all` refer to the level of hints given at the corresponding holes. The header file `pliny_fill.h` provides information on how to interpret the holes.

The donor code used for synthesis is present in the corresponding `results` directory. The `wrapped_tests.py` represents the test cases.