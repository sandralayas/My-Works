covid <- read.csv('C:/Users/cusat/Documents/Bigdata/dataset/covid.csv')
print(covid)

x <- covid$Confirmed
y <- covid$Deaths

a <- covid$Date

plot(x,y,xlim = c(0,15000),ylim = c(0,1500),xlab = 'date',ylab = 'confirmed')

timeplot <- ts(data = covid,start = 1,end = 125,frequency = 1)
