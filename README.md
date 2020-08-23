# geneticOpt
The main idea of this project is develop a Python module for totally customizable genetic algorithms. This library will allow since basic to advanced users create their own genetic models in easy way. Focusing on computational performance, this module will be developed entirely in C language.

## The module in its first version
This module will initially suport the following components:

### Objective Function
Will be an exclusively user defined component. The user defines a Python function that evaluates an individual of the population.

### Representation
This module will suport the basic representation methods:
- Binary.
- Integer.
- Real.

### Population Initialization
Initially, this module will suport only random and heuristic initialization methods. The heuristic initialization will be a user defined Python function, like the objective function.

### Selection Strategy
Some classical selection methods:
- Roulett Wheel Selection.
- Tournament Selection.
- Rank-Based Selection.

### Reproduction Strategy
The usual reproduction strategies in genetic algorithms are:
- Crossover.
- Mutation.

These methods are very important and can be developed in many ways. Some classical aproachs are:
- n-point Crossover.
- Aritmethic Crossover.
- Uniform Random Mutation.

### Replacement Strategy
Initially, this module suports only the elitist replacement strategy (only de best individuas from the initial population and its offsprings survives to the next generation.)

## Some ideas for future releases
- Develop some tools for statistical analysis of the genetic model defined by the user. The objective of these tools are allow the user to modify his genetic model and tune the genetic parameters.
 