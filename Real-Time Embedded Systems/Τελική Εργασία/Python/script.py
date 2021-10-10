import csv
from datetime import datetime
import matplotlib.pyplot as plt

delays = []
timestamps = []
reference = 0
time = 0
ref = [0,0]
with open('./times.csv') as csv_file:
    csv_reader = csv.reader(csv_file,delimiter = ';')
    line_count = 0
    rows = 0
    timer = 0.1
    for i in csv_reader:
        if (rows == 0):
            ref[0], ref[1] = i[0], i[1]
            reference = float(ref[0])/1.0 + float(ref[1])/1000000
        else:
            sec, microsec = i[0], i[1]
            time = float(sec)/1.0 + float(microsec)/1000000
            delay = time - (reference + timer * rows)
            if( abs(delay * 1000000) < 3000):
                delays.append(delay * 1000000)
            dt = datetime.fromtimestamp(time)
            timestamps.append(dt)
        rows = rows + 1


plt.rcParams.update({'figure.figsize':(7,5), 'figure.dpi':100})
plt.hist(delays, bins=500, align='left', density=True)        
plt.gca().set(title='Frequency Histogram of Delays', ylabel='Frequency', xlabel = 'delays in us');
plt.show()

