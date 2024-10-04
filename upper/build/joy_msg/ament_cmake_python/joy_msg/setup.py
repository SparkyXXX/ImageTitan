from setuptools import find_packages
from setuptools import setup

setup(
    name='joy_msg',
    version='0.0.0',
    packages=find_packages(
        include=('joy_msg', 'joy_msg.*')),
)
