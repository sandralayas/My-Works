# Load the required libraries
library(tidyverse)
library(lubridate)
library(forecast)

# Load the data
url <- "https://raw.githubusercontent.com/datasets/covid-19/master/data/time-series-19-covid-combined.csv"
covid_data <- read_csv(url)

# Filter the data for India and the required time period
india_data <- covid_data %>%
  filter(Country/Region == "India",
         date >= "2020-01-22",
         date <= "2020-12-15")

# Univariate Time Series Analysis
# Create a time series object for the total positive COVID-19 cases
india_ts <- ts(india_data$Confirmed, frequency = 7)

# Visualize the time series data using a line chart
plot(india_ts, main = "Total Positive COVID-19 Cases in India (22 Jan 2020 - 15 Dec 2020)",
     ylab = "Number of Cases", xlab = "Weeks")

# Multivariate Time Series Analysis
# Create a multivariate time series object that includes both the total positive cases and total deaths
india_multivar_ts <- ts(india_data[, c("Confirmed", "Deaths")], frequency = 7)

# Plot both series on a single chart
plot(india_multivar_ts, main = "Total Positive COVID-19 Cases and Deaths in India (22 Jan 2020 - 15 Dec 2020)",
     ylab = "Number of Cases", xlab = "Weeks")

# Time Series Forecasting
# Use the auto.arima() function from the forecast library to fit an ARIMA model to the total positive cases
india_ts_arima <- auto.arima(india_ts)

# Forecast the next 5 data points
india_ts_forecast <- forecast(india_ts_arima, h = 5)

# Plot the forecasted values
plot(india_ts_forecast, main = "Forecast of Total Positive COVID-19 Cases in India (22 Jan 2020 - 15 Dec 2020)",
     ylab = "Number of Cases", xlab = "Weeks")
