from math import sqrt, log10

def absoluteError(value, approximate):
    return abs(value -  approximate)

def relativeError(value, approximate):
    errA = absoluteError(value, approximate)
    return errA/abs(approximate)

def DIGSE(value, approximate):
    errR = relativeError(value, approximate)
    precision = len(str((approximate))) - 1
    mi = 0.5 * pow(10, 1 - precision)
    return - (0.3 + log10(mi + errR))

#def huatRule(polinomn):


value = sqrt(2)
approximate = 1.4142



if __name__ == "__main__":
    aux = DIGSE(value,approximate)
    print(aux)
    print(len(str((approximate)))-1)