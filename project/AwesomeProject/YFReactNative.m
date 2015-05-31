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
