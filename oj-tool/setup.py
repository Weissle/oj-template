from setuptools import setup, find_packages

setup(
    name='ojt',
    version='0.0.1',
    description='A tool for oj (oj-tool).',
    author='weissle',
    packages=['ojt'],
    install_requires=[],
    entry_points={
        'console_scripts':[
            'ojt = ojt.main:main'
        ]
    }

)
