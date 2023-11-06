#Create a histogram of the miles per gallon (mpg) in the mtcars dataset. Use different shades of blue to represent the frequency of each bin. Add appropriate title and labels to the plot. Calculate and display the mean and standard deviation of mpg on the plot.
# Load the ggplot2 library

library(ggplot2)

# Create a histogram of 'mpg' with different shades of blue
mpg_histogram <- ggplot(mtcars, aes(x = mpg)) +
  geom_histogram(binwidth = 3, fill = "#00FFFF", color = "#004466") +  # Use shades of blue
  labs(
    title = "Histogram of Miles Per Gallon (mpg)",
    x = "Miles Per Gallon (mpg)",
    y = "Frequency"
  ) +
  theme_minimal()

# Calculate mean and standard deviation of mpg
mean_mpg <- mean(mtcars$mpg)
std_dev_mpg <- sd(mtcars$mpg)

# Add mean and standard deviation to the plot
mpg_histogram +
  geom_text(aes(label = paste("Mean =", round(mean_mpg, 2), "\nSD =", round(std_dev_mpg, 2)),
                x = mean_mpg, y = 10, vjust = -1, hjust = 0.5, color = "red"))
            
            
