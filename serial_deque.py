import sys, serial, argparse
import numpy as np
from time import sleep
from collections import deque

import matplotlib.pyplot as plt
import matplotlib.animation as animation



class AnalogPlot:
	def __init__(self, strPort, maxLen):
		#open serial port
		self.ser = serial.Serial(strPort , 9600)
		self.ax = deque([0.0]*maxLen)
		self.ay = deque([0.0]*maxLen)
		self.az = deque([0.0]*maxLen)
		self.maxLen = maxLen

	def addToBuf (self, buf, val):
		if len(buf) < self.maxLen:
			buf.append(val)
		else:
			buf.pop()
			buf.appendleft(val)

	def add(self, data):
		#add data
		assert(len(data) == 3)
		self.addToBuf(self.ax,(data[0]))
		self.addToBuf(self.ay,(data[1]))
		self.addToBuf(self.az,(data[2]))

	def update(self, frameNum, a0, a1, a2):
		try:
			line = self.ser.readline()
			data = [float(val) for val in line.split()]
			if(len(data) == 3) :
				self.add(data)
				a0.set_data(range(self.maxLen), self.ax)
				a1.set_data(range(self.maxLen), self.ay)
				a2.set_data(range(self.maxLen), self.az)
		except KeyboardInterrupt:
			print('exiting')

		return a0,

	def close(self) :
		self.ser.flush()
		self.ser.close()

def main():
	#create parser

	parser = argparse.ArgumentParser(description = "Sensor Data")
	# add expected arguments
	parser.add_argument('--port', dest='port', required=True)

	args = parser.parse_args()

	strPort = args.port

	print('reading from serial port %s...' %strPort)

	#plot parameters
	analogPlot = AnalogPlot(strPort, 100)

	print('plotting data...')

	#set up animation

	fig = plt.figure()
	ax= plt.axes(xlim=(0,100), ylim=(0,1023))
	a0, = ax.plot([], [])
	a1, = ax.plot([], [])
	a2, = ax.plot([], [])
	anim = animation.FuncAnimation(fig, analogPlot.update, fargs=(a0,a1,a2), interval=50)

	plt.show()
 	analogPlot.close()
 	print('exiting.')

if __name__ == '__main__' :
	main()
