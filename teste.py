import geneticOpt as gOpt

def fitFunction(chrom):
    soma = 0
    for i in range(7):
        soma = soma + chrom(i)**2

    return soma

model = gOpt.realCodificationModel(objective= 'min', fitFunction= fitFunction,
                                   maxGenerations= 100, populationSize= 20, totalFamilies= 10, totalParents= 2, childrensPerFamily= 2,
                                   chromosomeLength= 7,
                                   initType= 'uniformRandom',
                                   selectionType= 'tournament',
                                   crossoverType= '3-Point', crossoverProb= 0.98,
                                   mutationType= 'uniformRandom', mutationProb= 0.05, alleleMutationProb= 0.01,
                                   replacementType= 'elitist')

ans = model.Solve()

ans
