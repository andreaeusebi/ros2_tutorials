from setuptools import find_packages, setup

package_name = 'py_custom_srv_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='andrea',
    maintainer_email='andrea@example.com',
    description='Python nodes that use a custom service',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'py_custom_server = py_custom_srv_pkg.py_custom_server:main',
            'py_custom_client = py_custom_srv_pkg.py_custom_client:main',
        ],
    },
)
