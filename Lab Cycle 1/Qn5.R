# Function to calculate the sum of the series
calculate_series_sum <- function(num_terms) {
  series_sum <- 0
  numerator <- 1
  denominator <- 1
  sign <- 1  # Initialize sign to positive
  
  for (i in 1:num_terms) {
    term <- sign * (numerator / denominator)
    series_sum <- series_sum + term
    
    numerator <- numerator + 1
    denominator <- denominator + 2
    sign <- -sign 
  }
  
  return(series_sum)
}

# Main program
num_terms <- as.integer(readline("Enter the number of terms in the series: "))

if (is.na(num_terms) || num_terms <= 0) {
  cat("Invalid input. Please enter a positive integer for the number of terms.\n")
} else {
  series_sum <- calculate_series_sum(num_terms)
  cat("The sum of the series with", num_terms, "terms is:", series_sum, "\n")
}