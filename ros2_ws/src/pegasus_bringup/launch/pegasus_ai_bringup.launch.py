from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    inference_node = Node(
        package="pegasus_ai",
        executable="inference_node",
        name="defect_inference",
        parameters=[
            {
                "model_type": "mock",
                "input_image_topic": "/pegasus/inspection_camera/color/image_raw",
                "output_detections_topic": "/pegasus/ai/defect_detections",
                "output_defect_array_topic": "/pegasus/ai/defect_array",
                "output_json_topic": "/pegasus/ai/defect_json",
                "output_health_topic": "/pegasus/ai/node_health",
                "annotated_image_topic": "/pegasus/ai/annotated_image",
                "max_publish_rate": 30.0,
            }
        ],
        output="screen",
        emulate_tty=True,
    )

    return LaunchDescription([inference_node])
