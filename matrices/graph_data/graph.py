import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import imageio
import sys
from os import listdir

def getXY(data, closeplot):
    x = []
    y = []
    for number in data:
        x.append(number[0])
        y.append(number[1])
    if closeplot:
        x.append(x[0])
        y.append(y[0])
    return [x, y]

if len(sys.argv) >= 3:
    gifname = sys.argv[1]
    input_location = sys.argv[2]
    output_location = sys.argv[3]
    
    closeplot = False 
    if len(sys.argv) == 5:
        closeplot = sys.argv[4]

    files = listdir(input_location)

    for filename in files:
        inpath = input_location + filename;
        outpath =  output_location + "\\images\\image_" + filename.split('.', 1)[0].rjust(5, '0') + ".png"
        data = pd.read_csv(inpath).values.tolist() 
        x,y = getXY(data, closeplot)
        plt.figure()
        plt.plot(x, y, color="black")
        plt.title("Wave: Step " + filename.split('.', 1)[0])
        plt.ylim([-2, 2])
        plt.savefig(outpath,  bbox_inches='tight')
        plt.close('all')
    
    with imageio.get_writer(output_location + "figures\\" + gifname, mode='I') as writer:
        files = listdir(output_location + "images\\")
        for filename in files:
            image = imageio.imread(output_location + "images\\" + filename)
            writer.append_data(image)


