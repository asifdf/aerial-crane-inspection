# Single defect detection result
std_msgs/Header header

# Classification
string type              # "crack", "corrosion", "paint_damage"
uint8 CLASS_CRACK = 0
uint8 CLASS_CORROSION = 1
uint8 CLASS_PAINT_DAMAGE = 2
uint8 class_id

# Confidence [0.0, 1.0]
float32 confidence

# Bounding box in pixel coordinates (top-left origin)
float32 bbox_x
float32 bbox_y
float32 bbox_width
float32 bbox_height

# Optional: normalized bbox [0,1] for resolution-invariant use
float32 bbox_x_norm
float32 bbox_y_norm
float32 bbox_width_norm
float32 bbox_height_norm

# Risk assessment
string risk_level        # "low", "medium", "high", "critical"
uint8 RISK_LOW = 0
uint8 RISK_MEDIUM = 1
uint8 RISK_HIGH = 2
uint8 RISK_CRITICAL = 3
uint8 risk_id

# Optional segmentation mask (compressed PNG)
sensor_msgs/CompressedImage mask

# 3D position estimate (if depth available)
geometry_msgs/Point position_3d
bool has_3d_position
