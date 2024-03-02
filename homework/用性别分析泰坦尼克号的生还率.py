import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib
plt.ioff()
matplotlib.use('TKAgg')



date=pd.read_csv("Titanic.csv",index_col=0)
date.head()
date.info()
date.drop(['Name','Ticket','Cabin'],axis=1,inplace=True)
a=date["Sex"].value_counts()
print(a)
date["Sex"]=="male"
date["Sex"]=(date["Sex"]=="male").astype("int")
print(date["Sex"])
b=date["Embarked"].value_counts().sum()

print(b)
#删除缺失值
date=date[date["Embarked"].notnull()]
c=date.shape
print("整理数据后的行列数",c)

#文本数据数字化
lables=date["Embarked"].unique().tolist()
date["Embarked"]=date["Embarked"].apply(lambda x:lables.index(x))

print("整理后的数据","\n",date)



#画图
tr=[]#登船位置数据
tl=[]#死亡人数数据
for i,j in zip(date["Embarked"],date["Survived"]):
    tr.append(i)
    tl.append(j)
print(tr)
print(tl)
x=[0,1,2]
x1=[0,1]
y=[tr.count(0),tr.count(1),tr.count(2)]
y1=[tl.count(0),tl.count(1)]
plt.figure()
plt.bar(x,y)
plt.figure(num=2)
plt.bar(x1,y1)

condition1=date["Sex"]==1#女性
condition2=date["Survived"]==1
condition3=date["Sex"]==0#男性
condition4=date["Survived"]==0
a1=len(date[condition1&condition2])/len(date[condition1])
a2=1-a1
b1=len(date[condition3&condition2])/len(date[condition3])
b2=1-b1
plt.figure(num=3)
plt.bar(x1,[a1,b1],label="survived proportion by sex")
plt.bar([4,5],[a2,b2],label="dead proportion by sex")
plt.text(0.1,-0.1,"female",ha="center",va="bottom")
plt.text(1.1,-0.1,"male",ha="center",va="bottom")
plt.text(4.1,-0.1,"female",ha="center",va="bottom")
plt.text(5.1,-0.1,"male",ha="center",va="bottom")
plt.text(0,a1,"%f%%"%(a1*100),ha="center",va="bottom")
plt.text(1,b1,"%f%%"%(b1*100),ha="center",va="bottom")
plt.text(4,a2,"%f%%"%(a2*100),ha="center",va="bottom")
plt.text(5,b2,"%f%%"%(b2*100),ha="center",va="bottom")

plt.legend()
plt.show()