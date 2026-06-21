# Crane zone definition for mission planning
std_msgs/Header header
string zone_id
string zone_name
string zone_type          # "beam", "column", "cable", "joint", "custom"

# 3D bounding box of zone (in world frame)
geometry_msgs/Pose zone_center
geometry_msgs/Vector3 zone_dimensions

# Inspection parameters
float32[] waypoints_x
float32[] waypoints_y
float32[] waypoints_z
float32[] waypoints_yaw

# Camera angles for this zone
float32[] camera_pitch
float32[] camera_yaw

# Expected defect types in this zone
string[] expected_defects

# Priority
uint8 priority            # 1=high, 2=medium, 3=low
