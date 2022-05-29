database <- read.csv('data.csv')
head(database)
cor(database)

lm.sol <- lm(age ~ x_l + x_d + x_h + x_whole, data=database)
# lm.sol <- lm(age ~ x_l + x_d + x_h + x_whole, data=database)
summary(lm.sol)

# library(leaps)
# leaps<-regsubsets(age ~ x_l + x_d + x_h + x_whole + x_shucked + x_viscera + x_shell, data=database, nbest=7)
# library(car)
# subsets(leaps,statistic = 'cp',main='Cp plot for all subsets regression')
# abline(1,1,lty=2,col='blue',y_max=5)

pdf("lm.sol.pdf")
plot(lm.sol)

lm.step = step(lm.sol)
summary(lm.step)

pdf("lm.step.pdf")
plot(lm.step)

anova(lm.step,lm.sol)
