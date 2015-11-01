find_event <- function(data, width=5, direction="both",index=FALSE){
    min = min(data[,5])
    max = max(data[,5])
    tolerance = 1.5
    half = trunc(width/2)
    f_events = 0
    r_events = 0
    last_mean = mean(data[0:width,5])
    last_f = TRUE
    last_r = TRUE
    for(i in seq(width,(dim(data)[1]-half-1),by=width)){
        mean = mean(data[(i-half):(i+half),5]) 
        if( ((-tolerance) < (mean-last_mean)) #falling
          ){
            if(last_f == FALSE){
                if(index ==TRUE){
                    f_events = c(f_events,i)
                } else {
                    f_events = c(f_events,data[i,4])
                }
            }
            last_f = TRUE
        } else {
            last_f = FALSE
        }
        if( ((mean-last_mean) < (tolerance)) #rising
          ){
            if(last_r == FALSE){
                if(index ==TRUE){
                    r_events = c(r_events,i)
                } else {
                    r_events = c(r_events,data[i,4])
                }
            }
            last_r = TRUE
        } else {
            last_r = FALSE
        }
        last_mean = mean
    }
    f_events = f_events[-1]
    r_events = r_events[-1]
    if(direction == "falling"){
        events = f_events
    } else if(direction == "rising"){
        events = r_events
    } else {
        events = c(r_events,f_events)
    }
    return(events)
}

time_between_edges <- function(edges){
    time = edges[-1] #mainly for length purposes
    for(i in 2:length(edges) ){
        time[i-1] = edges[i] - edges[i-1]
    }
    time = time * 10^9 # nano seconds
    return(time)
}

rms <- function(data, limits=c(0,0)){
	if(limits[1] != 0){
		start = which(data[,4]>limits[1])[1]
		end   = which(data[,4]>limits[2])[1] - 1
	} else {
		start = 0
		end = length(data[,4])
	}
    n = length(data[start:end,5])
    v = sqrt(1/n * sum( data[start:end,5] * data[start:end,5] ) )
    return(v)
}

bit_value <- function(data_signal, clock_signal, start_edge, clock_skips=0, clocks, CS=matrix(0,2,5),plot=FALSE){
    clk_rising_edge = find_event(clock_signal,direction="rising",index=TRUE)
    if(length(clk_rising_edge) < (clocks+clock_skips)){ stop("Error: The signal has not been meassured for that long") }
    logic_low  = 0.7 
    logic_high = 2.5
    clk_falling_edge = find_event(clock_signal,direction="falling")
    start = which(clk_falling_edge>start_edge)[1] #first clk falling edge after CS
    start = which(data_signal[,4]>clk_falling_edge[start])[1]
    
    pulse_width = clk_rising_edge[2] - clk_rising_edge[1] #280 ns
    read_time = trunc(pulse_width)/4
    start = start + read_time
    bit_val = c("0b")
            read_points = 0
            data_amplitude = 0
    for(i in clock_skips:(clocks-1)){ #7:16
        index = start+i*pulse_width
                read_points = c(read_points, data_signal[index,4])
                data_amplitude = c(data_amplitude, data_signal[index,5])
        if(data_signal[index,5] > logic_high){
            bit_val = c(bit_val,"1")
        } else if(data_signal[index,5] < logic_low){
            bit_val = c(bit_val,"0")
        } else {
            bit_val = c(bit_val,"U")
        }
    }
    
    if(plot){
        read_points = read_points[-1]
        data_amplitude = data_amplitude[-1]
        par(mfrow=c(3,1),
            oma=c(0,0,0,0)+0.1, 
            mar=c(0,0,0.1,0.1)+0.1)
        plot(clock_signal[,4],clock_signal[,5],type="l",col="blue",axes=FALSE)
        points(clock_signal[start,4],2,type="p",col="red")
        plot(CS[,4],CS[,5],type="l",col="orange",axes=FALSE)
        plot(data_signal[,4],data_signal[,5],type="l")
        lines(read_points,data_amplitude,type="p",col="red")
        par(mfrow=c(1,1),oma=c(2,0,0,0)+0.1, mar=c(4,4,4,1)+0.1)
    }
    return(paste(bit_val,collapse=""))
}

binary_to_int <- function(bit_string){
    int = 0;
    split = strsplit(bit_string, "")[[1]]
    garbage = FALSE
    
    for(bit in 3:length(split)) { #ignoring the 0b
        int = int * 2 #leftshift
        if(split[bit] == "1"){
            int = int + 1 #add one
        } else if(split[bit] == "0"){
            # do nothing
        } else {
            garbage = TRUE
        }
    }
    if(garbage){
        int = -1
    }
    return(int)
}
bin <- function(number, length){
	res = paste( c("\"", sapply(strsplit(paste(rev(intToBits(number))[-(1:(32 - length))]),""),`[[`,2) ,"\"\n"), collapse="")
	return(res)
}

as_bin <- function(numbers,length=10){
	res = array("nan",length(numbers))
	for( i in 1:length(numbers) ){
		res[i] = bin(numbers[i],length) 
	}
	return(res)
}
