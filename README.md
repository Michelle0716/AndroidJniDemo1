# AndroidJniDemo1
安卓对c进行so文件打包，并以jni的形式进行调用

## 项目中的部分
app  ：    编译so文件
jniDemo:   添加运行so文件

## 开发环境：
###  android studio 3.0.1
       (As3.0以上创建项目，选择支持c/c++,项目会自动生成需要的配置，不需要在编写cMakeList文件，创建后，直接运行，即可调用cpp里面c文件的内容)
###  配置ndk
       谷歌官方下载  https://developer.android.google.cn/ndk/downloads/
      
###    android studio的sdk manager里下载
       （直接在file——project structure——sdk——ndk 点击download，有可能存在文件缺失，建议官方下载,在ndk里面配置）
       
## 打包so
把Native方法提取出来，在一个类里面专门处理，如jniUtil.java
运行app,点击工具栏 build-make"app"，在app/build/intermediates/cmake/debug下可以看到生成的so文件，把他们拷贝出来，给JniDemo使用。
### 注意：
   jniUtil里面的包名要和cpp里面c文件的方法名的包名一致，一般我们现在jniUtil里面写好方法后，点击alt+enter生成c方法，这样不易出错
   
## 调用jni
在jniDemo里面新建文件夹jnilibs,把so文件的几个文件放在里面，在gradle配置
###  配置gradle
sourceSets.main{
        jni.srcDirs = []
        jniLibs.srcDir "src/main/jniLibs"
    }
    
    
### 创建方法类（包名类名要和so里面的一致）
 在java中创建与上面jniUtil.java相同的包，并把jniUtil.java拷到次目录。
 
 
 ##备注
 
### 3.配置动态连接库的名称,在mode的gradle->defaultConfig下增加以下代码
   ndk {
            moduleName "JNITest" //输出的SO文件名称
            abiFilters "armeabi", "armeabi-v7a", "x86"//指定cpu的类型
        }
###  4.加载动态连接库,在编写native方法类中新增：
   static
    {
        System.loadLibrary("native-lib");//名字注意，需要跟你的build.gradle ndk节点下面的名字一样
    }
### so库名Library
 System.loadLibrary导入，如果build.gradle ndk没有配置，那么要和CMakeLists里面一样，Sets the name of the library后面的名字，否则出现导入库失败，查找不到该库
    
    
