data<-read.csv('IRIS.csv')

print(data)

x1<-data$sepal_length
y1<-data$sepal_width

x2<-data$petal_length
y2<-data$petal_width

z<-data$species

plot(x1~y1,
    xlab = "length",
    ylab = "width",
    xlim = c(1,5),
    ylim = c(1,8),
    main = "Sepal - Petal",
    col = 'red',
    pch = ifelse(z=='Iris-setosa', 0, ifelse(z=='Iris-versicolor', 1, 2))
)
legend("topright", legend = "sepal", col = "red", pch = 16, cex = 1.0, inset = c(0.01,0.01), box.lwd = 0)

points(x2~y2,
    col = 'blue',
    pch = ifelse(z=='Iris-setosa', 0, ifelse(z=='Iris-versicolor', 1, 2))
)
legend("topright", legend = "petal", col = "blue", pch = 16, cex = 1.0, inset = c(0.01,0.1), box.lwd = 0)

legend("bottomright", legend = 'Iris-setosa',pch = 0, cex = 1.0, inset = c(0.01,0.01), box.lwd = 0)
legend("bottomright", legend = 'Iris-versicolor',pch = 1, cex = 1.0, inset = c(0.01,0.1), box.lwd = 0)
legend("bottomright", legend = 'Iris-virginica',pch = 2, cex = 1.0, inset = c(0.01,0.2), box.lwd = 0)

