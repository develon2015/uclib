## uclib
> ublic 是基于 glibc 的 C 程序库. <br/>

> 下载 <br/>
> git clone https://github.com/develon2015/uclib.git <br/>

> 使用头文件: <br/>
> #include <uclib/inc/net.h> <br/>

> 添加静态库uclib.a以编译: <br/>
> gcc \*.c uclib/uclib.a <br/>

### 测试
```
develon@desktop:~/git/uclib$ t resolveIP
测试 tresolveIP 函数...
javac.ga -> 104.18.44.94
javac.ga -> 2606:4700:30::6812:2d5e
```

