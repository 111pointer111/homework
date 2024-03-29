#分析各数据与房价的关系
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib
plt.ioff()
matplotlib.use('TKAgg')
date=pd.read_csv("boston_housing_data.csv")
print(date)
date=date[date["MEDV"].notnull()]       #删除有缺失数据的数据组
plt.figure(num="the relation between the MEDV and RM")
plt.bar(date["MEDV"],date["RM"])        #由柱状图可以看出房间数大致与房价成正相关
date=date.sort_values(by="MEDV")
print(date)#使数据按房价的从小到大排序
plt.figure(num="the relation between the")
plt.plot(date["MEDV"],date["RM"]) #由折线图可以看出房间数大致与房价成正相关
date1=date[["MEDV","RM"]]
print(date1["MEDV"])
r=date1.corr()
print(r["MEDV"]["RM"])#输出房价和房间数的相关系数


#线性回归
lr=0.00001#学习率
b=0#截距
k=0#斜率
epochs=1000#迭代次数
datey=date["RM"].values
datex=date["MEDV"].values
num=len(date["MEDV"])

def computer_error(b,k,datex,datey):
    totalerror=0
    for i in range(0,num):
        totalerror+=(k*datex[i]+b-datey[i])**2
    return totalerror/50
def gradient_descent(b,k,datex,datey):
    for i in range(epochs):
        b_grad=0
        k_grad=0
        for j in range(0,num):
            b_grad+=(1/num)*(k*datex[j]+b-datey[j])*1000
            k_grad+=(1/num)*datex[j]*(k*datex[j]+b-datey[j])
        b-=lr*b_grad
        k-=lr*k_grad
    return b,k
b,k=gradient_descent(b,k,datex,datey)
plt.plot(datex,datex*k+b)



plt.show()
