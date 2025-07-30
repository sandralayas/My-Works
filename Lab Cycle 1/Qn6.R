# Define a function to check if a number is prime
is_prime <- function(number) {
  if (number <= 1) {
    return(FALSE)
  }
  if (number <= 3) {
    return(TRUE)
  }
  if (number %% 2 == 0 || number %% 3 == 0) {
    return(FALSE)
  }
  i <- 5
  while (i * i <= number) {
    if (number %% i == 0 || number %% (i + 2) == 0) {
      return(FALSE)
    }
    i <- i + 6
  }
  return(TRUE)
}

# Define a function to print all prime numbers up to a given number
print_primes_until <- function(number) {
  for (i in 2:number) {
    if (is_prime(i)) {
      print(paste(i, "is a prime number"))
    }
  }
}

x1 <- readline("Enter any number: ")
y1 <- as.integer(x1)

# Check if the input is a valid integer
if (!is.na(y1)) {
  print_primes_until(y1)
} else {
  cat("Invalid input. Please enter a valid integer.\n")
}
