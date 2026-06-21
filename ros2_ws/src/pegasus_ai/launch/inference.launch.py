from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    # Launch arguments
    model_path_arg = DeclareLaunchArgument(
        "model_path",
        default_value="/opt/models/hybrid_fp16.trt",
        description="Path to TensorRT engine file",
    )

    config_file_arg = DeclareLaunchArgument(
        "config_file",
        default_value=PathJoinSubstitution(
            [FindPackageShare("pegasus_ai"), "config", "inference.yaml"]
        ),
        description="Path to inference config YAML",
    )

    namespace_arg = DeclareLaunchArgument(
        "namespace", default_value="", description="ROS2 namespace"
    )

    log_level_arg = DeclareLaunchArgument(
        "log_level", default_value="INFO", description="Log level"
    )

    def launch_setup(context, *args, **kwargs):
        namespace = LaunchConfiguration("namespace").perform(context)
        config_file = LaunchConfiguration("config_file").perform(context)
        model_path = LaunchConfiguration("model_path").perform(context)
        log_level = LaunchConfiguration("log_level").perform(context)

        inference_node = Node(
            package="pegasus_ai",
            executable="inference_node",
            name="defect_inference",
            namespace=namespace,
            parameters=[config_file, {"model_path": model_path}],
            arguments=["--ros-args", "--log-level", log_level],
            output="screen",
            emulate_tty=True,
        )

        return [inference_node]

    return LaunchDescription(
        [
            model_path_arg,
            config_file_arg,
            namespace_arg,
            log_level_arg,
            OpaqueFunction(function=launch_setup),
        ]
    )
