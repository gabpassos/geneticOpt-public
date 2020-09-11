import geneticOpt as gOpt

def fitFunction(chrom):
    soma = 0
    for i in range(7):
        soma = soma + chrom[i]**2

    return soma

model = gOpt.realCodificationModel(objective= 'max', fitFunction= fitFunction,
                                   maxGenerations= 10, populationSize= 6, totalFamilies= 3, totalParents= 2, childrensPerFamily= 2,
                                   chromosomeLength= 7,
                                   initType= 'uniformRandom',
                                   selectionType= 'tournament',
                                   crossoverType= '3-Point', crossoverProb= 0.995,
                                   mutationType= 'uniformRandom', mutationProb= 0, alleleMutationProb= 0.001,
                                   replacementType= 'elitist')

model.Solve()
