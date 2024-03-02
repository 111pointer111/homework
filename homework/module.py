
import matplotlib.pyplot as plt
import numpy as np

n=1024
x=np.random.normal(0,1,n)
y=np.random.normal(0,1,n)
t=y
plt.scatter(x, y,s=10,c=t,cmap='Blues',alpha=0.5)
plt.xlim(-5,5)
plt.ylim(-5,5)
plt.show()

