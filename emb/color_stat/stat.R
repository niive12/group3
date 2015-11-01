library(stringr)
source('../statistics/functions.R')

cat("---------- Proof of concept ----------\n")
analog_v = 1; scope_red = 2; scope_blue = 4; scope_green = 3; 
# i = 6 #5:8 is available

fileName = "../statistics/vin_vs_adc_value.RData"
if ( file.exists(fileName) ) {
	print(paste(c("reading vin and adc values ", fileName),collapse=""))
	load(fileName)
} else {
	stop("no such file, run statistics on adc_values first")
}

for(i in 5:8){
meassured_start = 17*3 * 280 * 10^-9
meassured_end   = 19*3 * 280 * 10^-9

csv_name = "analog_output"
folder_name = ""

scope = analog_v
filename = paste(c(folder_name,"C",scope,csv_name,str_pad(i, 5, pad="0"),".csv"),collapse="")
op_amp_out = read.csv(filename,skip=6)


scope = scope_red
filename = paste(c(folder_name,"C",scope,csv_name,str_pad(i, 5, pad="0"),".csv"),collapse="")
light_red = read.csv(filename,skip=6)
red_events = find_event(light_red,direction="rising")

adc_read_start = red_events[1]+meassured_start
adc_read_end   = red_events[1]+meassured_end
red_value = rms(op_amp_out, limits=c(adc_read_start,adc_read_end))

scope = scope_green
filename = paste(c(folder_name,"C",scope,csv_name,str_pad(i, 5, pad="0"),".csv"),collapse="")
light_green = read.csv(filename,skip=6)
green_events = find_event(light_green,direction="rising")

adc_read_start = green_events[1]+meassured_start
adc_read_end   = green_events[1]+meassured_end
green_value = rms(op_amp_out, limits=c(adc_read_start,adc_read_end))

scope = scope_blue
filename = paste(c(folder_name,"C",scope,csv_name,str_pad(i, 5, pad="0"),".csv"),collapse="")
light_blue = read.csv(filename,skip=6)
blue_events = find_event(light_blue,direction="rising")

adc_read_start = blue_events[1]+meassured_start
adc_read_end   = blue_events[1]+meassured_end
blue_value = rms(op_amp_out, limits=c(adc_read_start,adc_read_end))

if( i == 6 ) { #print green to the report
setEPS()
postscript("../Rapport_LegoSorter/img/analog_values.eps",height = 4, width = 8)
plot(op_amp_out[,4],op_amp_out[,5],ylim=c(0,3.3),type="l",col="yellow",xlab="time [s]",ylab="Voltage [V]")
lines(light_red  [,4],light_red  [,5],type="l",col="red")
lines(light_green[,4],light_green[,5],type="l",col="green")
lines(light_blue [,4],light_blue [,5],type="l",col="blue")
q=dev.off()
}
block_value = c(red_value,green_value,blue_value)

print(block_value)
block_value[1] = adc_value[which(v_in>red_value)[1]]
block_value[2] = adc_value[which(v_in>green_value)[1]]
block_value[3] = adc_value[which(v_in>blue_value)[1]]

# print(block_value)
cat(c(as_bin(block_value,length=10),"\n"))
}