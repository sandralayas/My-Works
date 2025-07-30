# Function to reverse a list using recursion
reverse_list <- function(lst) {
  if (length(lst) == 0) {
    return(list())
  } else {
    return(c(reverse_list(tail(lst, -1)), head(lst, 1)))
  }
}

# Function to convert a list to a character string
list_to_string <- function(lst) {
  return(paste(lst, collapse = ", "))
}

# Main program
input_string <- readline("Enter a list of numbers separated by commas: ")
input_list <- strsplit(input_string, ",")[[1]]

# Convert character elements to numeric (if needed)
input_list <- as.numeric(input_list)

if (is.na(input_list[1])) {
  cat("Invalid input. Please enter a list of numbers separated by commas.\n")
} else {
  cat("Original list: ", list_to_string(input_list), "\n")
  reversed_list <- reverse_list(input_list)
  cat("Reversed list: ", list_to_string(reversed_list), "\n")
}
