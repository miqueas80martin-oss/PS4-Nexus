// SPDX-License-Identifier: GPL-2.0-or-later
// SPDX-FileCopyrightText: 2025-2026 PS4 Nexus Mobile Project

#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <memory>

namespace PS4Nexus::Mobile {

enum class ScreenResolution : uint8_t {
    RESOLUTION_1080p = 0,
    RESOLUTION_720p = 1,
    RESOLUTION_540p = 2,
    RESOLUTION_360p = 3,
    RESOLUTION_ADAPTIVE = 4,
};

enum class GPUOptimization : uint8_t {
    HIGH_QUALITY = 0,
    BALANCED = 1,
    LOW_POWER = 2,
    ULTRA_LOW_POWER = 3,
};

struct MobileDeviceCapabilities {
    uint32_t cpu_cores = 4;
    uint32_t ram_mb = 512;
    float battery_health = 1.0f;
    bool has_dedicated_gpu = false;
    ScreenResolution screen_resolution = ScreenResolution::RESOLUTION_720p;
    uint32_t screen_dpi = 420;
};

class MobileGraphicsAdapter {
public:
    MobileGraphicsAdapter(const MobileDeviceCapabilities& caps);
    ~MobileGraphicsAdapter();

    void Initialize();
    void SetOptimizationLevel(GPUOptimization level);
    uint32_t GetCurrentFPS() const;
    void RenderFrameOptimized();
    void SetDynamicResolution(bool enabled);

private:
    MobileDeviceCapabilities capabilities;
    GPUOptimization optimization_level = GPUOptimization::BALANCED;
    uint32_t current_fps = 60;
    bool dynamic_resolution_enabled = true;
};

class MobileCPUThrottler {
public:
    MobileCPUThrottler();
    ~MobileCPUThrottler();

    void EnableThermalMonitoring();
    uint8_t GetThermalState() const;
    void ThrottleIfNeeded();
    uint32_t GetCPUFrequency() const;

private:
    uint32_t max_frequency = 2000;
    uint32_t current_frequency = 2000;
    uint8_t thermal_state = 0;
};

class MobileBatteryManager {
public:
    MobileBatteryManager();
    ~MobileBatteryManager();

    uint8_t GetBatteryPercentage() const;
    bool IsCharging() const;
    void EnableBatterySaver(bool enabled);
    uint32_t GetBatteryTimeRemaining() const;

private:
    uint8_t battery_percentage = 100;
    bool is_charging = false;
    bool battery_saver_enabled = false;
};

class MobileMemoryOptimizer {
public:
    MobileMemoryOptimizer(uint32_t available_ram_mb);
    ~MobileMemoryOptimizer();

    struct MemoryStats {
        uint32_t total_mb = 0;
        uint32_t used_mb = 0;
        uint32_t free_mb = 0;
        float usage_percent = 0.0f;
    };

    MemoryStats GetMemoryStats() const;
    void OptimizeMemory();
    void EnableAggressiveOptimization(bool enabled);

private:
    uint32_t total_ram_mb = 0;
    uint32_t used_ram_mb = 0;
    bool aggressive_optimization = false;
};

class MobileInputHandler {
public:
    MobileInputHandler();
    ~MobileInputHandler();

    void HandleTouchInput(float x, float y, bool pressed);
    void MapTouchZonesToButtons();
    void EnableVirtualController(bool enabled);
    bool HasHapticFeedback() const;
    void TriggerHapticFeedback(uint32_t duration_ms);

private:
    bool haptic_feedback_supported = false;
    bool virtual_controller_enabled = true;
};

} // namespace PS4Nexus::Mobile