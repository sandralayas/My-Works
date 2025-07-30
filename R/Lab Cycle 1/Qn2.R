# Function to encrypt a sentence using a Caesar cipher
caesar_cipher <- function(sentence, shift) {
  # Define the alphabet in both uppercase and lowercase
  alphabet <- c(letters, LETTERS)
  
  # Create a function to shift a character by a specified amount
  shift_char <- function(char, shift) {
    if (char %in% alphabet) {
      # Determine the case of the character (lowercase or uppercase)
      is_upper <- char %in% LETTERS
      alphabet_start <- ifelse(is_upper, "A", "a")
      
      # Calculate the new position after shifting
      char_index <- which(alphabet == char)
      new_pos <- (char_index + shift - which(alphabet == alphabet_start)) %% 26 + 1
      
      # Return the shifted character while maintaining the case
      if (is_upper) {
        return(LETTERS[new_pos])
      } else {
        return(letters[new_pos])
      }
    } else {
      return(char)  # Character is not in the alphabet, so don't shift it
    }
  }
  
  # Apply the shift_char function to each character in the sentence
  encrypted_sentence <- sapply(unlist(strsplit(sentence, NULL)), function(char) shift_char(char, shift))
  
  # Combine the characters back into a single string
  encrypted_sentence <- paste(encrypted_sentence, collapse = "")
  
  return(encrypted_sentence)
}

# Read the sentence and shift value from the user
sentence <- readline("Enter a sentence: ")
shift <- as.integer(readline("Enter the shift value: "))

# Encrypt the sentence
encrypted_sentence <- caesar_cipher(sentence, shift)

# Display the encrypted sentence
cat("Encrypted sentence: ", encrypted_sentence, "\n")
