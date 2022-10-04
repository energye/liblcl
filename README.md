
* 中文   
* [English](README.en-US.md)   

----
# liblcl

一个通用的跨平台GUI库，核心使用Lazarus LCL

----

[编译指南](Compile.README.md)  

----

* 已支持语言： 

  * go: https://github.com/energye/golcl
 

* 完成度较高的语言：

  * nim（Beta）: https://github.com/energye/golcl

#### 其他   

*所有导出的函数都为标准的c方式。* 在Windows上采用`__stdcall`约定，其它平台采用`__cdecl`约定。

----

##### 字符编码  

在所有平台上都默认使用`utf-8`编码。

----

##### 使用结构化异常处理的函数

### 授权

**保持跟Lazarus LCL组件采用相同的授权协议: [COPYING.modifiedLGPL](COPYING.modifiedLGPL.txt)**  