#pragma once

#include "Logger.hpp"

#define LOG(x, y) debugging::Logger::getInstancePtr()->logMessage(x, y)