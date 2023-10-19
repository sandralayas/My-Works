# Function to perform run-length encoding on a string
run_length_encoding <- function(input_string) {
  # Initialize variables
  compressed_string <- ""
  current_char <- ""
  char_count <- 0
  
  # Iterate through the input string
  for (char in strsplit(input_string, NULL)[[1]]) {
    if (char == current_char) {
      # If the current character is the same as the previous one, increment the count
      char_count <- char_count + 1
    } else {
      # If a new character is encountered, append the previous character and its count to the compressed string
      if (char_count > 0) {
        compressed_string <- paste0(compressed_string, current_char, char_count)
      }
      current_char <- char
      char_count <- 1
    }
  }
  
  # Append the last character and its count to the compressed string
  if (char_count > 0) {
    compressed_string <- paste0(compressed_string, current_char, char_count)
  }
  
  return(compressed_string)
}

# Read the input string from the user
input_string <- readline("Enter a string: ")

# Perform run-length encoding
compressed_string <- run_length_encoding(input_string)

# Display the compressed string
cat("Compressed string: ", compressed_string, "\n")
