import tensorflow as tf
import numpy as np

x_data = np.float32(np.random.rand(1, 100)) # 生成一个 1x100，取值范围在 [0, 1) 的二位数组，作为输入数据
y_data = x_data * 4.2 + 5.2 # 计算标准输出

# 建模
# - 我们已经知道这是一个一次函数了，有两个未知量 w 和 b
w = tf.Variable(tf.zeros(1)) # 模型中一个可变的数字，初值为 0
b = tf.Variable(tf.zeros(1)) # 同上
y = w * x_data + b # 一次函数公式模型

# 求解
# - 设置损失函数：误差的均方差
loss = tf.reduce_mean(tf.square(y - y_data))
# - 选择梯度下降的方法
optimizer = tf.train.GradientDescentOptimizer(0.5)
# - 迭代的目标：最小化损失函数
train = optimizer.minimize(loss)

# - 初始化所有全局变量
init = tf.global_variables_initializer()
# - 启动图 (graph)
sess = tf.Session()
sess.run(init)

# - 迭代，反复执行上面的最小化损失函数这一操作（train op）,拟合平面
for step in range(0, 201):
  sess.run(train)
  if step % 20 == 0:
    print(step, sess.run(w), sess.run(b))