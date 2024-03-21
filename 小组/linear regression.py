import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
datex=np.array(np.arange(0,50))
dated=np.array(np.random.randint(-5,5,size=50))
datey=np.array(3*datex+10+dated)
#学习率
lr=0.0001
#截距
b=0
#斜率
k=0
#最大迭代数
epochs=50
def computer_error(b,k,datex,datey):
    totalerror=0
    for i in range(0,50):
        totalerror+=(k*datex[i]+b-datey[i])**2
    return totalerror/50
def gradient_descent(b,k,datex,datey):
    for i in range(epochs):
        b_grad=0
        m=50
        k_grad=0
        for j in range(0,50):
            b_grad+=(1/m)*(k*datex[j]+b-datey[j])
            k_grad+=(1/m)*datex[j]*(k*datex[j]+b-datey[j])
        b-=lr*b_grad
        k-=lr*k_grad
    return b,k
b,k=gradient_descent(b,k,datex,datey)
plt.scatter(datex,datey)
plt.plot(datex,k*datex+b)
print(b,k)
plt.show()