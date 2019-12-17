import urllib.request
import xml.etree.ElementTree as ET
import matplotlib.pyplot as plt

temp_readings = []
time_readings = []
response = urllib.request.urlopen("http://localhost:8080/")
data = response.read().decode()
root = ET.fromstring(data.strip("\n"))

for reading in root.findall('reading'):
    time = reading.find('time').text
    time_readings.append(time[time.find(' '):])
    temp_readings.append(int(reading.find('temperature').text))

plt.plot(time_readings, temp_readings,'green')
title_obj = plt.title("Temperature Vs Time")
plt.setp(title_obj, color='green', fontsize=20,fontname="Times New Roman",fontweight="bold")
plt.xticks(time_readings, rotation='horizontal')
plt.xlabel("Time")
plt.ylabel("Temperature")
plt.show()
