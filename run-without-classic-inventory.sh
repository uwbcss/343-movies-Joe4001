#!/bin/bash

# Compile all .cpp files except classic.cpp and inventorycommand.cpp
g++ -Wall -Wextra -std=c++17 \
    main.cpp inventory.cpp movie.cpp drama.cpp comedy.cpp\
    return.cpp history.cpp command.cpp customer.cpp customerTable.cpp hashtable.cpp \
    borrow.cpp\
    -o movie-store

# Run the program
./movie-store