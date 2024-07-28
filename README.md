# Features
File output  
LCM of 1 to n  
List primes up to n  
# Benchmarks
n = 10 million in 10 seconds  
n = 100 million in 10 minutes  
# Requirements
https://gmplib.org/  
Debian  
`sudo apt-get install libgmp-dev`  
Mac  
`brew install gmp`  
# Build instructions
`gcc main.c findPrimes.c input.c multiplication.c -lgmp`
# To do
Current bottleneck is in multiplication  
Use threads  
Implement the sieve of Atkin  
