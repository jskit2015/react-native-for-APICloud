# react-native-for-APICloud
基于react-native 封装的 APIClou 平台的一个iOS模块.可以在APICloud上,直接使用 react-native 开发了.

## 先说点什么
[APICloud](http://www.apicloud.com/) 是国内新兴的混合开发平台.[react-native](http://facebook.github.io/react-native/),是facebook今年三月份正式对外公布的基于react.js的no dom开发框架.近几日,翻阅 react-native 的文档时,发现react-native更多的是担当 view 层的角色,理论上是可以嵌入到原生 iOS 应用开发的.也就是说,理论上,是有可能把 react-native 封装为 APICloud 平台的一个模块,用于扩展自己的应用功能的.试着做了下,真的成功了.(想想都有点小激动,以后可以完全用JS写原生应用了,say goodbye to html!)

## 扫描二维码快速体验

![app二维码](react-native.png)

这是官方入门指导的一个例子,我简单调了下样式.
第一个页面是 APICloud 模块开发的默认页面,里面的代码我已经改为react-navite 模块的了;点击运行,唤起的第二个页面是 facebook 官方为 react-native 准备的示例,我简单调了下样式.
注意: 第二个页面,可是完全用react-native写的,原生listView + 自定义单元格的页面! 

## 快速开始

* 通过 APICloud 云控制台-->模块-->自定义模块,将 module/iOS/reactNative.zip 上传,并勾选此模块.
* 通过 APICloud 云控制台-->代码-->上传压缩包,将 case/widget.zip 包上传.
* 通过 APICloud 云控制台-->云编译, 编译应用,扫描生成的二维码安装即可.

## 模块快速参考

如果你熟悉 react-native本身,直接将 moudleName 和 jsbundle 换成你自己的react-native模块名和jsbundle文件地址即可使用,无需关注内部细节.

```js
/* 创建并显示一个 react-navite 模块 */

var reactNative = api.require("reactNative");

reactNative.createModule({
    moduleName: "AwesomeProject", // 模块名称.需在编译前的react-js文件中指定.必须要和传入的jsbundle文件对应.
    jsbundle: "widget://res/main.jsbundle" /* 使用react-native bundle指令编译react-js后得到的文件.
    必须和moduleName对应使用.支持http:// ,fs://, widget://, cache:// 等协议. */
});
```

## 项目目录说明

* case 测试用例.
* jsbundle 一个干净的react-native 工程,可用于控件的调试和jsbundle文件的编译.
* module 一个编译好的APIClodu平台模块包,可直接上传后使用.
* project 将react-native 内嵌在自己应用的实例工程,以APICloud平台模块封装为例.
* react-native.png 快速体验的二维码.

## 项目核心代码

```objective-c
#import "YFReactNative.h"
#import "RCTRootView.h"
#import "NSDictionaryUtils.h"

@implementation YFReactNative

- (void) createModule:(NSDictionary *)paramDict{
  NSURL *jsCodeLocation;
  
  NSString * jsbundle = [paramDict objectForKey: @"jsbundle"];
  NSString * moduleName= [paramDict objectForKey: @"moduleName"];
  
  NSString * path = [self getPathWithUZSchemeURL: jsbundle];
  jsCodeLocation = [NSURL URLWithString: path];
  
  // 在新的控制器中,打开react-native模块.
  
  RCTRootView *rootView = [[RCTRootView alloc] initWithBundleURL:jsCodeLocation moduleName:moduleName launchOptions:nil];
  
  UIViewController * rectVC = [[UIViewController alloc] init];
  rectVC.view = rootView;
  
  [self.viewController.navigationController pushViewController:rectVC animated: YES];
}

@end
```
