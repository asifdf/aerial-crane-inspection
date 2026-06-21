# AI inference node health status
std_msgs/Header header
string node_name
string device_id          # e.g., "jetson_orin_nano_super"

# Performance metrics
float32 fps
float32 avg_latency_ms
float32 p95_latency_ms
float32 p99_latency_ms

# Resource usage
float32 gpu_util_percent
float32 gpu_mem_used_mb
float32 gpu_mem_total_mb
float32 cpu_util_percent
float32 cpu_mem_used_mb
float32 cpu_mem_total_mb
float32 temperature_c

# Model info
string model_path
string model_version
string precision          # "fp32", "fp16", "int8"
uint32 input_width
uint32 input_height

# Counters
uint64 frames_processed
uint64 detections_published
uint64 errors_count
uint64 last_error_time

# Status
string status             # "healthy", "degraded", "error", "starting"
string[] active_alerts
