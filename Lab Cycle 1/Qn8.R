# Function to check if a string is a palindrome
is_palindrome <- function(input_string) {
  # Remove spaces and punctuation, and convert to lowercase
  cleaned_string <- tolower(gsub("[[:space:][:punct:]]", "", input_string))
  
  if (nchar(cleaned_string) == 0) {
    # If there are no alphabetic characters in the cleaned string, return FALSE
    return(FALSE)
  }
  
  # Reverse the cleaned string
  reversed_string <- rev(strsplit(cleaned_string, NULL)[[1]])
  
  # Check if the cleaned string is equal to its reverse
  return(identical(cleaned_string, paste(reversed_string, collapse = "")))
}

# Main program
input_string <- readline("Enter a string to check for palindrome: ")

if (is_palindrome(input_string)) {
  cat("The entered string is a palindrome.\n")
} else {
  cat("The entered string is not a palindrome.\n")
}

cat("Original string: ", input_string, "\n")
if (is_palindrome(input_string)) {
  cat("Reversed string: ", tolower(gsub("[[:space:][:punct:]]", "", input_string)[nchar(input_string):1]), "\n")
}else{
  cat("Reversed string: ", tolower(gsub("[[:space:][:punct:]]", "", input_string)[nchar(input_string):1]), "\n")
}