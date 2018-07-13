import tensorflow as tf
import numpy as np
import pandas as pd

# 1.准备数据：使用 NumPy 生成假数据(phony data), 总共 100 个点.
# datas = pd.read_csv('data.csv', delimiter=',')
# x_data = np.float32(np.array([datas['x'].values]))
# y_data = np.float32(np.array([datas['y'].values]))
x1_data = np.float32(np.random.rand(1, 100)) # 随机输入
x2_data = np.float32(np.random.rand(1, 100)) # 随机输入
x3_data = np.float32(np.random.rand(1, 100)) # 随机输入
x4_data = np.float32(np.random.rand(1, 100)) # 随机输入
y_data = x1_data * 5.2 + x2_data * 8.2 + x3_data * 9.2 + x4_data * 1.2 + 1.6;
# print(x_data)
# print(_x_data)

# 2.构造一个线性模型
b = tf.Variable(tf.zeros(1))
# w = tf.Variable(tf.zeros(1))
# y = w * x_data + b
w1 = tf.Variable(tf.zeros(1))
w2 = tf.Variable(tf.zeros(1))
w3 = tf.Variable(tf.zeros(1))
w4 = tf.Variable(tf.zeros(1))
y = (w1 * x1_data) + (w2 * x2_data) + (w3 * x3_data) + (w4 * x4_data) + b

# 3.求解模型
# 设置损失函数：误差的均方差
loss = tf.reduce_mean(tf.square(y - y_data))
# 选择梯度下降的方法
optimizer = tf.train.GradientDescentOptimizer(0.2)
# 迭代的目标：最小化损失函数
train = optimizer.minimize(loss)


############################################################
# 以下是用 tf 来解决上面的任务
# 1.初始化变量：tf 的必备步骤，主要声明了变量，就必须初始化才能用
init = tf.global_variables_initializer()


# 设置tensorflow对GPU的使用按需分配
# config  = tf.ConfigProto()
# config.gpu_options.allow_growth = True
# 2.启动图 (graph)
# sess = tf.Session(config=config)
sess = tf.Session()
sess.run(init)

# 3.迭代，反复执行上面的最小化损失函数这一操作（train op）,拟合平面
for step in range(0, 1001):
  sess.run(train)
  if step % 100 == 0:
    print(step, sess.run(w1), sess.run(w2), sess.run(w3), sess.run(w4), sess.run(b))
    # print(step, sess.run(w), sess.run(b))

# 得到最佳拟合结果 w: [4.2], b: [6.2]