# Question 5 ; String

def get_substring(word):
  list_of_strings=[]
  for i in range(len(word)):
    for j in range(len(word)):
      list_of_strings.append(word[j:])  # Appends the sliced string to list_of_strings
    word=word[:len(word)-1]   # Remove the last character from the word  
  return list_of_strings  # Returns the list

def print_palindrome(word):
  for i in get_substring(word):  # Takes each substring
    if i==i[::-1]:print(i,end=' ')   # Checks if its palindrome

def word_length(word,length):
  for i in get_substring(word):  # Takes each substring
    if len(i)==length:print(i,end=' ')   # Checks if its of the given length

def print_length_distinct(word,length):
  for i in get_substring(word):  # Takes each substring
    if len(i)==length:   # Checks if its of the given length
      if len(set(i))==len(i):print(i,end=' ')   # Checks if its distinct


word=input( 'Enter the string :')

print('\n All the sub strings')

for i in get_substring(word):print(i,end=' ')

length=int(input('\n\nEnter the length : '))

print('\n Substrings of length',length) 
word_length(word,length)
print('\n\n Substrings of length',length,'which only have distinct character') 
print_length_distinct(word,length)
print('\n\n Palindromes :')
print_palindrome(word)
