#pragma once

#define ENABLE_HOOK

#include "Payload.h"

#include <detours.h>

namespace Hook {

    void initFunction();

    void addHook();

    void removeHook();

}