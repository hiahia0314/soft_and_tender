**平台**：win11

**C语言环境**：gcc.exe (MinGW-W64 x86_64-ucrt-posix-seh, built by Brecht Sanders) 12.3.0

**图形库**：SDL2  没有使用第三方图形库

使用clion进行编译，编译选项为CMakeList

---
# 游戏方式
## 机制
游戏进行的越长分数越高

其中有Life表示当前生命值，life为0时游戏结束

碰到障碍物会进入无敌时间并life减1,分数减200

## 键位
**（注意要切换至英语输入）**

1：采用wasd进行移动，w为“飞越”，s为“下潜”，a,d分别为左右移动

2：空格键为暂停

## 图片说明
### 障碍物
1：**无法躲避**的障碍物
[barrier.jpg](image%2Fbarrier.jpg)

2：需要**下潜**的障碍物
[water.jpg](image%2Fwater.jpg)

3：需要**飞跃**的障碍物
[sky.jpg](image%2Fsky.jpg)
### 道具
1：碰到后增加生命
[hum.jpg](image%2Fhum.jpg)

2：进入无敌时间
[herothing.png](image%2Fherothing.png)

3：加分
[bonus.jpg](image%2Fbonus.jpg)

4: 扣分
[decrease.jpg](image%2Fdecrease.jpg)

## 关于这个游戏的主题..
这是以日本电影红辣椒为主题（电影详情见[paprika]https://movie.douban.com/subject/1865703/

游戏中的音乐与图片均来自于电影，游戏最后的彩蛋也是本人认为在电影中的比较经典的台词。


