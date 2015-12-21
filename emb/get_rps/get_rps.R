std_logic_vector <- function(integer, length=21){
    number = matrix(0,1,length)
    for( i in length:1 ){
        integer = integer * 2;
        if(integer >= 2^length){
            integer = integer - 2^length
            number[i] = 1;
        }
    }
    return(number)
}

print_bin <- function(logic_vector){
    for( i in dim(logic_vector)[2]:1 ){
        cat(logic_vector[i])
    }
    cat("\n")
}

greater_equal <- function(a, b){
    for(i in dim(a)[2]:1){
        if(a[i] == 1 && b[i] == 0){
            return(TRUE)
        } else if (b[i] == 1 && a[i] == 0){
            return(FALSE)
        }
    }
}

to_integer <- function(a){
    res = 0
    for(i in (dim(a)[2]-1):0){
        if(a[i+1] == 1){
           res = res + 2^i
        }
    }
    return(res)
}

subtract <- function(a,b){
    int_a = to_integer(a)
    int_b = to_integer(b)
    res = int_a-int_b
    
    return(std_logic_vector(res,dim(a)[2]))
}

get_rps <- function(counter){
    num  = std_logic_vector(1666666)
    den  = std_logic_vector(counter,17)
    rest = matrix(0,1,17)
    ans  = matrix(0,1,6)
    rest[1:15] = num[7:21]
    for( i in 6:1 ){
        rest[2:17] = rest[1:16]
        rest[1] = num[i]
        if(greater_equal(rest,den)){
            rest = subtract(rest,den)
            ans[i] = 1;
        }
    }
    print_bin(ans)
    return(ans)
}

q = c(1,1,0,1,1,0,0,1,0,0,0,0,0,0,1,1)
q = matrix(q,1,length(q))
to_integer(q)

print_bin(std_logic_vector(1666666))
print_bin(std_logic_vector(49307))
a = get_rps(49307)
to_integer(a)
