#!/bin/bash

# Compile all .cpp files except borrow.cpp
g++ -Wall -Wextra -std=c++17 \
    main.cpp inventory.cpp movie.cpp drama.cpp classic.cpp comedy.cpp\
    return.cpp history.cpp command.cpp customer.cpp customerTable.cpp hashtable.cpp \
    inventorycommand.cpp \
    -o movie-store

# Run the program
./movie-store