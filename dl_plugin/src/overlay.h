// Hooks Dying Light's swap chain and draws Garry's Mod's frame on top of it.
#pragma once
#include <windows.h>
#include <functional>

namespace gml::overlay {

struct Callbacks {
    // Every DL frame, before the overlay draws. Gets the back buffer size and window.
    std::function<void(HWND hwnd, unsigned w, unsigned h)> onFrame;
};

bool Init(const Callbacks& cb);
void SetVisible(bool v);    // the user's toggle (F7)
void SetSuppressed(bool v); // hidden for now regardless (paused, no camera)
void SetReproject(bool v);  // re-project GMod's older frame to DL's current camera
void SetParallax(bool v);
void SetMaxFps(int fps, int autoLimit);  // Dying Light frame cap (0 = off, -1 = auto: refresh / N <= autoLimit)
void SetLowLatency(bool v);             // before the first frame: at most one frame queued
bool Visible();
// Save what the player sees (next frame) to GModLight_shots\. Capped unless forced.
void RequestScreenshot(const char* reason, bool force = false);

}  // namespace gml::overlay
