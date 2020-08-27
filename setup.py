from setuptools import setup, Extension

srcFiles = ["src/geneticOpt.c", "realcrossover.c", "realinitialization.c", "realmutation.c", "realreplacement.c", "realselection.c", "stdgen.c", "stdmath.c"]

includeDirs = ["include"]

setup(
    name = "geneticOpt", version = "0.0.1",
    ext_modules = [Extension("geneticOpt", srcFiles, include_dirs = includeDirs)]
)
