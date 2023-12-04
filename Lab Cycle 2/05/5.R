# Q5:  Time Series Visualization. Develop an R program to 
# create a time series plot using real-world data. (https://www.kaggle.com/datasets/niketchauhan/covid-19-time-series-data)
# Plot the time series object  and add a title and label. 
# Customize the plot to show trendlines and seasonal patterns. Discuss the insights gained from the visualization.


covid <- read.csv('covid.csv')

x <- covid$Recovered 
y <- covid$Deaths
z <- covid$Confirmed

a <- covid$Date
k <- 10000

timeplot <- ts(data = covid,start = 1,end = 125,frequency = 52)

plot(timeplot,xlab = 'Weekly data')
