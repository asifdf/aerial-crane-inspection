# Safety Injection Order — Pegasus Drone Inspection

> **MANDATORY**: This procedure must be followed exactly. No step may be skipped.
> Each step requires sign-off before proceeding to the next.

---

## Safety Principles

1. **AI never controls motors directly** — AI only detects defects and reports JSON
2. **Propellers OFF unless explicitly required** — Steps 1-4: props removed
3. **Human in the loop** — Safety pilot with RC override at all times
4. **Incremental autonomy** — Each step adds one capability, validated before next
5. **Kill switches** — Hardware (RC), Software (ROS2 service), Physical (tether)

---

## Step 1: Jetson Desk Inference (Zero Risk)

**Goal**: Validate AI pipeline on Jetson with static camera, no drone.

### Setup
- Jetson Orin Nano Super powered, connected to monitor/keyboard
- USB camera or CSI camera mounted on tripod
- No drone hardware connected

### Procedure
1. Flash Jetson with JetPack 6.x (L4T 36.x)
2. Install Docker + TensorRT + PyTorch + ROS2 Humble
3. Deploy `hybrid_fp16.trt` to `/opt/models/`
4. Run inference node:
   ```bash
   ros2 launch pegasus_ai inference.launch.py model_path:=/opt/models/hybrid_fp16.trt
   ```
5. Run mock camera or USB camera publisher
6. Verify:
   - [ ] `/ai/defect_detections` publishes at >10 Hz
   - [ ] `/ai/defect_json` valid JSON with correct schema
   - [ ] `/ai/node_health` shows FPS > 30, latency < 100ms
   - [ ] Annotated image (if enabled) shows correct boxes

### Sign-off
- [ ] **Engineer**: _______________ Date: __________
- [ ] **Safety Review**: _______________ Date: __________

---

## Step 2: Drone Powered, PROPELLERS REMOVED

**Goal**: Test full ROS2 stack on drone hardware, AI + MAVROS + PX4, no flight risk.

### Setup
- Drone frame assembled, flight controller (Pixhawk/Cube) connected
- Jetson mounted, connected to FC via UART/USB
- **PROPELLERS PHYSICALLY REMOVED** — verify visually
- Battery connected (for FC power only)
- RC transmitter ON, bound, in manual mode

### Procedure
1. Power on drone (FC + Jetson)
2. Start MAVROS:
   ```bash
   ros2 launch mavros px4.launch fcu_url:=/dev/ttyTHS1:921600
   ```
3. Start AI inference node
4. Verify ROS2 topics:
   - [ ] `/mavros/state` — FC connected, armed=false
   - [ ] `/mavros/local_position/pose` — position estimator running
   - [ ] `/camera/image_raw` — camera publishing
   - [ ] `/ai/defect_detections` — AI running
   - [ ] `/ai/defect_json` — JSON output
5. Test MAVROS services (no motors):
   - [ ] `/mavros/cmd/arming` — call, verify FC rejects (props off)
   - [ ] `/mavros/set_mode` — switch to OFFBOARD, verify FC rejects

### Sign-off
- [ ] **Engineer**: _______________ Date: __________
- [ ] **Safety Review**: _______________ Date: __________
- [ ] **Propellers Verified Removed**: _______________ Date: __________

---

## Step 3: Manual Flight + Camera Recording Only

**Goal**: Collect real flight imagery, verify camera/VFX pipeline, no AI.

### Setup
- **PROPELLERS INSTALLED** — standard flight props
- Safety pilot with RC transmitter (mode 2)
- Tethered or large open area, GPS lock
- Jetson recording to disk (rosbag or image saver)
- **AI NODE STOPPED** — only camera + MAVROS running

### Procedure
1. Pre-flight checks: battery, props tight, CG, GPS, RC link
2. Arm in STABILIZE/ALT_HOLD mode
3. Manual takeoff to 2m, hover
4. Fly crane inspection pattern manually:
   - [ ] Approach structure at 1-3m distance
   - [ ] Vary angles: perpendicular, 30°, 45°
   - [ ] Vary lighting: sunny, shaded, morning/afternoon
   - [ ] Capture 5+ minutes of footage
5. Land, disarm
6. Download rosbag/images
7. Verify:
   - [ ] Images clear, no excessive motion blur
   - [ ] Exposure reasonable (not blown out / crushed blacks)
   - [ ] Field of view covers inspection zones
   - [ ] Frame rate ≥ 20 FPS sustained

### Sign-off
- [ ] **Pilot**: _______________ Date: __________
- [ ] **Engineer**: _______________ Date: __________
- [ ] **Data Quality OK**: _______________ Date: __________

---

## Step 4: Manual Flight + AI Inference (AI Reports Only)

**Goal**: Run AI on real flight data in real-time, verify detections, AI does NOT control drone.

### Setup
- Same as Step 3
- AI inference node RUNNING
- Dashboard/backend connected to `/ai/defect_json`
- **AI OUTPUT LOGGED ONLY** — no connection to flight controller

### Procedure
1. Arm, takeoff to 2m
2. Fly same inspection pattern as Step 3
3. Monitor dashboard in real-time:
   - [ ] Detections appear on dashboard
   - [ ] JSON schema valid
   - [ ] Latency < 300ms (camera → dashboard)
   - [ ] No false positive spam
4. Land, disarm
5. Post-flight analysis:
   - [ ] Compare AI detections vs ground truth (manual labeling)
   - [ ] Log false positives/negatives for retraining
   - [ ] Verify zone_id mapping correct (if implemented)

