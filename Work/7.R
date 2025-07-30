sentence  <- readline('Enter the sentence : ')
cat('The lenght of the sentence is',nchar(sentence),'\n')
cat('The first five charecters are :',substr(sentence,1,5),'\n')
cat('The last five charecters are :',substr(sentence,nchar(sentence)-5,nchar(sentence)))