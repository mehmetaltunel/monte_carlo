MONTE CARLO SIMULATION ASSIGNMENT
================================

This assignment models bank customer service times using random number generation and Monte Carlo simulation.

FILES
-----
1. monte_carlo.c - Monte Carlo simulation for 100 customers
2. monte_carlo_extended.c - Extended Monte Carlo simulation for 1000 customers
3. README.txt - This file (Turkish version)
4. README_EN.txt - This file (English version)
5. REPORT.txt - Detailed report (Turkish version)
6. REPORT_EN.txt - Detailed report (English version)

COMPILER INFORMATION
-------------------
These programs were developed using the GCC compiler.
GCC version used: gcc (GCC) 11.3.0

COMPILATION INSTRUCTIONS
-----------------------
You can use the following commands to compile the programs:

For 100 customer simulation:
```
gcc -o monte_carlo monte_carlo.c -lm
```

For extended 1000 customer simulation:
```
gcc -o monte_carlo_extended monte_carlo_extended.c -lm
```

EXECUTION INSTRUCTIONS
---------------------
To run the compiled programs:

For 100 customer simulation:
```
./monte_carlo
```

For extended 1000 customer simulation:
```
./monte_carlo_extended
```

PROGRAM DESCRIPTION
------------------
These programs perform the following operations:

1. Generate uniformly distributed random numbers (between 0.0-1.0).
2. Convert these random numbers to service times with specific probabilities:
   - Ts-1 (4 minutes): 35% probability
   - Ts-2 (8 minutes): 50% probability
   - Ts-3 (12 minutes): 15% probability
3. Display the random number generated and the assigned service time for each customer.
4. Calculate and display how many times each service time type was generated and its percentage at the end of the simulation.
5. In the extended version, compare actual results with expected values and show deviation analysis.

NOTES
-----
- The programs will produce different results each time they are run because the random number generator is initialized with srand(time(NULL)).
- In the extended version, detailed output is shown only for the first 100 customers, but statistics are calculated for all 1000 customers.
- The programs should be compiled with the -lm flag as they use the math.h library. 