### Sign-off
- [ ] **Pilot**: _______________ Date: __________
- [ ] **Engineer**: _______________ Date: __________
- [ ] **AI Quality Acceptable**: _______________ Date: __________

---

## Step 5: Position Hold + Waypoint Test (No AI Decisions)

**Goal**: Autonomous waypoint flight working, AI still passive.

### Setup
- PX4 position control tuned (EKF2, GPS, barometer)
- MAVROS offboard mode tested
- ROS2 mission manager node ready
- Waypoints defined for crane inspection pattern
- AI running but **output ignored by mission manager**

### Procedure
1. Switch to OFFBOARD mode via MAVROS
2. Execute pre-programmed waypoint mission:
   - [ ] Takeoff to 3m
   - [ ] Visit 5+ waypoints around structure
   - [ ] Hold at each waypoint 3s (simulate inspection dwell)
   - [ ] Return to launch (RTL)
2. Verify:
   - [ ] Position hold accuracy < 0.5m
   - [ ] Waypoint transitions smooth
   - [ ] No oscillations or失控
   - [ ] Battery consumption as expected
   - [ ] AI running in background but not affecting flight

### Sign-off
- [ ] **Pilot**: _______________ Date: __________
- [ ] **Engineer**: _______________ Date: __________
- [ ] **Autonomous Flight Safe**: _______________ Date: __________

---

## Step 6: Waypoint Inspection + AI Detection (AI Reports, May Hover)

**Goal**: Full integration — autonomous flight with AI-assisted inspection behavior.

### AI Behavior (NON-CONTROL)
AI may request:
- **Hover/Slow**: `publish /ai/inspection_command {command: "hover", duration: 5.0}`
- **Revisit**: `publish /ai/inspection_command {command: "revisit", waypoint_id: 3}`
- **Alert**: `publish /ai/inspection_command {command: "alert", defect: {...}}`

**Mission Manager** decides whether to act on these — default: log only.

### Setup
- Mission manager subscribes to `/ai/defect_json` and `/ai/inspection_command`
- AI hover requests implemented as mission manager velocity commands (max 0.5 m/s)
- Safety pilot retains RC override at all times

### Procedure
1. Start mission in OFFBOARD
2. At each inspection waypoint:
   - [ ] Dwell 5s for AI inference
   - [ ] If AI detects HIGH/CRITICAL defect → mission manager hovers additional 10s
   - [ ] Log defect + position + image to dashboard
3. Complete mission, RTL
4. Verify:
   - [ ] All waypoints visited
   - [ ] Defects detected at expected locations
   - [ ] Hover extensions triggered correctly
   - [ ] No unsafe maneuvers
   - [ ] Dashboard shows complete inspection report

### Sign-off
- [ ] **Pilot**: _______________ Date: __________
- [ ] **Engineer**: _______________ Date: __________
- [ ] **Integration Verified**: _______________ Date: __________

---

## Step 7: Dashboard Integration + Operational Handoff

**Goal**: Complete system operational — dashboard shows live + historical data.

### Checklist
- [ ] Dashboard receives real-time JSON from drone (MQTT/ROSbridge)
- [ ] Historical inspections queryable by date, zone, drone
- [ ] Defect map visualization (3D or 2D)
- [ ] Risk heatmap by zone
- [ ] Export report (PDF/CSV) for maintenance team
- [ ] Alert notifications (email/Slack) for CRITICAL defects
- [ ] System monitoring: Jetson health, link quality, battery

### Documentation Package
- [ ] This safety injection order (signed)
- [ ] Flight test logs (rosbags) for all steps
- [ ] AI model cards (training data, metrics, limitations)
- [ ] Operating manual (startup, shutdown, emergency procedures)
- [ ] Maintenance schedule (model retrain, sensor calibration)

### Final Sign-off
- [ ] **Lead Engineer**: _______________ Date: __________
- [ ] **Safety Officer**: _______________ Date: __________
- [ ] **Operations Manager**: _______________ Date: __________
- [ ] **Customer/Stakeholder**: _______________ Date: __________

---

## Emergency Procedures

### Software Kill Switch (ROS2 Service)
```bash
# Emergency stop - disables offboard, commands RTL
ros2 service call /mavros/cmd/command mavros_msgs/srv/CommandLong \
  "{command: 176, confirmation: 0, param1: 1.0, param2: 0.0, param3: 0.0, param4: 0.0, param5: 0.0, param6: 0.0, param7: 0.0}"
# Command 176 = MAV_CMD_DO_SET_MODE with RTL
```

### Hardware Kill Switch
- **RC Transmitter**: Switch to MANUAL/STABILIZE — immediate pilot control
- **Flight Controller Safety Switch**: Physical button on FC (if equipped)
- **Battery Disconnect**: Quick-release connector (last resort)

### Software Watchdog
```python
# In mission manager - auto-RTL on link loss
if not received_heartbeat(5.0):  # 5 seconds
    trigger_rtl()
    log_emergency("Link loss")
```

---

## Revision History

| Version | Date | Author | Changes |
|---------|------|--------|---------|
| 1.0 | 2026-06-15 | Pegasus Team | Initial release |

---

**THIS DOCUMENT MUST BE PRINTED, SIGNED, AND KEPT WITH FLIGHT LOGS.**
**DIGITAL COPY IN REPO: `docs/SAFETY_INJECTION_ORDER.md`**
