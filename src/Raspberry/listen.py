import serial # Serial library 
import time   # Time library
import sys

#ser = serial.Serial('/dev/ttyACM0',9600) # Serial path also for the raspberry
ser = serial.Serial('COM3',9600)

while True:
    scoreOne= ser.readline() # get first datas from Serial
    scoreTwo= ser.readline() # get second datas from Serial

    file = open("scores.txt","a") # open the stream
    timeScore=time.strftime("%d/%m/%Y") # get time
    message = (timeScore+'\nplayerOne: '+scoreOne.decode("utf-8")+'playerTwo: '+scoreTwo.decode("utf-8")+'---\n').encode()
    file.write(message.decode("utf-8"))
    file.close() # close the stream

