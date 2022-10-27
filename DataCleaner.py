#Python script to split SMHI open data into separate text files based on content, and
#calculate mean or median temperatures per year and saves to text files. 
#Author: Love Kildetoft
import numpy as np
import glob as gb
import dateutil.parser as ps
#Define function which loads a file and parses it into an array. Skips unimportant rows.
def Cleaner(fname:'str') -> 'np.ndarray':
    fileArr = np.loadtxt(fname, dtype=str, skiprows=26, delimiter=";")
    return fileArr
#Loop over filenames and save as txt:s depending on column name. 
def dataProcessor(fname:'str', yRange:'list', median:'bool' = False) -> 'tuple(np.ndarray)':
    print("Processing dataset " + fname)
    cleanData = Cleaner(fname)
    years = np.empty(len(cleanData), dtype = int)
    temps = np.empty(len(cleanData), dtype = float)
    selYears = []
    meanTemps = []

    for i in range(0, len(cleanData)):
        years[i] = int(ps.parse(cleanData[i][0]).year)
        temps[i] = cleanData[i][2]
    #Calculate mean/median for each year
    for year in yRange:
        idxs = np.where(years == year)
        if median == True:
            mean = np.median(temps[idxs])
        else:
            mean = np.mean(temps[idxs])

        if np.isnan(mean) == False:
            meanTemps.append(mean)
            selYears.append(int(year))
        else: 
            continue
    
    #Calculate error bars
    stdErr = [np.sqrt(((a - np.mean(meanTemps))**2)/(len(meanTemps) - 1)) for a in meanTemps] 
    print("Done")
    return np.array(selYears), np.array(meanTemps), np.array(stdErr)
#Read names of all CSV files in folder, store filenames as array.
fnames = np.array(gb.glob("*.csv"))
years = range(1942, 2021)
#Loop over filenames and save files
for fname in fnames:
    selYears, meanTemps, meanStd = dataProcessor(fname, years)
    medYears, medTemps, medStd = dataProcessor(fname, years, median = True)
    #Save files
    np.savetxt("meanY_" + fname.split("_")[5].split(".")[0] + ".txt", selYears, fmt='%s')
    np.savetxt("meanT_" + fname.split("_")[5].split(".")[0] + ".txt", meanTemps)
    np.savetxt("meanErr_" + fname.split("_")[5].split(".")[0] + ".txt", meanStd)
    np.savetxt("medianY_" + fname.split("_")[5].split(".")[0] + ".txt", medYears, fmt='%s')
    np.savetxt("medianT_" + fname.split("_")[5].split(".")[0] + ".txt", medTemps)
    np.savetxt("medErr_" + fname.split("_")[5].split(".")[0] + ".txt", medStd)
