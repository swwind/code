const data = require('./data.json');

const length = data.map(d => d.length);
const diameter = data.map(d => d.diameter);
const height = data.map(d => d.height);

const whole_weight = data.map(d => d.whole_weight);
const shucked_weight = data.map(d => d.shucked_weight);
const viscera_weight = data.map(d => d.viscera_weight);
const shell_weight = data.map(d => d.shell_weight);

const age = data.map(d => d.rings + 1.5);

console.log(`database <- data.frame(
  x_l = c(${length.join(',')}),
  x_d = c(${diameter.join(',')}),
  x_h = c(${height.join(',')}),

  x_whole = c(${whole_weight.join(',')}),
  x_shucked = c(${shucked_weight.join(',')}),
  x_viscera = c(${viscera_weight.join(',')}),
  x_shell = c(${shell_weight.join(',')}),

  y = c(${age.join(',')})
)

lm.sol <- lm(y ~ x_l + x_d + x_h + x_whole, data = database)

# pdf("length.pdf")
# plot(y=database$y, x=database$x_l)
# pdf("diameter.pdf")
# plot(y=database$y, x=database$x_d)
# pdf("height.pdf")
# plot(y=database$y, x=database$x_h)

# pdf("whole_weight.pdf")
# plot(y=database$y, x=database$x_whole)
# pdf("shucked_weight.pdf")
# plot(y=database$y, x=database$x_shucked)
# pdf("viscera_weight.pdf")
# plot(y=database$y, x=database$x_viscera)
# pdf("shell_weight.pdf")
# plot(y=database$y, x=database$x_shell)

summary(lm.sol)
pdf("first.pdf")
plot(lm.sol)

tstep <- step(lm.sol)
summary(tstep)
pdf("second.pdf")
plot(tstep)
`)
