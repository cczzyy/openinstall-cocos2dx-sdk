//
// Created by Wenki on 2018/5/25.
//


#include "OpenInstall.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include "openinstall/Android/AndroidOpenInstall.h"

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

#include "CPOpenInstall.h"

#endif

using namespace openInstall2dx;

void OpenInstall::init() {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

    AndroidOpenInstall::init();

#elif  (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

    CPOpenInstall::initOpeninstall();

#endif

}

void OpenInstall::getInstall(float s, void (*installCallback)(AppData appData)) {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    AndroidOpenInstall::getInstall(s, installCallback);
#elif  (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

    CPOpenInstall::getInstallFrom(s,installCallback);

#endif

}

void OpenInstall::registerWakeUpHandler(void (*wakeupCallback)(AppData appData)) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    AndroidOpenInstall::registerWakeUpHandler(wakeupCallback);
#elif  (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

    CPOpenInstall::registerWakeUpHandlerToNative(wakeupCallback);
    
#endif
}

void OpenInstall::reportRegister() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    AndroidOpenInstall::reportRegister();
#elif  (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

    CPOpenInstall::reportRegisterToService();
#endif
}

void OpenInstall::reportEffectPoint(const char *pId, long pValue) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    AndroidOpenInstall::reportEffectPoint(pId, pValue);
#elif  (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

    CPOpenInstall::reportEffectPointToService(pId, pValue);
#endif
}
