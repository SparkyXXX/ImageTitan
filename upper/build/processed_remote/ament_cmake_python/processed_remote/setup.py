from setuptools import find_packages
from setuptools import setup

setup(
    name='processed_remote',
    version='0.0.0',
    packages=find_packages(
        include=('processed_remote', 'processed_remote.*')),
)
