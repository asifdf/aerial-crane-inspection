"""
Contract tests for Aerial AI drone stack (Aerial Autonomy Stack + PX4 SITL + MAVROS).

Validates:
  - Aerial Autonomy Stack ROS2 packages
  - autopilot_interface_msgs (actions + services)
  - mission conops YAML format
  - PX4 SITL availability
  - MAVROS installation
  - Isaac Sim scripts

Milestone 7: Drone Integration (Aerial Autonomy Stack)
"""

import os
import subprocess
from pathlib import Path

import pytest
import yaml

ROS2_WS = Path(__file__).parent.parent.parent / "ros2_ws"
AAS_SRC = ROS2_WS / "src"
MISSIONS_DIR = Path(__file__).parent.parent.parent / "missions"
SCRIPTS_DIR = Path(__file__).parent.parent.parent / "scripts"


# ── Helpers ────────────────────────────────────────────────────────────

def _ros2_pkg_list():
    """Return set of installed ROS2 packages."""
    result = subprocess.run(
        ["ros2", "pkg", "list"],
        capture_output=True, text=True,
        env={**os.environ, "AMENT_PREFIX_PATH": "/opt/ros/humble"},
    )
    return set(result.stdout.strip().split("\n"))


# ═══════════════════════════════════════════════════════════════════════
# Mission Conops YAML
# ═══════════════════════════════════════════════════════════════════════

class TestConopsYAML:
    """Validate mission YAML files (aerial-autonomy-stack conops format)."""

    def test_crane_inspection_exists(self):
        assert (MISSIONS_DIR / "crane_inspection.yaml").exists(), \
            "crane_inspection.yaml missing"

    def test_crane_inspection_valid(self):
        with open(MISSIONS_DIR / "crane_inspection.yaml") as f:
            data = yaml.safe_load(f)
        assert "steps" in data, "Must have 'steps' key"
        assert isinstance(data["steps"], list), "'steps' must be a list"
        assert len(data["steps"]) > 0, "At least one step required"

        valid_actions = {"takeoff", "land", "reposition", "orbit", "wait", "offboard", "speed"}
        for i, step in enumerate(data["steps"]):
            assert "action" in step, f"Step {i} missing 'action'"
            assert step["action"] in valid_actions, \
                f"Step {i} unknown action '{step['action']}'"

    def test_legacy_mission_still_valid(self):
        """Old crane_inspection_demo.yaml should still parse."""
        path = MISSIONS_DIR / "crane_inspection_demo.yaml"
        if not path.exists():
            pytest.skip("Legacy mission file not found")
        with open(path) as f:
            data = yaml.safe_load(f)
        assert "name" in data
        assert "waypoints" in data


# ═══════════════════════════════════════════════════════════════════════
# Aerial Autonomy Stack Packages
# ═══════════════════════════════════════════════════════════════════════

