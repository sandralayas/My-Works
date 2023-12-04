# Q5:  Time Series Visualization. Develop an R program to 
# create a time series plot using real-world data. (https://www.kaggle.com/datasets/niketchauhan/covid-19-time-series-data)
# Plot the time series object  and add a title and label. 
# Customize the plot to show trendlines and seasonal patterns. Discuss the insights gained from the visualization.


covid <- read.csv('C:/Users/cusat/Documents/Bigdata/dataset/covid.csv')
print(covid)

x <- covid$Confirmed
y <- covid$Deaths

a <- covid$Date

plot(x,y,xlim = c(0,15000),ylim = c(0,1500),xlab = 'date',ylab = 'confirmed')

timeplot <- ts(data = covid,start = 1,end = 125,frequency = 1)
