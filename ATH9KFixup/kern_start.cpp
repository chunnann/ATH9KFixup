//
//  kern_start.cpp
//  ATH9KFixup
//
//  Copyright © 2017 lvs1974. All rights reserved.
//
//  This kext is made based on lvs1974's NvidiaGraphicsFixup.
//

#include <Headers/plugin_start.hpp>
#include <Headers/kern_api.hpp>

#include "kern_ath9k.hpp"

static ATH9K ath9k;

static const char *bootargOff[] {
	"-ath9koff"
};

static const char *bootargDebug[] {
	"-ath9kdbg"
};

static const char *bootargBeta[] {
	"-ath9kbeta"
};

PluginConfiguration ADDPR(config) {
    xStringify(PRODUCT_NAME),
    parseModuleVersion(xStringify(MODULE_VERSION)),
    LiluAPI::AllowNormal | LiluAPI::AllowInstallerRecovery,
    bootargOff,
    arrsize(bootargOff),
    bootargDebug,
    arrsize(bootargDebug),
    bootargBeta,
    arrsize(bootargBeta),
    KernelVersion::Mavericks,
    KernelVersion::Mojave,
    []() {
        ath9k.init();
    }
};





