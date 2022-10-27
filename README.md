# The temperature trend in Sweden during the COVID19 pandemic: a qualitative investigation using SMHI open data
## Final project in MNXB01: Introduction to programming and computing for scientists

#### Project introduction

The Swedish Meteorological and Hydrological institute (SMHI) regularly provides datasets open to the general public, which contain several variables which the institute monitors. One such variable is temperature, which has been regurarly measured in several swedish cities since the late 1800s.
It is well known that there is an ever increasing trend towards higher temperatures, owing to global warming. Recent research has however indicated that this trend might have been temporarily broken during the worldwide COVID19 pandemic. Even though these effects may not have been significant to alter the prognosis for climate change, it is interesting to see if a similar effect was seen in Sweden as the government never imposed any strict lockdowns. The main cause of the decrease in greenhouse gas emissions is generally attributed to lockdowns, as these led to less travel and economic activities both domestically and internationally. 
In this project we investigate the temperature trend in three swedish cities (Falun, Lund and Karlstad) over the period from 1942-2021. 

#### Code 

The project is implemented in Python 3.10 as well as in C++ using the Numpy library for calculations and the ROOT library for graphics (https://root.cern).

##### Dependencies

ROOT (https://root.cern), Numpy (https://numpy.org), Python (https://www.python.org), C++ compiler (eg. https://gcc.gnu.org or built in ROOT compiler). For installation see links.

The outline/functionality is as follows:

*DataCleaner.py: This script performs the necessesary computations for our investigation and cleans the data by splitting it into separate textfiles, for easy analysis in ROOT. 
The script firstly parses all CSV-files in the folder and splits column by column. It then extracts the relevant years as integer-type and the corresponding temperatures. These are then averaged using Numpy, and the std-error is also found element wise. 
Finally, all data is saved to text files (.txt). 

*dataprocessing.C: ROOT macro which takes the filename of a txt as input and returns a vector of doubles. This is the next step after running DataCleaner.py

