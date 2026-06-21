from setuptools import find_packages, setup

package_name = "pegasus_ai"

setup(
    name=package_name,
    version="0.1.0",
    packages=find_packages(exclude=["test"]),
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        ("share/" + package_name + "/launch", ["launch/inference.launch.py"]),
        ("share/" + package_name + "/config", ["config/inference.yaml"]),
    ],
    install_requires=["setuptools"],
    zip_safe=False,
    maintainer="Pegasus Team",
    maintainer_email="user@pegasus.local",
    description="AI inference node for Pegasus drone inspection",
    license="Apache-2.0",
    entry_points={
        "console_scripts": [
            "inference_node = pegasus_ai.inference_node:main",
            "mock_camera_node = pegasus_ai.mock_camera_node:main",
            "test_publisher = pegasus_ai.test_publisher:main",
            "isaac_sim_listener = pegasus_ai.isaac_sim_listener:main",
            "vslam_nav2_mock = pegasus_ai.vslam_nav2_mock:main",
        ],
    },
)
