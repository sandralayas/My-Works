#Q1: Create a bar plot of the number of cylinders (cyl) in the mtcars dataset. Use different colors to represent the transmission type (am). Add appropriate title, labels, and legend to the plot.
# Load the ggplot2 library
library(ggplot2)

# Create a bar plot of 'cyl' with different colors for 'am'
ggplot(mtcars, aes(x = factor(cyl), fill = factor(am))) +
  geom_bar() +
  labs(
    title = "Number of Cylinders by Transmission Type",
    x = "Number of Cylinders",
    y = "Count"
  ) +
  scale_fill_manual(values = c("0" = "blue", "1" = "green")) +  # Define colors for 'am'
  guides(fill = guide_legend(title = "Transmission Type")) +  # Legend title
  theme_minimal()

