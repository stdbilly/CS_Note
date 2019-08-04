## 封装log4cpp,使用起来比较方便，如下所示。

输出的日志信息能同时输出到终端和文件

int main(void)
{

​	LogInfo("Message");	//或者   
​	LogError("Message");
​	LogWarn("Message");
​	LogDebug("Message");

}

##### [使用单例模式实现](mylog)