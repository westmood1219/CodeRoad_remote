#20
# a_input = input('please')
# print('input:',a_input)

#21
# 元组 tuple 列表 list
# a_tuple = (12,3,4,5)
# another_tuple = 2,3,4,5,6
#
# a_list = [12,3,456,87]
#
# for content in a_tuple:
#     print(content)
# range(n)生成一个从0到n-1的迭代器
# len类似sizeof
# for index in range(len(a_tuple)):
#     print('index=',index,'number in list=',another_tuple[index])

#22列表 list
# a = [1,2,3,4,5,1,-1]

#append(x)追加一个值到list最后面
# a.append(0)
# print(a)#[1, 2, 3, 4, 5, 1, -1, 0]

#指定位置添加值-insert(x,y)
# a.insert(1,0)
# print(a)#[1, 0, 2, 3, 4, 5, 1, -1]

#remove(value) 除去list里第一次出现的value
# a.remove(1)
# print(a)#[2, 3, 4, 5, 1, -1]

#打印特定位
# print(a[0])#第一位
# print(a[-1])#从后开始数第一位即最后一位(list倒数第一个数)
# print(a[1:3])#第1-2位 不包括第3位
# print(a[:3])#第0-2位 不包括第3位
# print(a[5:])#第4位后的所有(不包括第4位)
# print(a[-3:])#倒数三位(方向不变) 或者说从倒数第三到最后一位 [5 ,1,-1]

#index(x) #第一次出现x时的索引
# print(a.index(2))#1

#count(x)出现多少次x
# print(a.count(1))#2

#sort从小到大排序
# a.sort()
# print(a)#不能这样写:print(a.sort())
#从大到小
# a.sort(reverse=True)
# print(a)#[5, 4, 3, 2, 1, 1, -1]

#23多维列表
#推荐用numpy pandas处理多维列表
# a = [1,2,3,4,5]
# multi_dim_a = [[1,2,3],
#                [2,3,4],
#                [3,4,5]]
# print(a[1])
# print(multi_dim_a[0][1])#类似C

#24 字典 与list类似
#但可以包含很多属性 如数,字符,list,字典,函数
# d = {'apple':1,'pear':2,'orange':3}
# print(d['apple'])
# del d['pear']
# print(d)
# d2 = {1:'a','c':'b'}
# print(d2[1])
# def func():
#     print(1)
#     return 2
# d3 = {
#     'apple': [1, 2, 3],
#     'pear': {1: 3, 3: 'a'},
#     'orange': func
# }
# print(d3['pear'][3])
# print(d3['orange'])
# print(d3['orange']())

# 25载入模块imort
# import time
# print(time.localtime())

# import time as t#给模块取一个简称
# print(t.localtime())

#只载入某些功能from且不用打前面的time.
# from time import time,localtime
# print(localtime())#可以省略time.
# print(time())
#载入所有功能且不用打前面的time.
# from time import*
# print(localtime())#可以省略time.
# print(time())

# 26 自己的模块(脚本)
# import m1
# m1.printdata('I robot')
#把m1.py放在site-packages文件夹下即可作为全局py文件都可以调用的库

#27 循环之 continue & break
# 没学break之前:
# a = True
# while a:
#     b = input('tpye:')
#     if b=='1':
#         a = False
#     else:
#         pass # 空操作语句，主要用于占位，确保代码结构的完整性而不执行任何实际逻辑
#     print('still in while')
# print('finish run')
#有了break后:
# while True:
#     b = input('tpye:')
#     if b=='1':
#         break
#     else:
#         pass # 空操作语句，主要用于占位，确保代码结构的完整性而不执行任何实际逻辑
#     print('still in while')
# print('finish run')
# continue与C类似

#28 try之错误的处理
# try:
#     file = open('eee','r+')
# except Exception as e:#报错就执行下面:把报错信息记录在e里...
#     print('there is no such file \'eee\'')
#     response = input('do you want to create a new file')
#     if response == 'y':
#         file = open('eee','w')#创建eee
#     else:
#         pass
# else:#不报错执行下面
#     file.write('sss')
# file.close()

#29 py的zip lambda map等功能
#zip
# a = [1,2,3]
# b = [4,5,6]
# list(zip(a,b))#zip:列的方式合并 [(1, 4), (2, 5), (3, 6)]
# for i,j in zip(a,b):
#     print(i/2,j*2)
# list(zip(a,a,b))#[(1, 1, 4), (2, 2, 5), (3, 3, 6)]
#lamda
# def fun1(x,y):
#     return(x+y)
# fun1(2,3)
# fun2 = lambda x,y:x+y#>>fun2(1,2) 3
#map
# list(map(fun1,[1],[2]))#[3]
# list(map(fun1,[1,3],[2,5]))#[3,8]

#30 深浅复制copy&deepcopy
# import copy
# a = [1,2,3]
# b = a
# id(a)#a的内存地址
# print(id(a)==id(b))#True
# c = copy.copy(a)
# print(id(a)==id(c))#False
#False是因为发生了浅拷贝,只拷贝了值
# c[1]=22222
# print(a) #[1, 2, 3]
# print(c) #[1, 22222, 3]
#
# a = [1,2,[3,4]]
# d = copy.copy(a)
#id(a) = id(d) #SyntaxError:can't assign to function call
# id(a[2]) ==  id(d[2])#True
#浅拷贝的行为
#创建了一个新列表对象 d，但仅复制了 a 的第一层元素（即 1, 2, [3, 4] 的引用）。
#嵌套对象（如 [3, 4]）不会被复制，而是共享同一内存地址。因此 a[2] 和 d[2] 指向同一个子列表，id(a[2]) == id(d[2]) 返回 True
# e = copy.deepcopy(a)
# id(e[2]) == id(a[2])#False

# 31 多线程thread 另一套视频
# 32 多核 另一套
# 33 tkinter窗口 另一套
# 34 pickle 存放数据
# import pickle
# a_dict = {'da':111,2:[23,1,4],'23':{1:2,'d':'sad'}}
#
# file = open('pickle_eg.pickle','wb')
# pickle.dump(a_dict,file)
# file.close()
#
# file = open('pickle_eg.pickle','rb')
# a_dict1 = pickle.load(file)
# file.close()
# #或者用with读取
# with open('pickle_eg.pickle','rb')as file1:
#     a_dict2 = pickle.load(file1)
#     #不用file.close()了
# print(a_dict2)

# 35 set除去不同值
# char_list = ['a','b','c','c','d','d']
# print(set(char_list))#{'c', 'a', 'd', 'b'}
# sentence = 'hello world'
# print(set(sentence))#{'o', 'd', ' ', 'r', 'l', 'w', 'e', 'h'}
# unique_char = set(char_list)
# unique_char.add('x')
# print(unique_char)#{'c', 'd', 'a', 'b', 'x'}
# # unique_char.clear()
# # print(unique_char)#set()
# unique_char.remove('x')
# #print(unique_char.remove('x'))#None
# print(unique_char)
#
# print(unique_char.remove('y'))#报错,因为list里面没有y
# print(unique_char.discard('y'))#None
# print(unique_char)#但返回的还是原数据
#
# set1 = unique_char
# set2 = {'a','e','i'}
# print(set1.difference(set2))#set1中与set2不相同的值
# print(set1.intersection(set2))#set1中与set2相同的值(交集)

#正则表达
#用于文字处理比如网页爬虫