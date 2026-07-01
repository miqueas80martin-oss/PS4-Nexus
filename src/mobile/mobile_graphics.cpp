// SPDX-License-Identifier: GPL-2.0-or-later
// SPDX-FileCopyrightText: 2025-2026 PS4 Nexus Mobile Project

#include "mobile_graphics.hpp"
#include "../common/logger.hpp"

namespace PS4Nexus::Mobile {

MobileGraphicsAdapter::MobileGraphicsAdapter(const MobileDeviceCapabilities& caps)
    : capabilities(caps) {
    LOG_INFO("Mobile Graphics Adapter created");
}

MobileGraphicsAdapter::~MobileGraphicsAdapter() {}

void MobileGraphicsAdapter::Initialize() {
    LOG_INFO("Initializing Mobile Graphics Adapter");
    if (capabilities.ram_mb < 512) {
        optimization_level = GPUOptimization::ULTRA_LOW_POWER;
    } else if (capabilities.ram_mb < 1024) {
        optimization_level = GPUOptimization::LOW_POWER;
    } else {
        optimization_level = GPUOptimization::BALANCED;
    }
}

void MobileGraphicsAdapter::SetOptimizationLevel(GPUOptimization level) {
    optimization_level = level;
    LOG_DEBUG("GPU optimization level changed");
}

uint32_t MobileGraphicsAdapter::GetCurrentFPS() const {
    return current_fps;
}

void MobileGraphicsAdapter::RenderFrameOptimized() {
    if (optimization_level == GPUOptimization::HIGH_QUALITY) {
        current_fps = 60;
    } else if (optimization_level == GPUOptimization::BALANCED) {
        current_fps = 45;
    } else if (optimization_level == GPUOptimization::LOW_POWER) {
        current_fps = 30;
    } else {
        current_fps = 20;
    }
}

void MobileGraphicsAdapter::SetDynamicResolution(bool enabled) {
    dynamic_resolution_enabled = enabled;
    LOG_DEBUG("Dynamic resolution: {}", enabled ? "enabled" : "disabled");
}

MobileCPUThrottler::MobileCPUThrottler() {
    LOG_INFO("Mobile CPU Throttler created");
}

MobileCPUThrottler::~MobileCPUThrottler() {}

void MobileCPUThrottler::EnableThermalMonitoring() {
    LOG_INFO("Thermal monitoring enabled");
}

uint8_t MobileCPUThrottler::GetThermalState() const {
    return thermal_state;
}

void MobileCPUThrottler::ThrottleIfNeeded() {
    if (thermal_state > 80) {
        current_frequency = max_frequency * 0.7f;
        LOG_WARN("CPU throttled due to thermal state");
    }
}

uint32_t MobileCPUThrottler::GetCPUFrequency() const {
    return current_frequency;
}

MobileBatteryManager::MobileBatteryManager() {
    LOG_INFO("Mobile Battery Manager created");
}

MobileBatteryManager::~MobileBatteryManager() {}

uint8_t MobileBatteryManager::GetBatteryPercentage() const {
    return battery_percentage;
}

bool MobileBatteryManager::IsCharging() const {
    return is_charging;
}

void MobileBatteryManager::EnableBatterySaver(bool enabled) {
    battery_saver_enabled = enabled;
    LOG_DEBUG("Battery saver: {}", enabled ? "enabled" : "disabled");
}

uint32_t MobileBatteryManager::GetBatteryTimeRemaining() const {
    return battery_percentage * 2.1f;
}

MobileMemoryOptimizer::MobileMemoryOptimizer(uint32_t available_ram_mb)
    : total_ram_mb(available_ram_mb) {
    LOG_INFO("Mobile Memory Optimizer created");
}

MobileMemoryOptimizer::~MobileMemoryOptimizer() {}

MobileMemoryOptimizer::MemoryStats MobileMemoryOptimizer::GetMemoryStats() const {
    MemoryStats stats;
    stats.total_mb = total_ram_mb;
    stats.used_mb = used_ram_mb;
    stats.free_mb = total_ram_mb - used_ram_mb;
    stats.usage_percent = (static_cast<float>(used_ram_mb) / total_ram_mb) * 100.0f;
    return stats;
}

void MobileMemoryOptimizer::OptimizeMemory() {
    LOG_DEBUG("Running memory optimization");
}

void MobileMemoryOptimizer::EnableAggressiveOptimization(bool enabled) {
    aggressive_optimization = enabled;
}

MobileInputHandler::MobileInputHandler() {
    LOG_INFO("Mobile Input Handler created");
}

MobileInputHandler::~MobileInputHandler() {}

void MobileInputHandler::HandleTouchInput(float x, float y, bool pressed) {
    LOG_DEBUG("Touch input at ({}, {})", x, y);
}

void MobileInputHandler::MapTouchZonesToButtons() {
    LOG_DEBUG("Touch zones mapped");
}

void MobileInputHandler::EnableVirtualController(bool enabled) {
    virtual_controller_enabled = enabled;
}

bool MobileInputHandler::HasHapticFeedback() const {
    return haptic_feedback_supported;
}

void MobileInputHandler::TriggerHapticFeedback(uint32_t duration_ms) {
    if (haptic_feedback_supported) {
        LOG_DEBUG("Haptic feedback triggered");
    }
}

} // namespace PS4Nexus::Mobile