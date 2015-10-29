library(stringr)
source('functions.R')

cat("---------- Proof of concept ----------\n")
scope_clk = 3; scope_vin = 1; scope_cs = 2; scope_miso = 4; 
i = 21

scope = scope_vin
filename = paste(c("data/C",scope,"adc_testttt",str_pad(i, 5, pad="0"),".csv"),collapse="")
vin = read.csv(filename,skip=6)
cat("v_in rms: ",rms(vin),"\n")

scope = scope_clk
filename = paste(c("data/C",scope,"adc_testttt",str_pad(i, 5, pad="0"),".csv"),collapse="")
clk = read.csv(filename,skip=6)
clk_events = find_event(clk,direction="rising")
time_between_edges(clk_events)
cat(c("The signal was meassured in : ",length(clk_events), " clock cycles\n"))
# plot(clk[,4],clk[,5],type="l")
# lines(clk_events,array(2.5,length(clk_events),1),type="p",col="red")

scope = scope_cs
filename = paste(c("data/C",scope,"adc_testttt",str_pad(i, 5, pad="0"),".csv"),collapse="")
cs = read.csv(filename,skip=6)
cs_events = find_event(cs,direction="falling")
time_between_edges(cs_events)
cat(c("The signal was meassured for: ",length(cs_events)-1, " transmissions\n"))
plot(cs[,4],cs[,5],type="l")
lines(cs_events,array(2.5,length(cs_events),1),type="p",col="red")

scope = scope_miso
filename = paste(c("data/C",scope,"adc_testttt",str_pad(i, 5, pad="0"),".csv"),collapse="")
miso = read.csv(filename,skip=6)

setEPS()
postscript("../Rapport_LegoSorter/img/scope_adc.eps",height = 8, width = 8)
bit = bit_value(data_signal = miso, clock_signal= clk, start_edge = cs_events[1], clock_skips=7, clocks=17, CS=cs,plot=TRUE)
print(bit)
print(binary_to_int(bit))
q=dev.off()
# plot(miso[,4],miso[,5],type="l")

number_of_meassurements = 34
bit_value_vs_vin = matrix(0,number_of_meassurements,2)
for(i in 1:number_of_meassurements){
        filename = paste(c("data/C",scope_clk,"adc_testttt",str_pad(i, 5, pad="0"),".csv"),collapse="")
        clk = read.csv(filename,skip=6)
        filename = paste(c("data/C",scope_cs,"adc_testttt",str_pad(i, 5, pad="0"),".csv"),collapse="")
        cs = read.csv(filename,skip=6)
        filename = paste(c("data/C",scope_miso,"adc_testttt",str_pad(i, 5, pad="0"),".csv"),collapse="")
        miso = read.csv(filename,skip=6)
        filename = paste(c("data/C",scope_vin,"adc_testttt",str_pad(i, 5, pad="0"),".csv"),collapse="")
        vin = read.csv(filename,skip=6)
        
        cs_events = find_event(cs,direction="falling")
        bit = bit_value(data_signal = miso, clock_signal= clk, start_edge = cs_events[1], clock_skips=7, clocks=17)
        bit_value_vs_vin[i,1] = binary_to_int(bit)
        bit_value_vs_vin[i,2] = rms(vin)
        print(bit_value_vs_vin[i,])
}

adc_value  = bit_value_vs_vin[,1]
v_in       = bit_value_vs_vin[,2]
setEPS()
postscript("../Rapport_LegoSorter/img/ADC_values.eps",height = 4, width = 8)
plot(v_in,adc_value,type="l")
q=dev.off()