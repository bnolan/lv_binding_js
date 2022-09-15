# lvgljs

Write [lvgl](https://github.com/lvgl/lvgl) with JavaScript. It uses React's virtual DOM concept to manipulate lvgl UI components, providing a familiar experience to users.

在这里放一张代码图和效果图

## Table of Contents
- [Features](#Features)
- [Screenshot](#Screenshot)
- [Build](#Build)
- [Components](#Components)
- [Font-Symbol](#Font-Symbol)
- [Animation](#Animation)
- [Style](#Style)

## Features
- Support all lvgl built-in components
- Fully suport lvgl flex and grid style
- support most lvgl style，just write like html5 css
- support dynamic load image
- Fully support lvgl animation

## Screenshot
## Build
### Unix

#### use sdl simulate

Once you have installed openssl、sdl2、curl，you can run follwing script compile lvgljs with sdl simulator

```shell
make dev-x86
./dev_x86/Main ./demo/calculator/index.js
```

#### real device
- First you have to download openssl、curl source code and compile with divece arch
- Fill in CMAKE_BUILD_PLATFORM、CMAKE_C_COMPILER、CMAKE_CXX_COMPILER、CMAKE_CURL_LIB、CMAKE_CURL_INCLUDE_DIRS、CMAKE_SSL_LIB、CMAKE_CRYPTO_LIB in Makefile
- you can run follwing script compile lvgljs with device arch (default arm)
- copy executable file ./some_dir/Main and ./some_dir/lib in divece file-system, make sure file Main and dir lib in same dir

```shell
make dev-x86 or make build-x86
```

## Components
- [View](./doc/component/View.md)
- [Image](./doc/component/Image.md)
- [Button](./doc/component/Button.md)
- [Text](./doc/component/Text.md)
- [Input](./doc/component/Input.md)
- [Textarea](./doc/component/Textarea.md)
- [Switch](./doc/component/Switch.md)
- [Checkbox](./doc/component/Checkbox.md)
- [Dropdownlist](./doc/component/Dropdownlist.md)
- [ProgressBar](./doc/component/ProgressBar.md)
- [Line](./doc/component/Line.md)
- [Roller](./doc/component/Roller.md)
- [Keyboard](./doc/component/Keyboard.md)
- [Calendar](./doc/component/Calendar.md)

## Font-Symbol
[Buitin-Symbol](./doc/Symbol/symbol.md)

## Animation
[Animation](./doc/animate/animate.md)

## Style
[Layout](./doc/style/layout.md)


### Style

#### Position and Size (support absolute value、pixel values、percentage、auto)
- left
- top
- width
- height

```js
const style = {
    "width": "50%" | "100px" | 100,
    "height": "100px",
    "left": 20,
    "top": "50px",
    "width": "auto",
}
```

#### Box Model
- padding
- padding-left、padding-right、padding-top、padding-bottom
- border-width、border-color、border-side、border-radius
- outline-width、outline-color、outline-padding
  
```js
const style = {
    "padding": "20px" | "20px 20px" | "20px 20px 20px" | "20px 20px 20px 20px",
    "padding-left": "100px" | 100,
    "border-color": "yellow",
    "border-side": "left" | "right" | "top" | "bottom" | "full" | "top-right" | "top-bottom" | "top-left" | "right-bottom" | "right-left" | "bottom-left",
    "border-width": 8,
    "border-radius": 10,
    "outline-width": "50px",
    "outline-color": "green"
}
```

#### font
- font-size
- text-color
- letter-spacing
- line-spacing
- text-overflow
- text-align
- text-decoration

```js
const style = {
    "font-size": "20px",
    "text-color": "blue",
    "letter-spacing": "3px",
    "line-spacing": "15px",
    "text-overflow": "ellipsis" | "clip" | "auto" | "scroll" | "circular",
    "text-align": "auto" | "left" | "center" | "right",
    "text-decoration": "none" | "underline" | "strikethrough"
}
```  

#### flex
must use with display: "flex", flex can not mixed with left or top
- flex-direction (row | column)
- flex-wrap (wrap | nowrap | reverse)
- justify-content (flex-start | flex-end | center | space-evenly | space-around | space-between)
- align-items (flex-start | flex-end | center | space-evenly | space-around | space-between)
- align-content (flex-start | flex-end | center | space-evenly | space-around | space-between)
- flex-grow
  
```js
const style = {
    "display": "flex",
    "flex-wrap": "wrap",
    "justify-content": "center",
    "align-items": "center",
    "align-content": "center",
    "flex-grow": 1
}
```

#### grid

#### opacity
- opacity
- img-opacity
- border-opacity
- outline-opacity
- recolor-opacity
- shadow-opacity
  
```js
const style = {
    "opacity": 0.2,
    "img-opacity": 0.5,
    "border-opacity": 0.7,
    "outline-opacity": 0,
    "recolor-opacity": 1
}
```

#### display 
none | flex | grid
```js
const style = {
    "display": "none",
    "display": "grid",
    "display": "flex",
}
```

#### recolor
used with component Image
```js
const style = {
    "recolor": "green",
}
```

#### scrolling
- overflow-scrolling
- overflow
- scroll-dir
- scroll-snap-x
- scroll-snap-y
- scroll-enable-snap
```js
const style = {
    "overflow": "hidden" | "scroll" | "auto",
    "overflow-scrolling": "auto" | "touch",
    "scroll-dir": "none" | "left" | "right" | "top" | "bottom" | "horizontal" | "all",
    "scroll-snap-x": "none" | "snap_start" | "snap_end" | "snap_center",
    "scroll-snap-y": "none" | "snap_start" | "snap_end" | "snap_center",
    "scroll-enable-snap": true | false
}
```

#### spacing
set inner object row and column spacing
- row-spacing
- column-spacing

#### background
supoort local image、buildtin symbol、online image
- background-image
- background-color
- background-grad-color
- background-grad-color-dir

```js
const style = {
    "background-image": "./assets/somepic.png" | "http://some_website/somepic.png" | "audio"
    "background-color": "black",
    "background-grad-color": "green",
    "background-grad-color-dir": "none" | "vertical" | "horizontal"
}
```

#### shadow
- shadow-width
- shadow-color
- shadow-offset-x
- shadow-offset-y
- shadow-spread

```js
const style = {
    "shadow-width": "8px"
    "shadow-color": "black",
    "shadow-offset-x": "4px",
    "shadow-offset-y": "4px",
    "shadow-spread": "2px"
}
```
