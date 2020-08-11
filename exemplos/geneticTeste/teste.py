import geneticOpt as gOpt

model = gOpt.realCodificationModel(popSize = 10, numGenerations = 50,
                                   chromosomeLenght = 4, crossoverProb = 0.999,
                                   mutationProb = 0.6)

model.Solve()

model.getSolution()
