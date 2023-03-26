# image-decoding-algorithms
Scripts for decoding an image. Used in my college project PixPalette.
## What did I do:
- Wrote my decoder for .jpeg (JFIF) files in baseline encoding mode.
- For the other use cases I used a library "skimage", which has much more variety of decoding algorithms.

### Install it via pip:
```python
pip install colorpalette-master
```
### Install it manually:
- Copy the folder `cpmaster` into Lib\side-packages of your python enviroment.
- Install additional packages with:
```python
pip install scikit-image==0.19.3
```
```python
pip install numpy==1.21.6
```
```python
pip install pillow==9.4.0
```
### After, import it into the script using `import cpmaster`.

## Compiling requirements:
- Scikit-image (version '0.19.3' or newer)
- Numpy (version '1.21.6' or newer)
- Pillow (version '9.4.0' or newer)

## Running requirements:
- Python 3.7.7 or newer (code actually uses some deprecated syntax in newer versions of Python, so not sure about the last part)

## Using the package:
- Check the `___main___.py` file for my brief documentation on methods
- Write me an email, if there are any questions left - superavb222@gmail.com
