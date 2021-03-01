import geneticOpt as gOpt

def fitFunction(chrom):
    soma = 0
    for i in range(7):
        soma = soma + chrom[i]**2

    return soma

model = gOpt.realCodificationModel(objective= 'min', fitFunction= fitFunction,
                                   maxGenerations= 10000, populationSize= 500, totalFamilies= 250, totalParents= 2, childrensPerFamily= 2,
                                   chromosomeLength= 1000,
                                   initType= 'uniformRandom',
                                   selectionType= 'tournament',
                                   crossoverType= '3-Point', crossoverProb= 0.98,
                                   mutationType= 'uniformRandom', mutationProb= 0.05, alleleMutationProb= 0.01,
                                   replacementType= 'elitist')

ans = model.Solve()

ans
