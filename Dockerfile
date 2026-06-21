FROM ros:humble-ros-base-jammy

SHELL ["/bin/bash", "-c"]

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    git \
    python3-pip \
    python3-colcon-common-extensions \
    python3-rosdep \
    ros-humble-geographic-msgs \
    ros-humble-mavros-msgs \
    ros-humble-vision-msgs \
    libgeographic-dev \
    && rm -rf /var/lib/apt/lists/*
 
WORKDIR /workspace/aerial_ws

COPY ros2_ws ./ros2_ws
COPY external/aerial-autonomy-stack/ground/ground_ws/src/ground_system_msgs ./ros2_ws/src/ground_system_msgs

RUN source /opt/ros/humble/setup.bash && \
    cd /workspace/aerial_ws/ros2_ws && \
    rm -rf build install log && \
    colcon build --symlink-install --parallel-workers 2

CMD ["/bin/bash"]
