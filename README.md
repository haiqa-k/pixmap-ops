# pixmap-ops

Image manipulation demos based on the PPM image format.

TODO: Add a representative image for your project here

## How to build

*Windows*

Open git bash to the directory containing this repository.

```
pixmap-ops $ mkdir build
pixmap-ops $ cd build
pixmap-ops/build $ cmake -G "Visual Studio 16 2019" ..
pixmap-ops/build $ start Pixmap-Ops.sln
```

Your solution file should contain two projects: `pixmap_art` and `pixmap_test`.
To run from the git bash command shell, 

```
pixmap-ops/build $ ../bin/Debug/pixmap_test
pixmap-ops/build $ ../bin/Debug/pixmap_art
```

*macOS*

Open terminal to the directory containing this repository.

```
pixmap-ops $ mkdir build
pixmap-ops $ cd build
pixmap-ops/build $ cmake ..
pixmap-ops/build $ make
```

To run each program from build, you would type

```
pixmap-ops/build $ ../bin/pixmap_test
pixmap-ops/build $ ../bin/pixmap_art
```

## Image operators

TODO: Document the features of your PPM image class here. Include example images.
```
Resize
```
<img width="196" alt="earth_resize" src="https://user-images.githubusercontent.com/79232961/111062153-9c1f2f80-847d-11eb-8f2a-8f100969be18.png">

```
Subimge:
```
<img width="394" alt="earth_subimage" src="https://user-images.githubusercontent.com/79232961/111062149-988ba880-847d-11eb-9e6b-db1ffa21a7cf.png">

```
Gamma Correction
```
<img width="395" alt="earth_gamma" src="https://user-images.githubusercontent.com/79232961/111062151-9aee0280-847d-11eb-96ac-2345b0dcf1e4.png">

```
Original Image:
```
<img width="697" alt="star_original" src="https://user-images.githubusercontent.com/79232961/111060881-7e9a9780-8476-11eb-8115-52d2549f9942.png">

```
Grayscale:
```
<img width="697" alt="star_grayscale" src="https://user-images.githubusercontent.com/79232961/111060827-22d00e80-8476-11eb-964b-6e6d805787b0.png">

```
Flipped:
```
<img width="698" alt="star_flip" src="https://user-images.githubusercontent.com/79232961/111060815-1350c580-8476-11eb-922a-d0341c1e414e.png">

```
Inverted Color:
```
<img width="698" alt="star-inverted" src="https://user-images.githubusercontent.com/79232961/111060856-5d39ab80-8476-11eb-8ad7-83799b15e8b8.png">

```
Swirl:
```
<img width="695" alt="star_swirl" src="https://user-images.githubusercontent.com/79232961/111060868-6dea2180-8476-11eb-8826-b75da17ebd87.png">

```
Lightest Extraction:
```
<img width="697" alt="star_lightest" src="https://user-images.githubusercontent.com/79232961/111060902-a7bb2800-8476-11eb-977c-bb0ef9856e47.png">

```
Darkest Extraction:
```
<img width="696" alt="star_darkest" src="https://user-images.githubusercontent.com/79232961/111060910-b73a7100-8476-11eb-9546-6998a77b5a59.png">

```
Channel Shift:
```
<img width="698" alt="star_channelShift" src="https://user-images.githubusercontent.com/79232961/111060891-91ad6780-8476-11eb-9900-86d33dfdba24.png">

```
Blue Shift:
```
<img width="697" alt="star_blueshift" src="https://user-images.githubusercontent.com/79232961/111060922-c4eff680-8476-11eb-940e-03cebe665aba.png">




## Results

TODO: Show artworks using your class


```
Channel shifting an image that has been flipped:
```
<img width="690" alt="star_channelShift_flip" src="https://user-images.githubusercontent.com/79232961/111060836-30859400-8476-11eb-82b5-aae7c6a5358f.png">

```
Inverting an image that has been channel shifted and flipped:
```
<img width="696" alt="star_invert_channelShift_flip" src="https://user-images.githubusercontent.com/79232961/111060848-498e4500-8476-11eb-9338-be5dbec73a5e.png">



