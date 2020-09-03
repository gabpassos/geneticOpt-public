from setuptools import setup, Extension

srcFiles = [
    "src/geneticOpt.c",
    "src/realcrossover.c",
    "src/realinitialization.c",
    "src/realmutation.c",
    "src/realreplacement.c",
    "src/realselection.c",
    "src/stdgen.c", "src/stdmath.c"]

includeDirs = ["include"]

setup(
    name = "geneticOpt", version = "0.0.1",
    ext_modules = [Extension("geneticOpt", srcFiles, include_dirs = includeDirs)]
)
