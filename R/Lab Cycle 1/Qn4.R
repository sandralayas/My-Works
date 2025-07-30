generate_random_password <- function(length) {
  uppercase_chars <- LETTERS
  lowercase_chars <- letters
  digit_chars <- 0:9
  special_chars <- c('!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+', '=', '[', ']', '{', '}', '<', '>', '?')
  
 
  all_chars <- c(uppercase_chars, lowercase_chars, digit_chars, special_chars)
  
  
  password <- sample(all_chars, length, replace = TRUE)
  
  return(paste(password, collapse = ''))
}


length <- as.integer(readline("Enter the length of the password: "))

if (is.na(length) || length <= 0) {
  cat("Please enter a positive integer for the password length.\n")
} else {
  random_password <- generate_random_password(length)
  cat("Generated random password:", random_password, "\n")
}
