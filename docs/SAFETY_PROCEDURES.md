# Safety Procedures — Pegasus Drone Inspection System

> **MANDATORY**: All personnel operating the Pegasus drone inspection system must read and
> acknowledge this document before any flight operations. Sign-off required annually.

---

## Table of Contents

1. [Pre-Flight Checklist](#1-pre-flight-checklist)
2. [Emergency Procedures](#2-emergency-procedures)
3. [Geofence and No-Fly Zones](#3-geofence-and-no-fly-zones)
4. [Redundancy Systems](#4-redundancy-systems)
5. [AI Failover Procedures](#5-ai-failover-procedures)
6. [Manual Override](#6-manual-override)
7. [Post-Incident Reporting](#7-post-incident-reporting)

---

## 1. Pre-Flight Checklist

Every flight — regardless of mission type — requires completion of all items below.
No item may be skipped or deferred.

### Airframe & Propulsion

- [ ] **1. Propeller condition**: Visually inspect all propellers for cracks, chips, deformation,
      or excessive wear. Replace any blade with visible damage. Verify all nuts are torqued.
- [ ] **2. Motor spin-up test**: Arm motors briefly (1-2 s) in STABILIZE mode, verify all motors
      spin freely and in correct direction. Listen for bearing noise or vibration.
- [ ] **3. Frame integrity**: Check all arms, landing gear, and body panels for cracks or loose
      fasteners. Verify damping grommets (if equipped) are not degraded.

### Power System

- [ ] **4. Battery voltage**: Measure battery voltage under no-load. Must be ≥ 3.7 V/cell
      for LiPo (3.8 V/cell for LiHV). Reject packs below threshold.
- [ ] **5. Battery connection**: Verify battery is fully seated, strap secured, and connector
      locked. Tug-test the power lead.
- [ ] **6. Battery cell balance**: Check balance plug voltage deltas. All cells must be within
      0.1 V of each other.

### Flight Controller & Sensors

- [ ] **7. GPS lock**: Verify ≥ 12 satellites with HDOP ≤ 1.0. Wait for 3D fix before arming.
- [ ] **8. Compass calibration**: Check heading accuracy. Must be within ±5° of known direction.
      Recalibrate if >10° error or after any hardware change.
- [ ] **9. Barometer**: Verify altitude reading is within ±2 m of ground truth.

### Radio Link

- [ ] **10. RC link quality**: RSSI ≥ -80 dBm (or ≥ 60% link quality if dBm unavailable).
      Walk the mission area to verify no signal dropout zones.
- [ ] **11. RC failsafe**: Set throttle to zero, turn off transmitter. Verify FC enters failsafe
      mode (RTL or LAND) within 2 seconds. Re-bind transmitter.
- [ ] **12. Telemetry link**: MAVROS or Mavlink link active. Verify Heartbeat received at ≥ 1 Hz.

### AI & Compute

- [ ] **13. Jetson boot**: Verify Jetson is powered, reachable over SSH or serial. Check
      `tegrastats` for normal temperature (< 65 °C idle) and power mode.
- [ ] **14. ROS2 nodes**: All critical ROS2 nodes running: `inference_node`, `mock_camera_node`
      (or real camera), `mission_manager` (if used). Verify with `ros2 node list`.
- [ ] **15. AI topics**: Verify `/ai/defect_detections`, `/ai/defect_json`, and `/ai/node_health`
      are publishing. Check latency < 100 ms.
- [ ] **16. AI model checksum**: Verify model file `hybrid_fp16.trt` SHA-256 matches the
      signed release checksum published with the model card.

### Environment

- [ ] **17. Weather check**: Wind < 15 mph (7 m/s) sustained, gusts < 10 m/s. Visibility ≥ 3 km.
      No precipitation within forecast window. Ambient temp within battery spec (-10 °C to 50 °C).
- [ ] **18. Airspace clearance**: Confirm no NOTAMs or TFRs in the operating area. Verify
      operational altitude (max 400 ft AGL / 120 m) is legal.
- [ ] **19. Geofence**: Verify geofence polygon loaded on FC and on companion computer.
      Confirm no exclusion zones are within 100 m of flight path.
- [ ] **20. Landing zone**: Clear landing pad of debris, personnel, and obstacles. Mark with
      visual indicator (cone, mat, or paint). Confirm RTL landing point is obstacle-free.

### Crew & Comms

- [ ] **21. Roles assigned**: Pilot (manual RC), Operator (mission/monitor), Spotter (visual
      lookout). Each person has distinct call sign.
- [ ] **22. Comms check**: Radios/briefing on all crew: "Launch call" + "Emergency call"
      protocol confirmed. Verbal go-around.
- [ ] **23. Emergency plan reviewed**: Everyone present has read this document's emergency
      procedures within the past 24 hours.
- [ ] **24. Liability & insurance**: Confirmed applicable coverage. Mission approved by
      site safety officer (if required).

**Final sign-off before arm:**
- [ ] **Safety Pilot**: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Date/Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_
- [ ] **Mission Operator**: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Date/Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_

---

## 2. Emergency Procedures

### 2.1 Lost Link (RC / Telemetry)

**Priority**: Re-establish control → Auto-land → Flyaway mitigation

#### Stage 1 — RC Link Lost (≤ 5 seconds)
1. Operator alerts: **"RC LOST"** to all crew.
2. Wait **5 seconds** for automatic re-connect (most RC systems auto-recover).
3. If link returns → continue mission or RTL at pilot discretion.

#### Stage 2 — RC Lost, Telemetry Up (5-30 seconds)
1. Use MAVROS/companion computer to send RTL command:
   ```bash
   ros2 service call /mavros/cmd/command mavros_msgs/srv/CommandLong \
     "{command: 176, confirmation: 0, param1: 1.0, param2: 4.0, param3: 0.0, param4: 0.0, param5: 0.0, param6: 0.0, param7: 0.0}"
   ```
   (Command 176 = MAV_CMD_DO_SET_MODE, param2=4 = PX4 RTL mode)
2. Monitor drone on telemetry. Expect RTL altitude climb (15 m default).
3. Prepare for manual landing once RC is restored.

#### Stage 3 — Full Link Loss (Both RC and Telemetry)
1. **Do not panic**. FC should auto-enter failsafe after 10 s of no RC signal.
2. Default failsafe action: RTL (climb to 15 m → return to home → land).
3. If RTL area is compromised (e.g., over water), pilot may change failsafe action to
   LAND before flight.
4. Go to last known drone position after battery exhausted (estimate ~8 min of hover).
5. Use onboard recording (blackbox) for post-incident analysis.

#### Stage 4 — No Auto-RTL or Flyaway
1. Activate **secondary failsafe**: companion computer watchdog triggers RTL.
2. If no response → **Emergency geofence**: onboard failsafe triggers LAND.
3. If outside geofence → **Lost-drone procedure**: Record bounding box of last known position,
    time, heading, battery level. Use DJI-style finder beacon (if equipped).
4. File airspace incident report with local authority.

### 2.2 Low Battery

#### Detection
- **Level 1 (Warning)**: 25% remaining or 3.7 V/cell under load.
- **Level 2 (Critical)**: 15% remaining or 3.5 V/cell under load.
- **Level 3 (Emergency)**: 10% remaining or 3.3 V/cell under load.

#### Actions

| Level | Action |
|-------|--------|
| **1 (Warning)** | Complete current waypoint, then RTL. Do not start new inspection segments. |
| **2 (Critical)** | Abort mission immediately. Direct RTL command. Reduce throttle to minimum safe hover. |
| **3 (Emergency)** | Land immediately wherever safe. Do not attempt RTL. Accept crash if no safe LZ. |

**Always**: Log battery voltage, current, and temperature at 1-second intervals
on the companion computer for post-flight battery health analysis.

### 2.3 GPS Loss

#### Effects
- Loss of accurate position hold, waypoint navigation, and RTL capability.
- Loss of geofence enforcement (unless baro-only geofence configured).

#### Immediate Actions
1. Operator: **"GPS LOST"**.
2. Pilot immediately switches to **ATTITUDE** or **STABILIZE** (manual) mode.
3. If GPS does not recover within 10 s → **Land manually**.
4. If VSLAM or optical flow is active, may provide limited position hold —
   but **do not rely on it**. Manual landing is the default.

#### Causes & Mitigation

| Cause | Mitigation |
|-------|------------|
| RF interference (jammer, high-power antenna) | Move to different area, 50+ m away. Check for known emitters. |
| Constellation geometry (GPS/Galileo/GLONASS) | Wait 2 min for constellation change. |
| Multipath (buildings, canyon) | Fly higher (10+ m AGL) or move lateral 20+ m. |
| Receiver fault | Reboot FC, check antenna connection. |

### 2.4 Motor Failure (Partial)

1. Pilot: **"MOTOR FAILURE"** — switch to manual control immediately.
2. For quadcopter: reduce throttle. Anticipate yaw spin. Use opposite yaw to stabilize.
3. If controlled descent possible → land immediately in nearest safe area.
4. If uncontrollable → Cut throttle. **Crew: SHOUT "FALLING"**, clear area.
5. Post-incident: Record motor telemetry, ESC logs, and physical motor inspection.

### 2.5 Fire (Battery / ESC)

1. **SHOUT "FIRE."** — All personnel evacuate to ≥ 15 m upwind.
2. **DO NOT** use water on LiPo fire (water reacts with lithium).
   Use Class D fire extinguisher (dry sand, copper powder, or lith-x).
3. If drone is on ground and battery is removable → Use fire tongs to drop battery
   into a fireproof metal container filled with sand. **Do not** approach if
   battery is venting or flaming.
4. If drone is airborne → Land immediately regardless of location. Then follow above.
5. Call emergency services if fire spreads or structure is threatened.

---

## 3. Geofence and No-Fly Zones

### 3.1 Geofence Configuration

The geofence is defined at **two independent layers**:

1. **Flight Controller (FC) Geofence** — Enforced by PX4 firmware. Hard cutoff.
   - Polygon defined in QGroundControl.
   - Max altitude: 120 m AGL (400 ft).
   - Max radius: 500 m from home.
   - **Action on breach**: RTL (default), optionally LAND.
   - Cannot be disabled by software — must be physically cleared.

2. **Companion Computer (ROS2) Geofence** — Enforced by the mission manager.
   - Same or stricter polygon as FC geofence.
   - Pre-arm check: drone position + mission waypoints are inside all fence boundaries.
   - **Action on breach**: Pause mission → attempt to return to last safe waypoint.

### 3.2 No-Fly Zones (NFZs)

| Zone Type | Distance Buffer | Action |
|-----------|----------------|--------|
| Airports (Class B/C/D) | 5 NM (9.3 km) | Pre-arm: reject takeoff |
| Heliports / Hospitals | 0.5 NM (~900 m) | Pre-arm: reject takeoff |
| Crowds (people > 500) | 50 m lateral, no overflight | Geofence polygon restriction |
| Military / Gov't facilities | Per local regulation | Must have explicit clearance |
| Power lines (high voltage) | 50 m lateral, 30 m vertical | Geofence polygon restriction |
| Roads (vehicular traffic) | No overflight below 50 m | Mission planning requirement |

### 3.3 Dynamic Geofence Updates

The geofence may be updated in-air **only** in these cases:
- Emergency landing area re-designation.
- Temporary airspace restriction (TFR, NOTAM).

**Procedure:**
1. Operator sends new geofence polygon via MAVROS.
2. Validate that drone is currently inside new boundary.
3. Only then — remove old geofence.
4. Log change in mission log.

---

## 4. Redundancy Systems

### 4.1 Propulsion Redundancy

Pegasus uses a **quadcopter X-frame**, which has **no propulsion redundancy**.
Loss of any single motor means forced landing. Mitigations:

- Use high-quality motors (T-Motor, Sunnysky) with known Mean Time Between Failure.
- Pre-flight vibration analysis (FFT on IMU accelerometer).
- ESCs with active current limiting and over-temp protection.

### 4.2 Sensor Redundancy

| Sensor | Primary | Backup | Fallback |
|--------|---------|--------|----------|
| Position | GPS + GLONASS + Galileo | Barometer (altitude only) | Manual pilot |
| Heading | External compass (MAG) | Internal compass | Manual estimation |
| Attitude | IMU (gyro + accel) | Secondary IMU (if dual-FC) | Pilot visual |
| Velocity | GPS velocity | Optical flow (if equipped) | Manual estimation |
| Altitude | Barometer | GPS altitude | Manual estimation |
| Camera | Main inspection cam | Secondary FPV cam (if equipped) | N/A |

### 4.3 Communication Redundancy

- **Primary**: 2.4 GHz RC link (FrSky/Crossfire) — 10+ km range.
- **Secondary** (if equipped): 900 MHz RC link (Crossfire/R9) — 40+ km range.
- **Telemetry**: 433/915 MHz Mavlink radio — 5+ km range.
- **Companion link**: Wi-Fi / 4G / Ethernet bridge for ROS2 messages.
- **Data storage**: All telemetry and AI results are logged to onboard SD card
  in addition to over-the-air transmission.

### 4.4 Compute Redundancy

- Primary AI compute: Jetson Orin Nano Super.
- FC: Pixhawk/Cube flight controller (STM32F7 or H7).
- If Jetson crashes → FC continues in manual/autonomous mode (no AI).
- If FC crashes → No control. Kill switch (disconnect battery) is last resort.

### 4.5 Software Watchdog

```python
# Companion computer watchdog (runs as a separate process/container)
# If inference_node or mission_manager crashes, watchdog restarts them.
# If watchdog itself doesn't receive heartbeat for 10 seconds:
#   → Send RTL command to FC
#   → Log "COMPANION FAILURE. RTL ACTIVE."

watchdog_config = {
    "heartbeat_topic": "/ai/node_health",
    "heartbeat_timeout": 10.0,   # seconds
    "action_on_timeout": "RTL",
    "restart_crashed_nodes": True,
}
```

---

## 5. AI Failover Procedures

### 5.1 AI Node Unhealthy

If `/ai/node_health` reports `status: "degraded"` or stops publishing:

1. AI is considered **offline**.
2. Mission manager logs: "AI HEALTH LOST — operation continues without AI guidance."
3. Pilot or operator continues mission via manual flight (no autonomy change).
4. If AI was providing hover-extension or revisit commands — these are suppressed.
5. System continues in **safe fallback** mode: manual or pre-planned waypoint only.
6. Land within 2 minutes and investigate.

### 5.2 AI False Positive Storm

If >10 detections per second (clearly spurious) or confidence >0.9 on noise:

1. Operator: **"AI SPAM"**.
2. Reduce detection rate by increasing `conf_threshold` to 0.8 via dynamic parameter
   or simply ignore AI output for this flight.
3. Post-mission: capture rosbag of camera feed for model retraining.

### 5.3 AI Detects Critical Defect During Non-Inspection Phase

- AI should only run during inspection waypoint phases.
- If AI fires a CRITICAL-level detection during transit or takeoff:
   - Log it with drone position and timestamp.
   - **Do not** alter flight path — it may be a false positive.
   - Operator may optionally command a revisit waypoint.

---

## 6. Manual Override

### 6.1 RC Override

**The safety pilot has absolute priority at all times.** The RC transmitter
is the primary override mechanism:

- **Switch to MANUAL/STABILIZE**: Immediately reverts to pilot direct control.
  Disengages any autonomous mode. This is the **first action** in any emergency.
- **Switch to RTL**: One-switch failsafe to Return-To-Launch.
- **Kill switch**: Dedicated switch (3-position) that arms/disarms motors.

**This override cannot be disabled by software.** The RC receiver is wired
directly to the flight controller.

### 6.2 Software Kill Switch

If RC is unavailable but telemetry is up:

```bash
# Immediate disarm (emergency stop motors)
ros2 service call /mavros/cmd/arming mavros_msgs/srv/CommandBool \
  "{value: false}"

# Or: RTL command
ros2 service call /mavros/cmd/command mavros_msgs/srv/CommandLong \
  "{command: 176, confirmation: 0, param1: 1.0, param2: 4.0, param3: 0.0, param4: 0.0, param5: 0.0, param6: 0.0, param7: 0.0}"
```

### 6.3 Physical Kill Switch

**Last resort.** Only when drone is on ground and motors are armed/active:

1. **Safety switch on FC** (if equipped): Press and hold for 3 seconds to disarm.
2. **Battery disconnect**: Use quick-release connector. **Only if drone is on ground**
   and approachable. Do NOT approach a drone with spinning propellers.
3. **Fire extinguisher** (CO2/powder): Directed at battery/ESC compartment.

### 6.4 Override Hierarchy

```
Highest Priority:
  1. Physical kill (battery disconnect / FC safety switch)
  2. RC transmitter (any switch → manual)  
  3. Software kill (MAVROS service)
  4. AI override (operator computer)
Lowest Priority:
```

---

## 7. Post-Incident Reporting

Any event requiring emergency procedures (Section 2) or override (Section 6)
**must** be reported in the system safety log within 24 hours.

### Report Template

```
INCIDENT REPORT — PEGASUS SAFETY

Date/Time (UTC): _______________
Drone ID: ______________________
Flight #: ______________________
Location (lat/lon): _____________

Incident Type:
  [ ] Lost Link (RC)
  [ ] Lost Link (Telemetry)
  [ ] Low Battery
  [ ] GPS Loss
  [ ] Motor Failure
  [ ] Fire
  [ ] AI Failure
  [ ] Geofence Breach
  [ ] Other (describe): _____________

Description: ___________________________________
_______________________________________________
_______________________________________________

Root Cause: ___________________________________
_______________________________________________

Actions Taken: ________________________________
_______________________________________________

Damage/Injuries: ______________________________

Approving Officer: _____________ Date: ________
```

---

## Revision History

| Version | Date | Author | Changes |
|---------|------|--------|---------|
| 1.0 | 2026-06-15 | Pegasus Team | Initial release |

---

**THIS DOCUMENT MUST BE PRINTED, SIGNED, AND KEPT WITH FLIGHT LOGS.**
**DIGITAL COPY IN REPO: `docs/SAFETY_PROCEDURES.md`**
