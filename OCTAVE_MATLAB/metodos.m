function result = absoluteError(value, approximate)
    result = abs(value - approximate);
endfunction

function result = relativeError(value, approximate)
    errA = absoluteError(value, approximate);
    result = errA / abs(approximate);
endfunction

function result = DIGSE(value, approximate, base, precision)
    errR = relativeError(value, approximate);
    %científico
    mi = 0.5 *  power(base, 1 - precision);
    result = - (0.3 +  log10(mi + errR));
endfunction

function result = newton(value, approximate, numberOfIterations, base, precision)

    prec = power(base, 1 - precision);
    iterations = 0;
    while(iterations < numberOfIterations)

        nextValue = 0.5 * (approximate + value/approximate);

        errA = absoluteError(nextValue, approximate);    
        if(le(errA, prec))
            iterations++;
        endif

        approximate = nextValue;
    endwhile

    result = value;
endfunction

DIGSE(sqrt(2), 1.4142, 10, 5)
