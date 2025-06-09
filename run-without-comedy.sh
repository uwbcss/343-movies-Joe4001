#!/bin/bash

# Compile all .cpp files except comedy.cpp
g++ -Wall -Wextra -std=c++17 \
    main.cpp inventory.cpp movie.cpp drama.cpp classic.cpp \
    borrow.cpp return.cpp history.cpp command.cpp customer.cpp customerTable.cpp hashtable.cpp \
    inventorycommand.cpp \
    -o movie-store

# Run the program
./movie-store