#Qn1:Data types and manipulation
#Develop a program to read a a paragraph of text and perform:
#a.Count the total number of words
#b.Calculate the average word length
#c.IDENTIFY AND PRINT THE LONGEST WORD.
#D.Replace all occurences of a specific word with another word of your choice.

# Read the content of the file
file_path <- "C:/Users/cusat/Desktop/R programs/readline.txt"
my_text <- readLines(file_path)

# Remove leading and trailing white space
my_after_text <- trimws(my_text)

#print the paragraph
print(paste(my_after_text))

#count the number of words
number_of_words=lengths(gregexpr("\\w+", my_text))
print(paste("Number of words in a paragraph:",number_of_words))

#count the number of letters
number_of_letters=nchar(my_text)
print(paste("Number of letters in a paragraph:",number_of_letters))

average = number_of_letters/ number_of_words

print(paste("Average word length:",average))

#length of largest word and print the same
words<-unlist(strsplit(my_text,"\\s+"))
word_length<-nchar(words)
index_longest_word<-which.max(word_length)
longest_word<-words[index_longest_word]
cat("\nLongest word among the text file is:",longest_word,"\n")

# Get user input for word to replace
word_to_replace <- readline(prompt = "Enter the word to replace: ")

# Get user input for replacement word
replacement_word <- readline(prompt = "Enter the replacement word: ")

# Replace all occurrences of the word in each line of the file content
modified_text <- gsub(word_to_replace, replacement_word, my_text)

# Print the modified text
cat("Modified content:\n")
cat(modified_text, sep = "\n")