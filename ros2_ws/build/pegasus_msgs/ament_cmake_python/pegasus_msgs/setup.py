from setuptools import find_packages
from setuptools import setup

setup(
    name='pegasus_msgs',
    version='0.1.0',
    packages=find_packages(
        include=('pegasus_msgs', 'pegasus_msgs.*')),
)
