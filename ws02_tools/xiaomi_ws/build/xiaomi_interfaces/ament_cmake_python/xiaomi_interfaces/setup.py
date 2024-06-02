from setuptools import find_packages
from setuptools import setup

setup(
    name='xiaomi_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('xiaomi_interfaces', 'xiaomi_interfaces.*')),
)
