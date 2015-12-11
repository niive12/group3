graph  = read.csv('timing2.csv',header = FALSE)[,1]
timing = read.csv('timing2.csv',header = FALSE)[,2]

figwidth = 10
figheight = 5



offset = 0.4
lim = 25
setEPS()
postscript("../Report/img/micoban_timing.eps",width=figwidth,height=figheight)
par(mfrow=c(1,1),oma=c(0,0,0,0), mar=c(4,4,1,0)+0.1)
mid_bar = barplot(timing,ylim=c(0,lim), xpd=FALSE,xlab="microban level", ylab="time [s]")
for( i in 1:length(timing) ){
	if(timing[i] > lim && timing[i] < 99999){
		text(mid_bar[i-2],lim-3, labels=paste(c(timing[i]," s"),collapse=""), srt=90)
		print(i)
	} else if(timing[i] == 99999 ){
		rect(mid_bar[i]-offset,0,mid_bar[i]+offset,lim,angle=90, col="red")
	} else if(i == 155){
		rect(mid_bar[i]-offset,0,mid_bar[i]+offset,timing[i],angle=90, col="red")
	}
}
q = dev.off()
for(i in 1:length(timing) ){ #one outlier and they all seem to be in the same spot
	if(timing[i] > 25){
		timing[i] = 0
		graph[i] = 0
	}
}
setEPS()
postscript("../Report/img/time_vs_graph_size.eps",width=figwidth,height=figheight)
plot(graph,timing, xlab="graph size [nodes]",ylab="time [s]")
q = dev.off()

graph_size  = read.csv('timing_inc_competetion.csv',header = FALSE)[,1]
time = read.csv('timing_inc_competetion.csv',header = FALSE)[,2]


setEPS()
postscript("../Report/img/sokoban_complexity_graph_size.eps",width=figwidth,height=figheight)
plot(1:length(graph_size), graph_size,type="b", ylab="Graph size [nodes]",xlab="Number of diamonds")
q=dev.off()
setEPS()
postscript("../Report/img/sokoban_complexity_time.eps",width=figwidth,height=figheight)
plot(1:length(time), time,type="b", ylab="Time [s]",xlab="Number of diamonds")
q=dev.off()