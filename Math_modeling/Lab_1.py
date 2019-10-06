
# coding: utf-8

# In[12]:


import matplotlib as plt


# In[14]:


import numpy as np


# In[45]:


# Задание функции и ее производных
f = lambda x: 2.71828**x -5*x*x + 5*x
f1 = lambda x: 2.71828**x -10*x + 5
f2 = lambda x: 2.71828**x -10


# In[73]:


# Отрисовка общего графика
x = np.linspace(-1, 5, 100000)

plt.plot(x, f(x), label='f(x)')
plt.plot(x, f1(x), label='f\'(x)')
plt.plot(x, f2(x), label='f\'\'(x)')

plt.xlabel('x label')
plt.ylabel('y label')

plt.title("Simple Plot")

plt.legend()
plt.grid(True)
plt.show()


# In[74]:


a1 = -1
a2 = 1
d = 0.00001

b1 = a1
b2 = a2
#Рассчет корня с высокой точностью
for number in range(100):
    a2=a1 - f(a1)/f1(a1)
    a1 = a2 
print(a2)

#Подсчет минимального количества итераций для заданной точности d
cnt = 0
while d < abs(b2-a2):
    cnt+=1
    b2=b1 - f(b1)/f1(b1)
    b1 = b2 
print(b2)
print(cnt)


# In[75]:


a1 = 1
a2 = 3
d = 0.00001

b1 = a1
b2 = a2
#Рассчет корня с высокой точностью
for number in range(100):
    a2=a1 - f(a1)/f1(a1)
    a1 = a2 
print(a2)

cnt = 0
#Подсчет минимального количества итераций для заданной точности d
while d < abs(b2-a2):
    cnt+=1
    b2=b1 - f(b1)/f1(b1)
    b1 = b2 
print(b2)
print(cnt)


# In[71]:


a1 = 4
a2 = 5
d = 0.00001

b1 = a1
b2 = a2
#Рассчет корня с высокой точностью
for number in range(100):
    a2=a1 - f(a1)/f1(a1)
    a1 = a2 
print(a2)

#Подсчет минимального количества итераций для заданной точности d
cnt = 0
while d < b2-a2:
    cnt+=1
    b2=b1 - f(b1)/f1(b1)
    b1 = b2 
print(b2)
print(cnt)


# In[79]:


#Отрисовка графика для визуальной проверки полученных корней
x = np.linspace(-0.15, -0.14, 1000)

plt.plot(x, f(x), label='f(x)')

plt.xlabel('x label')
plt.ylabel('y label')

plt.title("Simple Plot")

plt.legend()
plt.grid(True)
plt.show()


# In[80]:


#Отрисовка графика для визуальной проверки полученных корней
x = np.linspace(1.62, 1.63, 1000)

plt.plot(x, f(x), label='f(x)')

plt.xlabel('x label')
plt.ylabel('y label')

plt.title("Simple Plot")

plt.legend()
plt.grid(True)
plt.show()


# In[78]:


#Отрисовка графика для визуальной проверки полученных корней
x = np.linspace(4.21, 4.22, 1000)

plt.plot(x, f(x), label='f(x)')

plt.xlabel('x label')
plt.ylabel('y label')

plt.title("Simple Plot")

plt.legend()
plt.grid(True)
plt.show()

