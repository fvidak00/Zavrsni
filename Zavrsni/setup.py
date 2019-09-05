from distutils.core import setup, Extension

primes = Extension('primes',
                    sources = ['primes.c'])

setup(name = 'primes',
        version = '1.0',
        description = 'C functions for working with prime numbers.',
        ext_modules = [primes])