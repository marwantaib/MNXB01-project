# The temperature trend in Sweden throughout the ages: a qualitative investigation using SMHI open data
## Final project in MNXB01: Introduction to programming and computing for scientists

#### Project introduction

The Swedish Meteorological and Hydrological institute (SMHI) regularly provides datasets open to the general public, which contain several variables which the institute monitors. One such variable is temperature, which has been regurarly measured in several swedish cities since the late 1800s.
It is well known that there is an ever increasing trend towards higher temperatures, owing to global warming. 
In this project we investigate the temperature trend in three swedish cities (Falun, Lund and Karlstad) over the period from 1942-2021. 

#### Code 

The project is implemented in Python 3.10 as well as in C++ using the Numpy library for calculations and the ROOT library for graphics (https://root.cern).

##### Dependencies

ROOT (https://root.cern), Numpy (https://numpy.org), Python (https://www.python.org) (the anaconda distribution of python conveniently include both of these, see https://www.anaconda.com), C++ compiler (eg. https://gcc.gnu.org or built in ROOT compiler). For installation see links.

The outline/functionality is as follows:

*DataCleaner.py: This script performs the necessesary computations for our investigation and cleans the data by splitting it into separate textfiles, for easy analysis in ROOT. 
The script firstly parses all CSV-files in the folder and splits column by column. It then extracts the relevant years as integer-type and the corresponding temperatures. These are then averaged using Numpy, and the std-error is also found element wise. 
Finally, all data is saved to text files (.txt). 

*dataprocessing.C: ROOT macro which takes the filename of a txt as input and returns a vector of doubles. This is the next step after running DataCleaner.py

*plotting.C: ROOT macro for plotting the subsequent cleaned data. 

*fitter.h: Header file containing functions for fitting the data. 

*dataprocessor.cpp and dataprocessor.h: deprecated as of now, irrelevant. 

#### How to run/install

Step 0: Install all dependencies following the instructions at the webpages in the dependencies section above. 

Step 1: Place all CSV-files you want to perform analysis on in the same folder as all of the code. 

Step 2: Open up a terminal and navigate to the project folder. Run DataCleaner.py by typing Python3 DataCleaner.py in the terminal. Let the script finish, this should produce a number of .txt files containing mean values, median values and the corresponding years. 

Step 3: Modify the filepath in each method in dataprocessing.C to the file you want to point to. 

Step 4: Compile plotting.C by running ROOT and then typing .L plotting.C in the ROOT prompt. 

Step 5: Type plot_graph(date(), temp(), err()) in the ROOT prompt and press enter. This should produce a plot which can then be saved. 
