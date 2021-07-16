# Fourier Transform Drawing

**Note : Detail Information can be found on Proposal and Report.**

## Abstract
Fourier series is an expansion of a periodic function in terms of an infinite sum of sines and cosines. Fourier series make use of the orthogonality relationships of the sine and cosine functions.  With appropriate weights, one cycle or period of the summation can be made to approximate an arbitrary function in that interval. 

In mathematics, the discrete-time fourier transform (DTFT) is a form of Fourier analysis that is applicable to the sequence of values. The DTFT is often used to analyze samples of a continuous function. The term discrete-time refers to the fact that the transform operates on discrete data, often samples whose interval has units of time.

In this program, we are going to use discrete fourier transform in order to generate the fourier series of the given discrete  coordinate data. 
In mathematics, the discrete Fourier Transform (DFT) converts a finite sequence of equally-spaced samples of function into a same-length sequence of equal-spaced samples of the discrete-time fourier transform(DTFT), which is a complex valued function of frequency.


The discrete-time fourier transform is an example of a fourier series. In this project, we have two methods to draw an object with epicycles. 

## First Method
First one is with Canvas Drawing in which the user is given a canvas and he/she is able to draw anything in the given canvas. When the drawing is completed, the program redraws the same path with epicycles. 

![canvas](https://user-images.githubusercontent.com/56423554/125977411-489ad9bf-2cab-4c58-ba17-e01c9dad8aab.png)
![canvas_drawing](https://user-images.githubusercontent.com/56423554/125977417-9ce30139-92f0-4f10-8731-ec36c080d315.png)

## Second Method
Second method is with binary images in which the program detects the object in the given Image(White Color represents object and Black Color represents background). Then the coordinate of the given image is extracted from the image whose path is retraced by this program with the help of Discrete Fourier Transform.

![sasuke_itachi](https://user-images.githubusercontent.com/56423554/125976641-8d230952-22cd-406f-9ab6-0cfe599f1e3c.png)

## To run Locally
To run locally, you must have installed g++ Compiler (Used Version : 9.3.0), SFML library, Python3. I have used VS Code IDE and its extension Easy C++ Project to build this project.

** Clone the repository **
```
git clone https://github.com/NirajanBekoju/Fourier-Transform-Drawing
```

** Create a virtual environment and activate it **
```
virtualenv venv
source ./venv/bin/activate
```

** Install all requirements from requirements.txt **
```
pip install -r requirements.txt
```