class TestAASPackages:
    """Validate Aerial Autonomy Stack ROS2 packages."""

    def test_autopilot_interface_msgs_exists(self):
        assert (AAS_SRC / "autopilot_interface_msgs").is_dir(), \
            "autopilot_interface_msgs package missing"

    def test_autopilot_interface_exists(self):
        assert (AAS_SRC / "autopilot_interface").is_dir(), \
            "autopilot_interface package missing"

    def test_mission_package_exists(self):
        assert (AAS_SRC / "mission").is_dir(), \
            "mission package missing"

    def test_offboard_control_exists(self):
        assert (AAS_SRC / "offboard_control").is_dir(), \
            "offboard_control package missing"

    def test_yolo_py_exists(self):
        assert (AAS_SRC / "yolo_py").is_dir(), \
            "yolo_py package missing"

    def test_state_sharing_exists(self):
        assert (AAS_SRC / "state_sharing").is_dir(), \
            "state_sharing package missing"

    def test_imu_publisher_exists(self):
        assert (AAS_SRC / "imu_publisher").is_dir(), \
            "imu_publisher package missing"

    # ── Action definitions ──────────────────────────────────────────

    def test_takeoff_action_defined(self):
        action_file = AAS_SRC / "autopilot_interface_msgs" / "action" / "Takeoff.action"
        assert action_file.exists(), "Takeoff.action missing"
        content = action_file.read_text()
        assert "takeoff_altitude" in content

    def test_land_action_defined(self):
        action_file = AAS_SRC / "autopilot_interface_msgs" / "action" / "Land.action"
        assert action_file.exists(), "Land.action missing"

    def test_orbit_action_defined(self):
        action_file = AAS_SRC / "autopilot_interface_msgs" / "action" / "Orbit.action"
        assert action_file.exists(), "Orbit.action missing"

    def test_offboard_action_defined(self):
        action_file = AAS_SRC / "autopilot_interface_msgs" / "action" / "Offboard.action"
        assert action_file.exists(), "Offboard.action missing"

    # ── Service definitions ─────────────────────────────────────────

    def test_set_reposition_service_defined(self):
        srv_file = AAS_SRC / "autopilot_interface_msgs" / "srv" / "SetReposition.srv"
        assert srv_file.exists(), "SetReposition.srv missing"

    def test_set_speed_service_defined(self):
        srv_file = AAS_SRC / "autopilot_interface_msgs" / "srv" / "SetSpeed.srv"
        assert srv_file.exists(), "SetSpeed.srv missing"

    # ── Source files ────────────────────────────────────────────────

    def test_px4_interface_source(self):
        src = AAS_SRC / "autopilot_interface" / "src" / "px4_interface.cpp"
        assert src.exists(), "px4_interface.cpp missing"

    def test_mission_node_source(self):
        src = AAS_SRC / "mission" / "mission" / "mission_node.py"
        assert src.exists(), "mission_node.py missing"

    def test_mission_node_uses_actions(self):
        src = AAS_SRC / "mission" / "mission" / "mission_node.py"
        content = src.read_text()
        # Must use ROS2 actions, not raw MAVROS topics
        assert "ActionClient" in content, "Should use ROS2 ActionClient"
        assert "send_goal" in content, "Should use send_goal"


# ═══════════════════════════════════════════════════════════════════════
# PX4 SITL
# ═══════════════════════════════════════════════════════════════════════

class TestPX4Environment:
    """PX4 SITL must be built and available."""

    def test_px4_binary_exists(self):
        px4_bin = Path("/workspace/PX4-Autopilot/build/px4_sitl_default/bin/px4")
        assert px4_bin.exists(), \
            f"PX4 SITL binary missing. Build with: cd /workspace/PX4-Autopilot && make px4_sitl_default"

    def test_px4_romfs_exists(self):
        romfs = Path("/workspace/PX4-Autopilot/ROMFS/px4fmu_common")
        assert romfs.exists(), "PX4 ROMFS missing"


# ═══════════════════════════════════════════════════════════════════════
# MAVROS
# ═══════════════════════════════════════════════════════════════════════

class TestMAVROS:
    """MAVROS must be installed."""

    @pytest.fixture(scope="class")
    def pkg_list(self):
        return _ros2_pkg_list()

    def test_mavros_installed(self, pkg_list):
        assert "mavros" in pkg_list, "MAVROS not installed"

    def test_mavros_msgs_installed(self, pkg_list):
        assert "mavros_msgs" in pkg_list, "mavros_msgs not installed"


# ═══════════════════════════════════════════════════════════════════════
# Isaac Sim Integration Scripts
# ═══════════════════════════════════════════════════════════════════════

class TestIsaacSimScripts:
    """Validate Isaac Sim + Pegasus integration scripts."""

    def test_spawn_pegasus_drone_exists(self):
        assert (SCRIPTS_DIR / "spawn_pegasus_drone.py").exists(), \
            "spawn_pegasus_drone.py missing"

    def test_isaac_sim_pegasus_test_exists(self):
        assert (SCRIPTS_DIR / "isaac_sim_pegasus_test.py").exists(), \
            "isaac_sim_pegasus_test.py missing"

    def test_spawn_script_uses_ros2_backend(self):
        src = (SCRIPTS_DIR / "spawn_pegasus_drone.py").read_text()
        assert "ROS2Backend" in src or "ros2_backend" in src.lower(), \
            "Spawn script should use ROS2 backend for sensor publishing"
