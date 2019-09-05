def SieveOfEratosthenes(n): 

    # Kreirati niz boolean vrijednosti "allNumberToN[0..n]"
    # i incijalizirati sve kao True.
    # Ako je 'i' prosti broj, vrijednost na AllNumberToN[i] će biti True,
    # a ako je složeni False.
    # primes[] lista sadrži proste brojeve. 

    allNumbersToN = [True for i in range(n + 1)] 
    primes = []

    #Brojevi 0 i 1 nisu prosti brojevi po definiciji prostih brojeva.
    allNumbersToN[0]= False
    allNumbersToN[1]= False

    p = 2

    #Optimizacija algoritma
    while (p * p <= n): 
          
        # Ako prime[p] nije promjenjen onda je prosti broj
        if (allNumbersToN[p] == True): 
            primes.append(p)
            # Označavanje sve višekratnika broja p kao složenih
            for i in range(p * 2, n + 1, p): 
                allNumbersToN[i] = False
        p += 1

    return primes

    # Print all prime numbers 
    """ for p in range(n + 1): 
        if prime[p]:
            print (p) """

# driver program 
if __name__=='__main__': 
    n = 10**8
    prostiBrojevi = SieveOfEratosthenes(n) 