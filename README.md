# FileTester-FT

这是一个为了对一些使用文件进行输入输出的命令行文件的快速测试而开发的项目。

这个项目的版本号为v1.0.0.1。

## 目录

- [项目设立背景](#项目设立背景)
- [下载安装](#下载安装)
- [使用方法](#使用方法)
- [版本信息](#版本信息)
- [关于作者](#关于作者)
- [下载问题](#下载问题)

## 项目设立背景

在NOIP比赛中，程序都是以文件进行输入输出的，所以练习时也要使用文件输入输出。

而这样的调试并不方便，我们习惯注释掉文件直接从屏幕输入输出。

但是这不是个好习惯，所以我启用了这个项目，来实现一种方便的测试，而不用改变程序本身。

## 下载安装

作者本人不会Git，所以我不能像别人一样提供Git下载。

这里说一下项目构造，具体下载方法请自己探索。

### 解决方案、项目与源代码

解决方案是`FileTester-FT/test.sln`，下载后即可打开，但与项目文件夹的相对位置不能改变；打开后可以生成。

项目文件夹是`FileTester-FT/test/`文件夹，这个文件夹下的`test.vcxproj`是项目文件。

### 已生成的文件

已生成的文件放在`FileTester-FT/executable files/`文件夹下，详细信息见`FileTester-FT/executable files/README.md`，这里不再重复。

## 使用方法

详细使用方法各个版本有所不同，详见更新记录。

## 版本信息

### version 1.0.0.1

[下载源码 从 gitee.com](https://gitee.com/apple-ba/FileTester-FT/repository/archive/v1.0.0.1%E5%8F%91%E5%B8%83.zip)

[下载程序 从 gitee.com](https://gitee.com/apple-ba/FileTester-FT/raw/master/v1.0.0.1.exe)

完成于2021年1月。

#### 包含了基础的功能：

1.完成了从屏幕输入`IDC_EDIT_input`的数据到输入文件`*.in`的转换代码；

2.完成了运行程序`*.exe`的代码；

3.完成了从输出文件`*.out`到屏幕输出`IDC_EDIT_output`的数据转换代码。

#### 已知但未修复的错误：

1.程序可以自动删除生成的输入文件`*.in`，但不能自动删除生成的输出文件`*.out`;

2.无法读入输出文件`*.out`中的换行。

#### 使用方法：

按照程序窗口提示操作即可。没有什么特别之处。有两个英文单词，做个翻译：`input`输入；`output`输出。输出框不可以编辑，不是错误。

## 关于作者

作者：apple-ba

代码编辑器：VS2019+MFC

## 下载问题

为了解决raw.githubusercontent.com无法访问问题，在[gitee.com](https://gitee.com/apple-ba/FileTester-FT/)有一个类似的项目但结构不同，供参考。

