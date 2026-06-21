# Array of defect detections for a single frame
std_msgs/Header header
string drone_id
string zone_id

# All detections in this frame
pegasus_msgs/DefectDetection[] detections

# Summary counts
uint32 total_count
uint32 crack_count
uint32 corrosion_count
uint32 paint_damage_count

# Highest risk in this frame
string max_risk_level
uint8 max_risk_id

# Processing latency (seconds)
float32 inference_latency
float32 total_latency
