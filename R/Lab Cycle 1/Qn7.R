
# Function to generate and print the Fibonacci-like series
generate_and_print_series <- function(num_terms) {
  series <- numeric(num_terms) 
  
  
  series[1] <- 0
  series[2] <- 1
  series[3] <- 1
  
  # Print the Fibonacci-like series
  cat("Fibonacci-like series with", num_terms, "terms:\n")
  cat(series[1], series[2], series[3])
  
  # Generate and print the Fibonacci-like series 
  for (i in 4:num_terms) {
    series[i] <- series[i - 1] + series[i - 2] + series[i - 3]
    cat(" ", series[i]) 
  }
  cat("\n")
}


generate_and_print_fibonacci <- function(num_terms) {
  fibonacci_series <- numeric(num_terms)  
  
  
  fibonacci_series[1] <- 0
  fibonacci_series[2] <- 1
  
  # Print the actual Fibonacci series
  cat("Actual Fibonacci series with", num_terms, "terms:\n")
  cat(fibonacci_series[1], fibonacci_series[2])
  
 
  for (i in 3:num_terms) {
    fibonacci_series[i] <- fibonacci_series[i - 1] + fibonacci_series[i - 2]
    cat(" ", fibonacci_series[i])  # Print each term separated by a space
  }
  cat("\n")
}


num_terms <- as.integer(readline("Enter the number of terms: "))

if (is.na(num_terms) || num_terms <= 0) {
  cat("Please enter a positive integer for the number of terms.\n")
} else {
  generate_and_print_series(num_terms)
  generate_and_print_fibonacci(num_terms)
}
